/*
 * File: MPU6050.h
 *
 * Code generated for Simulink model :MPU6050.
 *
 * Model version      : 1.1
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Wed Dec 15 21:19:10 2021
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

#ifndef RTW_HEADER_MPU6050_h_
#define RTW_HEADER_MPU6050_h_
#include "STM32_Config.h"
#include "MPU6050_External_Functions.h"
#ifndef MPU6050_COMMON_INCLUDES_
#define MPU6050_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* MPU6050_COMMON_INCLUDES_ */

#include "MPU6050_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_MPU6050 {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void MPU6050_initialize(void);
extern void MPU6050_step(void);

/* Real-time Model object */
extern RT_MODEL_MPU6050 *const MPU6050_M;

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
 * '<Root>' : 'MPU6050'
 */
#endif                                 /* RTW_HEADER_MPU6050_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] MPU6050.h
 */
