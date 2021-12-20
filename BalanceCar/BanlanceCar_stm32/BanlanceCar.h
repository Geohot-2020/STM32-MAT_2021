/*
 * File: BanlanceCar.h
 *
 * Code generated for Simulink model :BanlanceCar.
 *
 * Model version      : 1.14
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Mon Dec 20 20:05:54 2021
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

#ifndef RTW_HEADER_BanlanceCar_h_
#define RTW_HEADER_BanlanceCar_h_
#include "BanlanceCar_USART.h"
#include "STM32_Config.h"
#include "BanlanceCar_External_Functions.h"
#include "BanlanceCar_TIM.h"
#ifndef BanlanceCar_COMMON_INCLUDES_
#define BanlanceCar_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BanlanceCar_COMMON_INCLUDES_ */

#include "BanlanceCar_types.h"

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
  real_T REG_Access2;                  /* '<S1>/REG_Access2' */
  uint32_T Buff;                       /* '<S1>/MATLAB Function' */
  uint16_T USART_Send;                 /* '<S1>/USART_Send' */
  uint16_T NbChar;                     /* '<S1>/MATLAB Function' */
  int16_T DataStoreRead1;              /* '<Root>/Data Store Read1' */
} B_BanlanceCar;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T motob;                        /* '<Root>/Data Store Memory1' */
  real_T acc_yaw;                      /* '<Root>/Data Store Memory10' */
  real_T yaw;                          /* '<Root>/Data Store Memory11' */
  real_T Accel_Z;                      /* '<Root>/Data Store Memory12' */
  real_T Gyro_Z;                       /* '<Root>/Data Store Memory13' */
  real_T Temputure;                    /* '<Root>/Data Store Memory14' */
  real_T BLTarget;                     /* '<Root>/Data Store Memory15' */
  real_T Angle;                        /* '<Root>/Data Store Memory17' */
  real_T EncoderB;                     /* '<Root>/Data Store Memory19' */
  real_T acc_pitch;                    /* '<Root>/Data Store Memory2' */
  real_T Tar_V;                        /* '<Root>/Data Store Memory20' */
  real_T Ang_moto;                     /* '<Root>/Data Store Memory21' */
  real_T Encoder_bias;                 /* '<Root>/Data Store Memory22' */
  real_T Vel_moto;                     /* '<Root>/Data Store Memory23' */
  real_T Turn_moto;                    /* '<Root>/Data Store Memory24' */
  real_T Tar_turn;                     /* '<Root>/Data Store Memory25' */
  real_T MotorA;                       /* '<Root>/Data Store Memory26' */
  real_T MotorB;                       /* '<Root>/Data Store Memory27' */
  real_T pitch;                        /* '<Root>/Data Store Memory3' */
  real_T Accel_X;                      /* '<Root>/Data Store Memory4' */
  real_T Gyro_X;                       /* '<Root>/Data Store Memory5' */
  real_T acc_roll;                     /* '<Root>/Data Store Memory6' */
  real_T roll;                         /* '<Root>/Data Store Memory7' */
  real_T Accel_Y;                      /* '<Root>/Data Store Memory8' */
  real_T Gyro_Y;                       /* '<Root>/Data Store Memory9' */
} DW_BanlanceCar;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Saturation;             /* '<Root>/Saturation' */
  const real_T Gain;                   /* '<Root>/Gain' */
  const int16_T DataTypeConversion;    /* '<Root>/Data Type Conversion' */
} ConstB_BanlanceCar;

/* Real-time Model Data Structure */
struct tag_RTM_BanlanceCar {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_BanlanceCar BanlanceCar_B;

/* Block states (default storage) */
extern DW_BanlanceCar BanlanceCar_DW;
extern const ConstB_BanlanceCar BanlanceCar_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void BanlanceCar_initialize(void);
extern void BanlanceCar_step(void);

/* Real-time Model object */
extern RT_MODEL_BanlanceCar *const BanlanceCar_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S1>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'BanlanceCar'
 * '<S1>'   : 'BanlanceCar/Function-Call Subsystem1'
 * '<S2>'   : 'BanlanceCar/Function-Call Subsystem1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_BanlanceCar_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BanlanceCar.h
 */
