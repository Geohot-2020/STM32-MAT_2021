/*
 * File: MOTOR.c
 *
 * Code generated for Simulink model :MOTOR.
 *
 * Model version      : 1.5
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Thu Dec 16 14:50:49 2021
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

#include "MOTOR.h"
#include "MOTOR_private.h"

/* Block signals (default storage) */
B_MOTOR MOTOR_B;

/* Block states (default storage) */
DW_MOTOR MOTOR_DW;

/* Real-time model */
static RT_MODEL_MOTOR MOTOR_M_;
RT_MODEL_MOTOR *const MOTOR_M = &MOTOR_M_;

/* Model step function */
void MOTOR_step(void)
{
  /* S-Function (USART_Receive): '<Root>/USART_Receive' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    if (USART1_RxConf.rxStatus == SERIAL_RX_OFF) {
      USART1_RxConf.pRX_R = USART1_RxConf.pRX_BuffStart;
      MOTOR_B.USART_Receive_o1 = 0;
      USART1_RxConf.rxStatus = SERIAL_RX_ON;

      /* USART1 interrupt receive mode. */
      HAL_UART_Receive_IT(&huart1, USART1_RxConf.pRX_BuffStart, ((uint16_T)10U));
    }

    /* Some data are available, copy them on output of Simulink block. */
    if (USART1_RxConf.rxStatus == SERIAL_RX_OK) {
      uint16_T idx;
      MOTOR_B.USART_Receive_o1 = ((uint16_T)10U);
      MOTOR_B.USART_Receive_o2 = (uint32_T)USART1_RxConf.pRX_R;
      for (idx = 0; idx < ((uint16_T)10U); idx++) {
        *(char*)(&MOTOR_B.USART_Receive_o3[0]+idx) = *(char*)USART1_RxConf.pRX_R
          ++;
      }

      *USART1_RxConf.pRX_R = 0;
      USART1_RxConf.rxStatus = SERIAL_RX_OFF;
    }
  }

  /* S-Function (USART_Send): '<Root>/USART_Send' */
  {
    if (MOTOR_B.USART_Receive_o1 != 0) {
      /* Copy data to send. */
      TX_CopyData(&USART1_TxConf, (uint8_t*)MOTOR_B.USART_Receive_o2, (uint16_t)
                  MOTOR_B.USART_Receive_o1);
    }

    if (USART1_TxConf.nb2Send) {
      MOTOR_B.USART_Send = 0;
      USART1_TX_SendData(&USART1_TxConf);
    }

    if (USART1_TxConf.txStatus != SERIAL_TX_ON) {
      MOTOR_B.USART_Send = USART1_TxConf.nbSent;
    }
  }

  /* Update for S-Function (TIMERS_Config): '<Root>/Timers' */
  {
  }
}

/* Model initialize function */
void MOTOR_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM2 initialization. */
      /* Store TIM2 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM2_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim2;

      /* Store TIM information. */
      TIM2_Conf.TIM_Prescaler = 71;
      TIM2_Conf.TIM_APBClock = 72000000;
      TIM2_Conf.TIM_ARR = 1000 - 1;
      TIM2_Conf.TIM_Clock = 1.0E+6;
      TIM2_Conf.TIM_Freq = 1000.0;
      TIM2_Conf.CH1_duty = 0.0;
      TIM2_Conf.CH2_duty = 0.0;
      TIM2_Conf.CH3_duty = 50.0;
      TIM2_Conf.CH4_duty = 0.0;
      TIM2_Conf.CH1_type = UNKNOWN;
      TIM2_Conf.CH2_type = UNKNOWN;
      TIM2_Conf.CH3_type = OUTPUT_PWM;
      TIM2_Conf.CH4_type = UNKNOWN;

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
      __HAL_TIM_SET_AUTORELOAD(&htim2,1000 - 1);

      /* Set CH3 Pulse value. */
      __HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,(uint32_t)(500));

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim2,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */

    /* USART1 initialization for receive. */
    USART1_Rx_Initialization();

    /* USART1 initialization for send. */
    USART1_Tx_Initialization();

    {
      /* TIM2 Start. */

      /* Wait for htim2 State READY. */
      while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
      }

      HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
    }

    {
      /* External interrupt function registering. */
      EXTI_Callback[4] = EXTI4_Callback;
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] MOTOR.c
 */
