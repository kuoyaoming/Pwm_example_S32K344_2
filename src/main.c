/*==================================================================================================
*   版權所有 2020 - 2024 NXP
*
*   NXP 機密專有軟體。此軟體歸 NXP 所有或控制，只能嚴格按照
*   適用的授權條款使用。透過明確接受這些條款或透過下載、安裝、
*   啟動和/或以其他方式使用軟體，您同意您已閱讀並同意遵守
*   並受這些授權條款約束。如果您不同意受適用授權條款約束，
*   則不得保留、安裝、啟動或以其他方式使用軟體。
*
*   此檔案僅包含範例程式碼。它不是生產程式碼交付物的一部分。
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        包含檔案
* 1) 系統和專案包含檔案
* 2) 外部單元所需介面
* 3) 此單元內部和外部介面
==================================================================================================*/

#include "Pwm.h"
#include "Mcu.h"
#include "Port.h"
#include "Mcl.h"

/*==================================================================================================
*                          本地型別定義 (結構、聯合、列舉)
==================================================================================================*/

/* RGB color structure */
typedef struct {
    uint16 r;  /* Red component (0-PWM_PERIOD) */
    uint16 g;  /* Green component (0-PWM_PERIOD) */
    uint16 b;  /* Blue component (0-PWM_PERIOD) */
} RgbColor_t;

/* HSV color structure */
typedef struct {
    uint16 h;  /* Hue (0-359 degrees) */
    uint8 s;   /* Saturation (0-255) */
    uint8 v;   /* Value/Brightness (0-255) */
} HsvColor_t;

/* RGB LED control structure */
typedef struct {
    uint16 hue_step;         /* Current hue step (0-359) */
    uint8 hue_speed;         /* Hue change speed (1-8) */
    uint8 hue_counter;       /* Hue update counter */
    uint8 brightness_level;  /* Fixed brightness level (0-255) */
} RgbLedState_t;

/*==================================================================================================
*                                       Local macro definitions
==================================================================================================*/
#define HUE_STEPS         (360U)      /* Hue steps for full color wheel */
#define BASE_DELAY        (15000U)    /* Base delay time (faster color transitions) */
#define MIN_HUE_SPEED     (1U)        /* Minimum hue change speed */
#define MAX_HUE_SPEED     (5U)        /* Maximum hue change speed */
#define PWM_PERIOD        (0x8000U)   /* PWM counter period (32768) - Standard PWM range */
#define MAX_DUTY          (0x8000U)   /* Maximum duty cycle for 100% */
#define SAFE_MAX_DUTY     (0x7FFFU)   /* Safe maximum (32767) prevents overflow */
#define UPDATE_RATE_HZ    (66U)       /* Update frequency 66Hz for smooth transitions */
#define CPU_FREQ_MHZ      (48U)       /* CPU core frequency 48MHz */

/* Fixed brightness settings for color showcase */
#define BRIGHTNESS_LEVEL  (220U)      /* Fixed brightness level (86% for vivid colors) */
#define SATURATION_LEVEL  (255U)      /* Maximum saturation for pure colors */

/* Cree CLP6C-FKB RGB LED color calibration factors */
#define RED_SCALE_FACTOR    (100U)    /* Red channel scaling (100%) */
#define GREEN_SCALE_FACTOR  (85U)     /* Green channel scaling (85% - brightest) */
#define BLUE_SCALE_FACTOR   (110U)    /* Blue channel scaling (110% - dimmest) */
/*==================================================================================================
*                                      Local constants
==================================================================================================*/



/*==================================================================================================
*                                      Local variables
==================================================================================================*/
static RgbLedState_t rgb_state;         /* RGB LED state */
static uint32 rng_seed = 0x12345678U;   /* Random number seed */

/*==================================================================================================
*                                      全域常數
==================================================================================================*/

/*==================================================================================================
*                                      全域變數
==================================================================================================*/

/*==================================================================================================
*                                   Local function prototypes
==================================================================================================*/
static void PrecisionDelay(uint32 microseconds);
static void WaitColorTransition(void);
static uint8 GetRandomHueSpeed(void);
static RgbColor_t HsvToRgb(HsvColor_t hsv);
static void UpdateRgbLed(uint32 cycle);
/*==================================================================================================
*                                       Local functions
==================================================================================================*/

/**
* @brief        High precision delay function
* @details      Precise delay calculation based on actual CPU clock frequency
*/
static void PrecisionDelay(uint32 microseconds)
{
    /* Based on Clock_Ip configuration: CORE_CLK = 48MHz, ~8 clock cycles per loop */
    volatile uint32 cycles = (microseconds * CPU_FREQ_MHZ) / 8U;
    while(cycles--);
}

/**
* @brief        66Hz color transition timer
* @details      Precise 15ms interval (based on 48MHz CPU frequency, optimal for smooth color changes)
*/
static void WaitColorTransition(void)
{
    PrecisionDelay(BASE_DELAY);  /* 15ms = 1/66 second for smooth color transitions */
}

/**
* @brief        Generate random hue speed
* @details      Optimized pseudo-random number generator for hue changes
*/
static uint8 GetRandomHueSpeed(void)
{
    rng_seed = (rng_seed << 1) ^ (rng_seed >> 30) ^ 0x6C078965U;
    return MIN_HUE_SPEED + (rng_seed % (MAX_HUE_SPEED - MIN_HUE_SPEED + 1));
}

/**
* @brief        HSV to RGB color space conversion with Cree LED calibration
* @details      High precision conversion algorithm with overflow protection and LED optimization
*/
static RgbColor_t HsvToRgb(HsvColor_t hsv)
{
    RgbColor_t rgb = {0, 0, 0};
    uint16 region, remainder, p, q, t;
    uint32 temp_r, temp_g, temp_b;
    
    if (hsv.s == 0) {
        /* Grayscale */
        uint32 gray_value = (uint32)hsv.v * PWM_PERIOD / 255U;
        if (gray_value > SAFE_MAX_DUTY) gray_value = SAFE_MAX_DUTY;
        rgb.r = rgb.g = rgb.b = (uint16)gray_value;
        return rgb;
    }
    
    region = hsv.h / 60U;
    remainder = (hsv.h % 60U) * 255U / 60U;
    
    p = (uint16)((uint32)hsv.v * (255U - hsv.s) / 255U);
    q = (uint16)((uint32)hsv.v * (255U - ((uint32)hsv.s * remainder / 255U)) / 255U);
    t = (uint16)((uint32)hsv.v * (255U - ((uint32)hsv.s * (255U - remainder) / 255U)) / 255U);
    
    /* Calculate RGB values based on hue region */
    switch (region) {
        case 0:
            temp_r = (uint32)hsv.v * PWM_PERIOD / 255U;
            temp_g = (uint32)t * PWM_PERIOD / 255U;
            temp_b = (uint32)p * PWM_PERIOD / 255U;
            break;
        case 1:
            temp_r = (uint32)q * PWM_PERIOD / 255U;
            temp_g = (uint32)hsv.v * PWM_PERIOD / 255U;
            temp_b = (uint32)p * PWM_PERIOD / 255U;
            break;
        case 2:
            temp_r = (uint32)p * PWM_PERIOD / 255U;
            temp_g = (uint32)hsv.v * PWM_PERIOD / 255U;
            temp_b = (uint32)t * PWM_PERIOD / 255U;
            break;
        case 3:
            temp_r = (uint32)p * PWM_PERIOD / 255U;
            temp_g = (uint32)q * PWM_PERIOD / 255U;
            temp_b = (uint32)hsv.v * PWM_PERIOD / 255U;
            break;
        case 4:
            temp_r = (uint32)t * PWM_PERIOD / 255U;
            temp_g = (uint32)p * PWM_PERIOD / 255U;
            temp_b = (uint32)hsv.v * PWM_PERIOD / 255U;
            break;
        default: /* case 5 */
            temp_r = (uint32)hsv.v * PWM_PERIOD / 255U;
            temp_g = (uint32)p * PWM_PERIOD / 255U;
            temp_b = (uint32)q * PWM_PERIOD / 255U;
            break;
    }
    
    /* Apply Cree LED calibration factors */
    temp_r = (temp_r * RED_SCALE_FACTOR) / 100U;
    temp_g = (temp_g * GREEN_SCALE_FACTOR) / 100U;
    temp_b = (temp_b * BLUE_SCALE_FACTOR) / 100U;
    
    /* Ensure values don't exceed PWM period to prevent overflow */
    if (temp_r > SAFE_MAX_DUTY) temp_r = SAFE_MAX_DUTY;
    if (temp_g > SAFE_MAX_DUTY) temp_g = SAFE_MAX_DUTY;
    if (temp_b > SAFE_MAX_DUTY) temp_b = SAFE_MAX_DUTY;
    
    rgb.r = (uint16)temp_r;
    rgb.g = (uint16)temp_g;
    rgb.b = (uint16)temp_b;
    
    return rgb;
}



/**
* @brief        Update RGB LED with smooth color transitions.
* @details      Focus on showcasing all color combinations with fixed brightness
*/
static void UpdateRgbLed(uint32 cycle)
{
    RgbLedState_t *rgb = &rgb_state;
    HsvColor_t hsv;
    RgbColor_t rgb_color;
    
    /* Update hue counter */
    rgb->hue_counter++;
    if(rgb->hue_counter >= rgb->hue_speed) {
        rgb->hue_counter = 0;
        
        /* Smooth hue progression (always forward for smooth color wheel) */
        rgb->hue_step++;
        if(rgb->hue_step >= HUE_STEPS) {
            rgb->hue_step = 0;  /* Complete color wheel cycle */
            /* Change speed for next cycle to create variation */
            rgb->hue_speed = GetRandomHueSpeed();
        }
    }
    
    /* Calculate HSV values with fixed brightness and saturation */
    hsv.h = rgb->hue_step;
    hsv.s = SATURATION_LEVEL;     /* Maximum saturation for pure colors */
    hsv.v = rgb->brightness_level; /* Fixed brightness level */
    
    /* Convert to RGB with calibration and overflow protection */
    rgb_color = HsvToRgb(hsv);
    
    /* Set PWM duty cycles with final safety check */
    uint16 safe_red = (rgb_color.r > SAFE_MAX_DUTY) ? SAFE_MAX_DUTY : rgb_color.r;
    uint16 safe_green = (rgb_color.g > SAFE_MAX_DUTY) ? SAFE_MAX_DUTY : rgb_color.g;
    uint16 safe_blue = (rgb_color.b > SAFE_MAX_DUTY) ? SAFE_MAX_DUTY : rgb_color.b;
    
    Pwm_SetDutyCycle(0, safe_red);    /* Red channel */
    Pwm_SetDutyCycle(1, safe_green);  /* Green channel */
    Pwm_SetDutyCycle(2, safe_blue);   /* Blue channel */
}

/**
* @brief        Smooth RGB color showcase
* @details      Displays all color combinations with smooth transitions
*               66Hz update rate for fluid color changes
*/
void RgbColorShowcase(void)
{
    uint32 cycle = 0U;
    
    /* Initialize RGB state */
    rgb_state.hue_step = 0;
    rgb_state.hue_speed = GetRandomHueSpeed();
    rgb_state.hue_counter = 0;
    rgb_state.brightness_level = BRIGHTNESS_LEVEL;  /* Fixed brightness for color showcase */
    
    /* Initialize all channels to off */
    Pwm_SetDutyCycle(0, 0);  /* Red channel */
    Pwm_SetDutyCycle(1, 0);  /* Green channel */
    Pwm_SetDutyCycle(2, 0);  /* Blue channel */
    
    /* Main RGB color showcase loop - smooth color transitions */
    while(1) {
        /* Update RGB LED with smooth color transitions */
        UpdateRgbLed(cycle);
        
        /* 66Hz RGB update interval (15ms) for smooth color transitions */
        WaitColorTransition();
        cycle++;
    }
}

/*==================================================================================================
*                                       全域函數
==================================================================================================*/

/**
* @brief        Example main function
* @details      Initialize required drivers and control RGB LED brightness using PWM
*               Creates smooth color transitions with breathing effect
*/
int main(void)
{
    /* Initialize MCU driver */
    Mcu_Init(&Mcu_Config_VS_0);

    /* Initialize clock tree */
    Mcu_InitClock(McuClockSettingConfig_0);

    /* Apply mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize all pins using Port driver */
    Port_Init(&Port_Config_VS_0);

    /* Initialize MCL driver */
    Mcl_Init(&Mcl_Config_VS_0);

    /* Initialize PWM driver */
    Pwm_Init(&Pwm_Config_VS_0);

    /* Set external counter bus periods */
    Mcl_Emios_SetCounterBusPeriod(MCL_EMIOS_LOGIC_CH1, 0x8000U, FALSE);  /* Red channel */
    Mcl_Emios_SetCounterBusPeriod(MCL_EMIOS_LOGIC_CH4, 0x8000U, FALSE);  /* Green channel */
    Mcl_Emios_SetCounterBusPeriod(MCL_EMIOS_LOGIC_CH3, 0x8000U, FALSE);  /* Blue channel */

    /* Execute RGB color showcase */
    RgbColorShowcase();

    /* Deinitialize PWM driver */
    Pwm_DeInit();

    return 0U;
}

#ifdef __cplusplus
}
#endif

/** @} */

