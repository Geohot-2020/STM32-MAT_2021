/*
 * File: BanlanceCar.c
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

#include "BanlanceCar.h"
#include "BanlanceCar_private.h"

/* GPIOA output mask value definition. */
uint16_t GPIOA_maskWrite;

/* Block signals (default storage) */
B_BanlanceCar BanlanceCar_B;

/* Block states (default storage) */
DW_BanlanceCar BanlanceCar_DW;

/* Real-time model */
static RT_MODEL_BanlanceCar BanlanceCar_M_;
RT_MODEL_BanlanceCar *const BanlanceCar_M = &BanlanceCar_M_;

/* Model step function */
void BanlanceCar_step(void)
{
  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  {
    /* Set GPIOA output mask value. */
    GPIOA_maskWrite = GPIOA->ODR;
    GPIOA_maskWrite &= 0xFFCF ;
    GPIOA_maskWrite |= (uint16_t)1.0 << 4;
    GPIOA_maskWrite |= (uint16_t)0.0 << 5;

    /* Write GPIOA input value */
    GPIOA->ODR = (uint16_t)GPIOA_maskWrite;
  }

  /* DataStoreRead: '<Root>/Data Store Read1' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write'
   */
  BanlanceCar_B.DataStoreRead1 = BanlanceCar_ConstB.DataTypeConversion;

  /* Update for S-Function (TIMERS_Config): '<Root>/Timers1' */
  {
    if (BanlanceCar_B.DataStoreRead1 != TIM2_Conf.CH3_duty) {
      TIM2_Conf.CH3_duty = BanlanceCar_B.DataStoreRead1;
      if (BanlanceCar_B.DataStoreRead1 >= 0) {
        /* Channel3 duty cycle is an input port. */
        __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(uint32_t)
                              (BanlanceCar_B.DataStoreRead1 * (&htim2)->
          Instance->ARR / 100));
      }
    }
  }

  /* Update for S-Function (TIMERS_Config): '<Root>/Timers' */
  {
  }

  /* End of Update for S-Function (TIMERS_Config): '<Root>/Timers' */
}

/* Model initialize function */
void BanlanceCar_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM2 initialization. */
      /* Store TIM2 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM2_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim2;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM2_Conf.TIM_Prescaler = 0;
      TIM2_Conf.TIM_APBClock = 72000000;
      TIM2_Conf.TIM_ARR = 7199 - 1;
      TIM2_Conf.TIM_Clock = 7.2E+7;
      TIM2_Conf.TIM_Freq = 10001.39;
      TIM2_Conf.CH1_duty = 0.0;
      TIM2_Conf.CH2_duty = 0.0;
      TIM2_Conf.CH3_duty = 6.93;
      TIM2_Conf.CH4_duty = 0.0;
      TIM2_Conf.CH1_type = UNKNOWN;
      TIM2_Conf.CH2_type = UNKNOWN;
      TIM2_Conf.CH3_type = OUTPUT_PWM;
      TIM2_Conf.CH4_type = OUTPUT_PWM;

      /* Interrupt handler default initialization. */
      TIM2_Conf.ItUpFcn = NULL;
      TIM2_Conf.ItTrgFcn = NULL;
      TIM2_Conf.ItComFcn = NULL;
      TIM2_Conf.ItBrkFcn = NULL;
      TIM2_Conf.ItCcFcn = NULL;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim2)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim2,TIM2_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim2,7199 - 1);

      /* Set CH3 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(uint32_t)(499));

      /* Set CH4 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,(uint32_t)((7199 - 1)/2));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim2,TIM_EVENTSOURCE_UPDATE);
    }

    {
      /* TIM9 initialization. */
      /* Store TIM9 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM9_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim9;
      G_TIM_Count++;

      /* Store TIM information. */
      TIM9_Conf.TIM_Prescaler = 7199;
      TIM9_Conf.TIM_APBClock = 72000000;
      TIM9_Conf.TIM_ARR = 10000 - 1;
      TIM9_Conf.TIM_Clock = 10000.0;
      TIM9_Conf.TIM_Freq = 1.0;
      TIM9_Conf.CH1_duty = 0.0;
      TIM9_Conf.CH2_duty = 0.0;
      TIM9_Conf.CH3_duty = 0.0;
      TIM9_Conf.CH4_duty = 0.0;
      TIM9_Conf.CH1_type = UNKNOWN;
      TIM9_Conf.CH2_type = UNKNOWN;
      TIM9_Conf.CH3_type = UNKNOWN;
      TIM9_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM9_Conf.ItUpFcn = NULL;
      TIM9_Conf.ItTrgFcn = NULL;
      TIM9_Conf.ItComFcn = NULL;
      TIM9_Conf.ItBrkFcn = NULL;
      TIM9_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM9_Conf.ItUpFcn = TIM9_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim9)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim9,TIM9_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim9,10000 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim9,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */

    /* USART1 initialization for send. */
    USART1_Tx_Initialization();

    {
      /* TIM2 Start. */

      /* Wait for htim2 State READY. */
      while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);

      /* Wait for htim2 State READY. */
      while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
    }

    {
      /* TIM9 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim9);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim9);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BanlanceCar.c
 */
