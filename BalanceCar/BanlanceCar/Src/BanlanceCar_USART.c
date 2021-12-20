/*
 * File: BanlanceCar_USART.c
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
#include "BanlanceCar_USART.h"
#include "main.h"

/* Number of USART/UART configured for send. */
uint16_t G_SERIAL_TX_Count = 0;

/* Array of USART/UART send data information. */
SERIAL_TxConfTypeDef* G_SERIAL_TX_Conf[2];
void* G_SERIAL_TX_Handler[2];

/* USART1 ring data send buffer. */
static uint8_t USART1_TxDataBuffer[512];

/* USART1 send data structure information. */
SERIAL_TxConfTypeDef USART1_TxConf;

/*******************************************************************************
 * Function Name  : TX_CopyData
 * Description    : Copy msg to send to ring buffer (if possible)
 * Input          : pointer to data to send , length(number) of data to send and
 *                  ring buffer context
 *******************************************************************************/
void TX_CopyData(struct SERIAL_TxConf* pConf, uint8_t* pSrc, uint16_t dataLength)
{
  uint16_t msgSize = 0;
  uint16_t idx;

  /* Copy msg to send to ring buffer */
  for (idx = 0; idx < dataLength; idx++) {
    if ((pConf->pTx_W == pConf->pTx_R) && (pConf->nb2Send!=0))
      break;                           /* Ring Buffer is full. */
    *pConf->pTx_W++ = *pSrc++;
    msgSize++;
    if (pConf->pTx_W == pConf->pTx_R)
      break;                           /* Ring Buffer is full. */
    if (pConf->pTx_W == pConf->pTx_BuffEnd) {
      /* Revolve buffer. */
      pConf->pTx_W = pConf->pTx_BuffStart;
    }
  }

  /* Update number of data to send. */
  /* Access locked. */
  pConf->txLock = 1;
  pConf->nb2Send += msgSize;

  /* If end of send interrupt mode arrived during last instruction. */
  if (pConf->txLock == 2)
    pConf->nb2Send -= pConf->nbSent;

  /* Unlock access. */
  pConf->txLock = 0;
  if (msgSize < dataLength)
    pConf->nbMsgLost++;                /* Message not all sent. */
}

/**
 * @brief Tx Transfer completed callback.
 * @param huart UART handle.
 * @retval None
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  SERIAL_TxConfTypeDef* pConf = G_SERIAL_TX_Conf[0];
  UART_HandleTypeDef* pHandler = (UART_HandleTypeDef*)G_SERIAL_TX_Handler[0];

  {
    uint16_t idx = 0;
    for (idx = 0;idx < 2;idx++) {
      pHandler = (UART_HandleTypeDef*)G_SERIAL_TX_Handler[idx];
      if (pHandler == huart) {
        pConf = G_SERIAL_TX_Conf[idx];
        break;
      }
    }
  }

  if (pHandler == huart) {
    pConf->txStatus = SERIAL_TX_OK;
    pConf->pTx_R += pConf->nbSent;
    if (pConf->pTx_R >= pConf->pTx_BuffEnd) {
      pConf->pTx_R = pConf->pTx_BuffStart;
    }

    if (pConf->txLock == 0) {
      pConf->nb2Send -= pConf->nbSent;
    } else {
      pConf->txLock = 2;
    }
  }
}

/*******************************************************************************
 * Function Name  : USART1_TX_SendData
 * Description    : Send ring buffer management
 * Input          : Ring buffer context
 *******************************************************************************/
void USART1_TX_SendData(struct SERIAL_TxConf* pConf)
{
  uint16_t msgSize;

  /* If USART is not already running and data to send */
  if ((pConf->txStatus != SERIAL_TX_ON) && pConf->nb2Send) {
    pConf->txStatus = SERIAL_TX_ON;
    msgSize = (uint32_t)pConf->pTx_BuffEnd - (uint32_t)pConf->pTx_R;

    /* Send all msg or end of ring buffer */
    if (pConf->nb2Send <= msgSize) {
      pConf->nbSent = pConf->nb2Send;

      /* USART1 interrupt send mode*/
      HAL_UART_Transmit_IT(&huart1, pConf->pTx_R, pConf->nb2Send);
    } else {
      pConf->nbSent = msgSize;

      /* USART1 interrupt send mode*/
      HAL_UART_Transmit_IT(&huart1, pConf->pTx_R, msgSize);
    }
  }
}

/*******************************************************************************
 * Function Name  : USART1_Tx_Initialization
 * Description    : Send Initialization of USART1
 * Input          : -
 *******************************************************************************/
void USART1_Tx_Initialization(void)
{
  /* Store USART1 send configuration and its handler. */

  /* Initialize ring buffer information. */
  USART1_TxConf.nb2Send = 0;
  USART1_TxConf.nbSent = 0;
  USART1_TxConf.nbMsgLost = 0;
  USART1_TxConf.buffSize = 512;
  USART1_TxConf.pTx_BuffStart = &USART1_TxDataBuffer[0];
  USART1_TxConf.pTx_BuffEnd = &USART1_TxDataBuffer[512];
  USART1_TxConf.pTx_W = USART1_TxDataBuffer;
  USART1_TxConf.pTx_R = USART1_TxDataBuffer;
  USART1_TxConf.CopyData = TX_CopyData;
  USART1_TxConf.SendData = USART1_TX_SendData;
  USART1_TxConf.txStatus = SERIAL_TX_OFF;
  USART1_TxConf.txLock = 0;

  /* Register this USART1 in global configuration stores. */
  G_SERIAL_TX_Conf[G_SERIAL_TX_Count] = &USART1_TxConf;
  G_SERIAL_TX_Handler[G_SERIAL_TX_Count] = (void*)&huart1;
  G_SERIAL_TX_Count++;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] BanlanceCar_USART.c
 */
