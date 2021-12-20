/*
 * File: MOTOR_USART.h
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

#ifndef RTW_HEADER_MOTOR_USART_h_
#define RTW_HEADER_MOTOR_USART_h_
#include "STM32_Config.h"

/* USART1_Tx_Initialization declaration. */
void USART1_Tx_Initialization(void);

/**
 * @brief SERIAL Rx State structures definition
 */
typedef enum {
  SERIAL_RX_ON = 0x00,                 /*!< Rx serial communication started. */
  SERIAL_RX_OK = 0x01,
                 /*!< Rx serial communication terminated with data available. */
  SERIAL_RX_OFF = 0x02                 /*!< Rx serial communication stopped. */
} SERIAL_RxStatusTypeDef;

/**
 * @brief SERIAL data information
 */
typedef struct {
  uint8_t* pRX_BuffStart;              /*!< point to ring buffer*/
  uint8_t* pRX_R;                    /*!< Point to receive data value buffer. */
  __IO SERIAL_RxStatusTypeDef rxStatus;
                                     /*!< Usart receive communication status. */
} SERIAL_RxConfTypeDef;

/**
 * @brief USART Tx State structures definition
 */
typedef enum {
  SERIAL_TX_ON = 0x00,                 /*!< Tx serial communication started. */
  SERIAL_TX_OK = 0x01,               /*!< Tx serial communication terminated. */
  SERIAL_TX_OFF = 0x02                 /*!< Tx serial communication stopped. */
} SERIAL_TxStatusTypeDef;

/**
 * @brief SERIAL data information
 */
typedef struct SERIAL_TxConf {
  uint16_t nb2Send;                    /*!< Nb of char to send*/
  uint16_t nbSent;                     /*!< Nb sent char*/
  uint16_t nbMsgLost;       /*!< Nb lost msg (not enough space in ring buffer)*/
  uint16_t buffSize;                   /*!< Size of send ring buffer*/
  uint8_t* pTx_BuffStart;              /*!< point to ring buffer*/
  uint8_t* pTx_BuffEnd;                /*!< point to end ring buffer*/
  uint8_t* pTx_W;                      /*!< point to free space*/
  uint8_t* pTx_R;                      /*!< point to char to send*/
  void (* CopyData)(struct SERIAL_TxConf* pConf, uint8_t* pSrc, uint16_t
                    dataLength);
  void (* SendData)(struct SERIAL_TxConf* pConf);
  __IO SERIAL_TxStatusTypeDef txStatus;/*!< Usart send communication status.*/
  __IO uint8_t txLock;                 /*!< lock data access */
} SERIAL_TxConfTypeDef;

/* USART1_Rx_Initialization declaration. */
void USART1_Rx_Initialization(void);

/* USART1 HAL handler. */
extern UART_HandleTypeDef huart1;

/* USART1 receive configuration. */
extern SERIAL_RxConfTypeDef USART1_RxConf;

/* USART1 HAL handler. */
extern UART_HandleTypeDef huart1;

/* USART1 send configuration. */
extern SERIAL_TxConfTypeDef USART1_TxConf;
void TX_CopyData(struct SERIAL_TxConf*, uint8_t*, uint16_t);

/* USART1_TX_SendData declaration. */
void USART1_TX_SendData(struct SERIAL_TxConf*);

#endif                                 /* RTW_HEADER_MOTOR_USART_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] MOTOR_USART.h
 */
