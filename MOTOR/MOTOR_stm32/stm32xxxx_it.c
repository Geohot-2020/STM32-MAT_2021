/*
 * File: stm32xxxx_it.c
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

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
  /* This section of code is going to be merged by the STM32CubeMX tool. */
  /* USER CODE BEGIN SysTick_IRQn 0 */
  {
    extern volatile uint32_t remainAutoReloadTimerLoopVal_S;

    /* Manage number of loop before interrupt has to be processed. */
    if (remainAutoReloadTimerLoopVal_S) {
      remainAutoReloadTimerLoopVal_S--;
    }
  }

  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] stm32xxxx_it.c
 */
