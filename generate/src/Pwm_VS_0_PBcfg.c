/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Emios Flexio FlexPwm eTpu
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 5.0.0
*   Build Version        : S32K3_RTD_5_0_0_HF01_D2505_ASR_REL_4_7_REV_0000_20250507
*
*   Copyright 2020 - 2025 NXP
*
*   NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file       Pwm_VS_0_PBcfg.c
*
*   @addtogroup pwm_driver Pwm Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Pwm.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_VS_0_PB_CFG_VENDOR_ID_C                       43
#define PWM_VS_0_PB_CFG_MODULE_ID_C                       121
#define PWM_VS_0_PB_CFG_AR_RELEASE_MAJOR_VERSION_C        4
#define PWM_VS_0_PB_CFG_AR_RELEASE_MINOR_VERSION_C        7
#define PWM_VS_0_PB_CFG_AR_RELEASE_REVISION_VERSION_C     0
#define PWM_VS_0_PB_CFG_SW_MAJOR_VERSION_C                5
#define PWM_VS_0_PB_CFG_SW_MINOR_VERSION_C                0
#define PWM_VS_0_PB_CFG_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((PWM_VS_0_PB_CFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_VS_0_PB_CFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Pwm_VS_0_PBcfg.c and Std_Types.h are different."
    #endif
#endif

#if (PWM_VS_0_PB_CFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm_VS_0_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM_VS_0_PB_CFG_AR_RELEASE_MAJOR_VERSION_C    != PWM_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_VS_0_PB_CFG_AR_RELEASE_MINOR_VERSION_C    != PWM_AR_RELEASE_MINOR_VERSION) || \
     (PWM_VS_0_PB_CFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_VS_0_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM_VS_0_PB_CFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
     (PWM_VS_0_PB_CFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION) || \
     (PWM_VS_0_PB_CFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_VS_0_PBcfg.c and Pwm.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"


#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/*============================== Channels configuration ===================================*/
/**
* @brief        Array of configured PWM channels
*
*/
const Pwm_ChannelConfigType Pwm_Channels_VS_0_PB[PWM_VS_0_PB_CFG_CHANNELS_COUNT] =
{
    /* PwmChannel_0 */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)0U,
        /** @brief  Channel class */
        PWM_FIXED_PERIOD,
        /** @brief  Ip channel configuration */
        {
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_EMIOS,
            /** @brief  Pointer to the Emios ip Configuration */
            (const void *)(&Emios_Pwm_Ip_VS_0_I1_Ch12),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
        #if (defined(PWM_ETPU_USED) && (PWM_ETPU_USED == STD_ON))
            /** @brief  Pointer to the Etpu_Pwm ip channel instance structure */
            NULL_PTR,
            /** @brief  Pointer to the Etpu_Pwm ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)EMIOS_PWM_IP_VS_0_I1_CH12_CFG,
            /** @brief The duty cycle of this channel */
            16384U
        },
        /** @brief  The state of the channel output in idle mode */
        PWM_LOW,
        NULL_PTR
    },
    /* PwmChannel_1 */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)1U,
        /** @brief  Channel class */
        PWM_FIXED_PERIOD,
        /** @brief  Ip channel configuration */
        {
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_EMIOS,
            /** @brief  Pointer to the Emios ip Configuration */
            (const void *)(&Emios_Pwm_Ip_VS_0_I1_Ch13),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
        #if (defined(PWM_ETPU_USED) && (PWM_ETPU_USED == STD_ON))
            /** @brief  Pointer to the Etpu_Pwm ip channel instance structure */
            NULL_PTR,
            /** @brief  Pointer to the Etpu_Pwm ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)EMIOS_PWM_IP_VS_0_I1_CH13_CFG,
            /** @brief The duty cycle of this channel */
            16384U
        },
        /** @brief  The state of the channel output in idle mode */
        PWM_LOW,
        NULL_PTR
    },
    /* PwmChannel_2 */
    {
        /** @brief  Channel Id */
        (Pwm_ChannelType)2U,
        /** @brief  Channel class */
        PWM_FIXED_PERIOD,
        /** @brief  Ip channel configuration */
        {
            /** @brief  Hardware Channel Type */
            PWM_CHANNEL_EMIOS,
            /** @brief  Pointer to the Emios ip Configuration */
            (const void *)(&Emios_Pwm_Ip_VS_0_I1_Ch14),
        #if (defined(PWM_FLEXIO_USED) && (PWM_FLEXIO_USED == STD_ON))
            /** @brief  Pointer to the Flexio ip channel configuration structure */
            NULL_PTR,
            /** @brief  Alternate Clock for flexio channel */
            FLEXIO_PWM_IP_CLK_DIV_1,
        #endif
        #if (PWM_FLEXPWM_USED == STD_ON)
            /** @brief  Pointer to the FlexPwm ip channel configuration structure */
            NULL_PTR,
            /** @brief SubModule id for this channel */
            0U,
        #endif
        #if (defined(PWM_ETPU_USED) && (PWM_ETPU_USED == STD_ON))
            /** @brief  Pointer to the Etpu_Pwm ip channel instance structure */
            NULL_PTR,
            /** @brief  Pointer to the Etpu_Pwm ip channel configuration structure */
            NULL_PTR,
        #endif
        #if (defined(PWM_ETIMER_USED) && (PWM_ETIMER_USED == STD_ON))
            /** @brief  Pointer to the Etimer ip channel configuration structure */
            NULL_PTR,
        #endif
            /** @brief  Hardware Channel Instance ID */
            (Pwm_IpwInstanceType)EMIOS_PWM_IP_VS_0_I1_CH14_CFG,
            /** @brief The duty cycle of this channel */
            16384U
        },
        /** @brief  The state of the channel output in idle mode */
        PWM_LOW,
        NULL_PTR
    }
};


/*============================== High level configuration ===================================*/
const Pwm_ConfigType Pwm_Config_VS_0 =
{
    /** @brief  Number of configured PWM channels */
    (Pwm_ChannelType)PWM_VS_0_PB_CFG_CHANNELS_COUNT,
    /** @brief  Pointer to array of PWM channels */
    &Pwm_Channels_VS_0_PB,
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    /** @brief  Hardware to logic channel map. Array containing a number of elements
                equal to total number of available channels on all IP. */
    {
        /*---------------------eMIOS_0---------------------------*/
        (Pwm_ChannelType)255,            /* Emios_0_0 unused */
        (Pwm_ChannelType)255,            /* Emios_0_1 unused */
        (Pwm_ChannelType)255,            /* Emios_0_2 unused */
        (Pwm_ChannelType)255,            /* Emios_0_3 unused */
        (Pwm_ChannelType)255,            /* Emios_0_4 unused */
        (Pwm_ChannelType)255,            /* Emios_0_5 unused */
        (Pwm_ChannelType)255,            /* Emios_0_6 unused */
        (Pwm_ChannelType)255,            /* Emios_0_7 unused */
        (Pwm_ChannelType)255,            /* Emios_0_8 unused */
        (Pwm_ChannelType)255,            /* Emios_0_9 unused */
        (Pwm_ChannelType)255,            /* Emios_0_10 unused */
        (Pwm_ChannelType)255,            /* Emios_0_11 unused */
        (Pwm_ChannelType)255,            /* Emios_0_12 unused */
        (Pwm_ChannelType)255,            /* Emios_0_13 unused */
        (Pwm_ChannelType)255,            /* Emios_0_14 unused */
        (Pwm_ChannelType)255,            /* Emios_0_15 unused */
        (Pwm_ChannelType)255,            /* Emios_0_16 unused */
        (Pwm_ChannelType)255,            /* Emios_0_17 unused */
        (Pwm_ChannelType)255,            /* Emios_0_18 unused */
        (Pwm_ChannelType)255,            /* Emios_0_19 unused */
        (Pwm_ChannelType)255,            /* Emios_0_20 unused */
        (Pwm_ChannelType)255,            /* Emios_0_21 unused */
        (Pwm_ChannelType)255,            /* Emios_0_22 unused */
        (Pwm_ChannelType)255,            /* Emios_0_23 unused */
        /*---------------------eMIOS_1---------------------------*/
        (Pwm_ChannelType)255,            /* Emios_1_0 unused */
        (Pwm_ChannelType)255,            /* Emios_1_1 unused */
        (Pwm_ChannelType)255,            /* Emios_1_2 unused */
        (Pwm_ChannelType)255,            /* Emios_1_3 unused */
        (Pwm_ChannelType)255,            /* Emios_1_4 unused */
        (Pwm_ChannelType)255,            /* Emios_1_5 unused */
        (Pwm_ChannelType)255,            /* Emios_1_6 unused */
        (Pwm_ChannelType)255,            /* Emios_1_7 unused */
        (Pwm_ChannelType)255,            /* Emios_1_8 unused */
        (Pwm_ChannelType)255,            /* Emios_1_9 unused */
        (Pwm_ChannelType)255,            /* Emios_1_10 unused */
        (Pwm_ChannelType)255,            /* Emios_1_11 unused */
        (Pwm_ChannelType)0,            /* Emios_1_12 */
        (Pwm_ChannelType)1,            /* Emios_1_13 */
        (Pwm_ChannelType)2,            /* Emios_1_14 */
        (Pwm_ChannelType)255,            /* Emios_1_15 unused */
        (Pwm_ChannelType)255,            /* Emios_1_16 unused */
        (Pwm_ChannelType)255,            /* Emios_1_17 unused */
        (Pwm_ChannelType)255,            /* Emios_1_18 unused */
        (Pwm_ChannelType)255,            /* Emios_1_19 unused */
        (Pwm_ChannelType)255,            /* Emios_1_20 unused */
        (Pwm_ChannelType)255,            /* Emios_1_21 unused */
        (Pwm_ChannelType)255,            /* Emios_1_22 unused */
        (Pwm_ChannelType)255,            /* Emios_1_23 unused */
        /*---------------------eMIOS_2---------------------------*/
        (Pwm_ChannelType)255,            /* Emios_2_0 unused */
        (Pwm_ChannelType)255,            /* Emios_2_1 unused */
        (Pwm_ChannelType)255,            /* Emios_2_2 unused */
        (Pwm_ChannelType)255,            /* Emios_2_3 unused */
        (Pwm_ChannelType)255,            /* Emios_2_4 unused */
        (Pwm_ChannelType)255,            /* Emios_2_5 unused */
        (Pwm_ChannelType)255,            /* Emios_2_6 unused */
        (Pwm_ChannelType)255,            /* Emios_2_7 unused */
        (Pwm_ChannelType)255,            /* Emios_2_8 unused */
        (Pwm_ChannelType)255,            /* Emios_2_9 unused */
        (Pwm_ChannelType)255,            /* Emios_2_10 unused */
        (Pwm_ChannelType)255,            /* Emios_2_11 unused */
        (Pwm_ChannelType)255,            /* Emios_2_12 unused */
        (Pwm_ChannelType)255,            /* Emios_2_13 unused */
        (Pwm_ChannelType)255,            /* Emios_2_14 unused */
        (Pwm_ChannelType)255,            /* Emios_2_15 unused */
        (Pwm_ChannelType)255,            /* Emios_2_16 unused */
        (Pwm_ChannelType)255,            /* Emios_2_17 unused */
        (Pwm_ChannelType)255,            /* Emios_2_18 unused */
        (Pwm_ChannelType)255,            /* Emios_2_19 unused */
        (Pwm_ChannelType)255,            /* Emios_2_20 unused */
        (Pwm_ChannelType)255,            /* Emios_2_21 unused */
        (Pwm_ChannelType)255,            /* Emios_2_22 unused */
        (Pwm_ChannelType)255,            /* Emios_2_23 unused */
        /*---------------------Flexio_0---------------------------*/
        (Pwm_ChannelType)255,            /* Flexio_0_0 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_1 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_2 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_3 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_4 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_5 unused */
        (Pwm_ChannelType)255,            /* Flexio_0_6 unused */
        (Pwm_ChannelType)255            /* Flexio_0_7 unused */
    }
#endif
};

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
