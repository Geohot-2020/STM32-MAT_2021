/*
 * File: BanlanceCar_TIM.c
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
#include "BanlanceCar_TIM.h"

/* Number of configured TIMER. */
uint16_t G_TIM_Count = 0;

/* Array of TIMER information. */
TIM_ConfTypeDef* G_TIM_Conf[5];
TIM_HandleTypeDef* G_TIM_Handler[5];

/* TIM2 informations. */
TIM_ConfTypeDef TIM2_Conf;

/* TIM9 informations. */
TIM_ConfTypeDef TIM9_Conf;

/*******************************************************************************
 * Function Name  : TIM_PeriodElapsedCustomCallback
 * Description    : Timer callback for update event
 * Input          : TIM_HandleTypeDef*   TIM IC handle
 *******************************************************************************/
void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim)
{
  TIM_ConfTypeDef * pConf = G_TIM_Conf[0];
  TIM_HandleTypeDef* pHandler = G_TIM_Handler[0];

  {
    uint16_t idx = 0;
    for (idx = 0;idx < 5;idx++) {
      pHandler = G_TIM_Handler[idx];
      if (pHandler == htim) {
        pConf = G_TIM_Conf[idx];
        break;
      }
    }
  }

  if (pHandler == htim) {
    if (pConf->ItUpFcn != NULL) {
      /* Call update function for TIM9. */
      pConf->ItUpFcn();
    }
  }
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  extern void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim);

  /* Handle this event from model side. */
  TIM_PeriodElapsedCustomCallback(htim);
}

/*******************************************************************************
 * Function Name  : TIM9_ItUpFcn
 * Description    : TIM9 update interrupt
 * Input          : None
 * TIM9_ItUpFcn is called from TIM_PeriodElapsedCustomCallback function
 * in BanlanceCar_TIM.c file.
 *******************************************************************************/
void TIM9_ItUpFcn()
{
  {
    /* S-Function (TIMERS_Config): '<Root>/Timers' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
    {
      char_T string[31];
      static const char_T b[26] = "u1= %7.0f,u2= %7.1f r/s\r\n";
      real_T rtb_Switch_idx_0;
      real_T rtb_Switch_idx_1;

      /* S-Function (REG_Access): '<S1>/REG_Access2' */
      {
        BanlanceCar_B.REG_Access2 = TIM1->CNT;
      }

      /* Switch: '<S1>/Switch' incorporates:
       *  Constant: '<S1>/Constant'
       *  DataStoreWrite: '<S1>/Data Store Write'
       *  Gain: '<S1>/Gain'
       *  Gain: '<S1>/Gain1'
       *  Sum: '<S1>/Add'
       */
      if (BanlanceCar_B.REG_Access2 > 10000.0) {
        rtb_Switch_idx_0 = 65535.0 - BanlanceCar_B.REG_Access2;
        rtb_Switch_idx_1 = (65535.0 - BanlanceCar_B.REG_Access2) *
          0.0025641025641025641;
      } else {
        rtb_Switch_idx_0 = BanlanceCar_B.REG_Access2;
        rtb_Switch_idx_1 = 0.0025641025641025641 * BanlanceCar_B.REG_Access2;
      }

      /* End of Switch: '<S1>/Switch' */

      /* MATLAB Function: '<S1>/MATLAB Function' */
      /* MATLAB Function 'Function-Call Subsystem1/MATLAB Function': '<S2>:1' */
      /* '<S2>:1:2' if coder.target('Sfun') */
      /* '<S2>:1:6' else */
      /* '<S2>:1:7' Buff = uint32(0); */
      /* '<S2>:1:8' string = char(zeros(1,31)); */
      /* '<S2>:1:9' stringSize = uint16(size(string,2)); */
      /* '<S2>:1:10' stringFormat = char(['u1= %7.0f,u2= %7.1f r/s',13,10,0]); */
      /* '<S2>:1:11' coder.ceval('snprintf',coder.wref(string),stringSize,coder.rref(stringFormat),u1,u2); */
      snprintf(&string[0], 31, &b[0], rtb_Switch_idx_0, rtb_Switch_idx_1);

      /* '<S2>:1:12' Buff = coder.ceval('getBuffPtr',coder.rref(string)); */
      BanlanceCar_B.Buff = getBuffPtr(&string[0]);

      /* '<S2>:1:13' NbChar = stringSize; */
      BanlanceCar_B.NbChar = 31U;

      /* S-Function (USART_Send): '<S1>/USART_Send' */
      {
        if (BanlanceCar_B.NbChar != 0) {
          /* Copy data to send. */
          TX_CopyData(&USART1_TxConf, (uint8_t*)BanlanceCar_B.Buff, (uint16_t)
                      BanlanceCar_B.NbChar);
        }

        if (USART1_TxConf.nb2Send) {
          BanlanceCar_B.USART_Send = 0;
          USART1_TX_SendData(&USART1_TxConf);
        }

        if (USART1_TxConf.txStatus != SERIAL_TX_ON) {
          BanlanceCar_B.USART_Send = USART1_TxConf.nbSent;
        }
      }

      /* S-Function (REG_Access): '<S1>/REG_Access' */
      {
        TIM1->CNT = 0;
      }
    }

    /* End of Outputs for S-Function (TIMERS_Config): '<Root>/Timers' */
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BanlanceCar_TIM.c
 */
