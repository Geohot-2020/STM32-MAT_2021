/*
 * File: untitled.c
 *
 * Code generated for Simulink model :untitled.
 *
 * Model version      : 1.3
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Wed Dec 15 11:09:55 2021
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

#include "untitled.h"
#include "untitled_private.h"

/* GPIOA output mask value definition. */
uint16_t GPIOA_maskWrite;

/* Block signals (default storage) */
B_untitled untitled_B;

/* Block states (default storage) */
DW_untitled untitled_DW;

/* Real-time model */
static RT_MODEL_untitled untitled_M_;
RT_MODEL_untitled *const untitled_M = &untitled_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (untitled_M->Timing.TaskCounters.TID[1])++;
  if ((untitled_M->Timing.TaskCounters.TID[1]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    untitled_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void untitled_step(void)
{
  if (untitled_M->Timing.TaskCounters.TID[1] == 0) {
    /* UnitDelay: '<S1>/Output' */
    untitled_B.Output = untitled_DW.Output_DSTATE;

    /* Switch: '<S3>/FixPt Switch' incorporates:
     *  Constant: '<S2>/FixPt Constant'
     *  Sum: '<S2>/FixPt Sum1'
     *  UnitDelay: '<S1>/Output'
     */
    untitled_DW.Output_DSTATE = (uint8_T)((uint8_T)(untitled_B.Output + 1) & 3);
  }

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  untitled_B.PulseGenerator1 = ((untitled_DW.clockTickCounter < 5000) &&
    (untitled_DW.clockTickCounter >= 0));

  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */
  if (untitled_DW.clockTickCounter >= 99999) {
    untitled_DW.clockTickCounter = 0;
  } else {
    untitled_DW.clockTickCounter++;
  }

  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' */
  {
    /* Set GPIOA output mask value. */
    GPIOA_maskWrite = GPIOA->ODR;
    GPIOA_maskWrite &= 0xFF3F ;
    GPIOA_maskWrite |= (uint16_t)untitled_B.Output << 6;
    GPIOA_maskWrite |= (uint16_t)untitled_B.PulseGenerator1 << 7;

    /* Write GPIOA input value */
    GPIOA->ODR = (uint16_t)GPIOA_maskWrite;
  }

  rate_scheduler();
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* (no initialization code required) */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] untitled.c
 */
