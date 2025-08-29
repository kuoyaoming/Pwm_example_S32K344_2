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

#ifndef EMIOS_PWM_IP_VS_0_PBCFG_H
#define EMIOS_PWM_IP_VS_0_PBCFG_H

/**
*   @file       Emios_Pwm_Ip_VS_0_PBcfg.h
*
*   @addtogroup emios_pwm_ip Emios Pwm IPL
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
#include "Emios_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define EMIOS_PWM_IP_VS_0_PB_CFG_VENDOR_ID                       43
#define EMIOS_PWM_IP_VS_0_PB_CFG_MODULE_ID                       121
#define EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_MINOR_VERSION        7
#define EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_REVISION_VERSION     0
#define EMIOS_PWM_IP_VS_0_PB_CFG_SW_MAJOR_VERSION                5
#define EMIOS_PWM_IP_VS_0_PB_CFG_SW_MINOR_VERSION                0
#define EMIOS_PWM_IP_VS_0_PB_CFG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Emios_Pwm_Ip_Types header file are of the same vendor */
#if (EMIOS_PWM_IP_VS_0_PB_CFG_VENDOR_ID != EMIOS_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Emios_Pwm_Ip_VS_0_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same AUTOSAR version */
#if ((EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_MAJOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_MINOR_VERSION    != EMIOS_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (EMIOS_PWM_IP_VS_0_PB_CFG_AR_RELEASE_REVISION_VERSION != EMIOS_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Emios_Pwm_Ip_VS_0_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Emios_Pwm_Ip_Types header file are of the same software version */
#if ((EMIOS_PWM_IP_VS_0_PB_CFG_SW_MAJOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (EMIOS_PWM_IP_VS_0_PB_CFG_SW_MINOR_VERSION != EMIOS_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (EMIOS_PWM_IP_VS_0_PB_CFG_SW_PATCH_VERSION != EMIOS_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Emios_Pwm_Ip_VS_0_PBcfg.h and Emios_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
/* Emios instance index for configuration PwmEmios_1/PwmEmiosChannels_0 */
#define EMIOS_PWM_IP_VS_0_I1_CH12_CFG      (1U)
/* Macro to enable the mode operations. */
#ifndef EMIOS_PWM_IP_MODE_OPWMB_USED
#define EMIOS_PWM_IP_MODE_OPWMB_USED
#endif

/* Emios instance index for configuration PwmEmios_1/PwmEmiosChannels_1 */
#define EMIOS_PWM_IP_VS_0_I1_CH13_CFG      (1U)
/* Macro to enable the mode operations. */
#ifndef EMIOS_PWM_IP_MODE_OPWMB_USED
#define EMIOS_PWM_IP_MODE_OPWMB_USED
#endif

/* Emios instance index for configuration PwmEmios_1/PwmEmiosChannels_2 */
#define EMIOS_PWM_IP_VS_0_I1_CH14_CFG      (1U)
/* Macro to enable the mode operations. */
#ifndef EMIOS_PWM_IP_MODE_OPWMB_USED
#define EMIOS_PWM_IP_MODE_OPWMB_USED
#endif


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifndef EMIOS_PWM_IP_PRECOMPILE_SUPPORT
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"

/* Channel configurations for Emios instance 1 */
/* Emios channel 12 configuration */
extern const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_VS_0_I1_Ch12;

/* Emios channel 13 configuration */
extern const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_VS_0_I1_Ch13;

/* Emios channel 14 configuration */
extern const Emios_Pwm_Ip_ChannelConfigType Emios_Pwm_Ip_VS_0_I1_Ch14;

#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Pwm_MemMap.h"
#endif  /* EMIOS_PWM_IP_PRECOMPILE_SUPPORT */

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* EMIOS_PWM_IP_VS_0_PBCFG_H */

