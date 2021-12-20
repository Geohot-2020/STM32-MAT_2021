/*
 * File: test.c
 *
 * Code generated for Simulink model :test.
 *
 * Model version      : 1.1
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Thu Dec 16 14:40:47 2021
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

#include "test.h"
#include "test_private.h"

/* Block signals (default storage) */
B_test test_B;

/* Block states (default storage) */
DW_test test_DW;

/* Real-time model */
static RT_MODEL_test test_M_;
RT_MODEL_test *const test_M = &test_M_;

/* Model step function */
void test_step(void)
{
  test_B.PulseGenerator = ((test_DW.clockTickCounter < 500) &&
    (test_DW.clockTickCounter >= 0));
  if (test_DW.clockTickCounter >= 9999) {
    test_DW.clockTickCounter = 0;
  } else {
    test_DW.clockTickCounter++;
  }

  {
    if (test_B.PulseGenerator == 0)
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
    else
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
  }
}

/* Model initialize function */
void test_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] test.c
 */
