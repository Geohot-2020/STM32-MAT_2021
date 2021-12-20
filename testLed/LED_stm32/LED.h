/*
 * File: LED.h
 *
 * Code generated for Simulink model :LED.
 *
 * Model version      : 1.1
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Wed Dec 15 14:10:25 2021
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#ifndef RTW_HEADER_LED_h_
#define RTW_HEADER_LED_h_
#include "STM32_Config.h"
#include "LED_External_Functions.h"
#ifndef LED_COMMON_INCLUDES_
#define LED_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LED_COMMON_INCLUDES_ */

#include "LED_types.h"

/* GPIOA output mask value declaration. */
extern uint16_t GPIOA_maskWrite;

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  real_T PulseGenerator1;              /* '<Root>/Pulse Generator1' */
} B_LED;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T clockTickCounter_i;          /* '<Root>/Pulse Generator1' */
} DW_LED;

/* Real-time Model Data Structure */
struct tag_RTM_LED {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_LED LED_B;

/* Block states (default storage) */
extern DW_LED LED_DW;

/* Model entry point functions */
extern void LED_initialize(void);
extern void LED_step(void);

/* Real-time Model object */
extern RT_MODEL_LED *const LED_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LED'
 */
#endif                                 /* RTW_HEADER_LED_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED.h
 */
