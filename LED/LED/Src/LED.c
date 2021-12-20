/*
 * File: LED.c
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

#include "LED.h"
#include "LED_private.h"

/* GPIOA output mask value definition. */
uint16_t GPIOA_maskWrite;

/* Block signals (default storage) */
B_LED LED_B;

/* Block states (default storage) */
DW_LED LED_DW;

/* Real-time model */
static RT_MODEL_LED LED_M_;
RT_MODEL_LED *const LED_M = &LED_M_;

/* Model step function */
void LED_step(void)
{
  LED_B.PulseGenerator = ((LED_DW.clockTickCounter < 500) &&
    (LED_DW.clockTickCounter >= 0));
  if (LED_DW.clockTickCounter >= 999) {
    LED_DW.clockTickCounter = 0;
  } else {
    LED_DW.clockTickCounter++;
  }

  LED_B.PulseGenerator1 = ((LED_DW.clockTickCounter_i < 300) &&
    (LED_DW.clockTickCounter_i >= 0));
  if (LED_DW.clockTickCounter_i >= 999) {
    LED_DW.clockTickCounter_i = 0;
  } else {
    LED_DW.clockTickCounter_i++;
  }

  {
    /* Set GPIOA output mask value. */
    GPIOA_maskWrite = GPIOA->ODR;
    GPIOA_maskWrite &= 0xFF3F ;
    GPIOA_maskWrite |= (uint16_t)LED_B.PulseGenerator << 6;
    GPIOA_maskWrite |= (uint16_t)LED_B.PulseGenerator1 << 7;

    /* Write GPIOA input value */
    GPIOA->ODR = (uint16_t)GPIOA_maskWrite;
  }
}

/* Model initialize function */
void LED_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED.c
 */
