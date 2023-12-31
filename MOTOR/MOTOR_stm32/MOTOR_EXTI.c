/*
 * File: MOTOR_EXTI.c
 *
 * Code generated for Simulink model :MOTOR.
 *
 * Model version      : 1.3
 * Simulink Coder version    : 9.6 (R2021b) 14-May-2021
 * TLC version       : 9.6 (Aug 25 2021)
 * C/C++ source code generated on  : Thu Dec 16 11:53:42 2021
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
#include "MOTOR_EXTI.h"

/* Exti function pointer array */
void (*EXTI_Callback[16])(void) = { NULL, NULL, NULL, NULL, NULL, NULL, NULL,
  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

/**
 * @brief  EXTI line detection callbacks.
 * @param  GPIO_Pin Specifies the pins connected EXTI line
 * @retval None
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  uint16_t pinNum = 0;
  switch (GPIO_Pin) {
   case GPIO_PIN_1 :
    pinNum = 1;
    break;

   case GPIO_PIN_2 :
    pinNum = 2;
    break;

   case GPIO_PIN_3 :
    pinNum = 3;
    break;

   case GPIO_PIN_4 :
    pinNum = 4;
    break;

   case GPIO_PIN_5 :
    pinNum = 5;
    break;

   case GPIO_PIN_6 :
    pinNum = 6;
    break;

   case GPIO_PIN_7 :
    pinNum = 7;
    break;

   case GPIO_PIN_8 :
    pinNum = 8;
    break;

   case GPIO_PIN_9 :
    pinNum = 9;
    break;

   case GPIO_PIN_10 :
    pinNum = 10;
    break;

   case GPIO_PIN_11 :
    pinNum = 11;
    break;

   case GPIO_PIN_12 :
    pinNum = 12;
    break;

   case GPIO_PIN_13 :
    pinNum = 13;
    break;

   case GPIO_PIN_14 :
    pinNum = 14;
    break;

   case GPIO_PIN_15 :
    pinNum = 15;
    break;

   default:
    pinNum = 0;
    break;
  }

  if (EXTI_Callback[pinNum] != NULL) {
    (*EXTI_Callback[pinNum])();
  }
}

/*******************************************************************************
 * Function Name  : EXTI4_Callback
 * Description    : Callback for External Interrupt connected to Pin4
 * Input          : -
 *******************************************************************************/
void EXTI4_Callback()
{
  {
    /* S-Function (GPIO_Exti): '<Root>/GPIO_Exti' */

    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */

    /* S-Function (GPIO_Write): '<S1>/GPIO_Write' */
    {
      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
    }

    /* End of Outputs for S-Function (GPIO_Exti): '<Root>/GPIO_Exti' */
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] MOTOR_EXTI.c
 */
