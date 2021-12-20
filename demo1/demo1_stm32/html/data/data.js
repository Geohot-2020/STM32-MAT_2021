var dataJson = {"arch":{"ispc":true,"isunix":false,"ismac":false},"build":"demo1","ref":false,"files":[{"name":"demo1.c","type":"source","group":"model","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Model files","code":"/*\r\n * File: demo1.c\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#include \"demo1.h\"\r\n#include \"demo1_private.h\"\r\n\r\n/* GPIOA output mask value definition. */\r\nuint16_t GPIOA_maskWrite;\r\n\r\n/* Block signals (default storage) */\r\nB_demo1 demo1_B;\r\n\r\n/* Block states (default storage) */\r\nDW_demo1 demo1_DW;\r\n\r\n/* Real-time model */\r\nstatic RT_MODEL_demo1 demo1_M_;\r\nRT_MODEL_demo1 *const demo1_M = &demo1_M_;\r\n\r\n/* Model step function */\r\nvoid demo1_step(void)\r\n{\r\n  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */\r\n  demo1_B.PulseGenerator = ((demo1_DW.clockTickCounter < 5000) &&\r\n    (demo1_DW.clockTickCounter >= 0));\r\n\r\n  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */\r\n  if (demo1_DW.clockTickCounter >= 99999) {\r\n    demo1_DW.clockTickCounter = 0;\r\n  } else {\r\n    demo1_DW.clockTickCounter++;\r\n  }\r\n\r\n  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */\r\n  demo1_B.PulseGenerator1 = ((demo1_DW.clockTickCounter_i < 5000) &&\r\n    (demo1_DW.clockTickCounter_i >= 0));\r\n\r\n  /* DiscretePulseGenerator: '<Root>/Pulse Generator1' */\r\n  if (demo1_DW.clockTickCounter_i >= 99999) {\r\n    demo1_DW.clockTickCounter_i = 0;\r\n  } else {\r\n    demo1_DW.clockTickCounter_i++;\r\n  }\r\n\r\n  /* S-Function (GPIO_Write): '<Root>/GPIO_Write' */\r\n  {\r\n    /* Set GPIOA output mask value. */\r\n    GPIOA_maskWrite = GPIOA->ODR;\r\n    GPIOA_maskWrite &= 0xFF3F ;\r\n    GPIOA_maskWrite |= (uint16_t)demo1_B.PulseGenerator << 6;\r\n    GPIOA_maskWrite |= (uint16_t)demo1_B.PulseGenerator1 << 7;\r\n\r\n    /* Write GPIOA input value */\r\n    GPIOA->ODR = (uint16_t)GPIOA_maskWrite;\r\n  }\r\n}\r\n\r\n/* Model initialize function */\r\nvoid demo1_initialize(void)\r\n{\r\n  /* (no initialization code required) */\r\n}\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] demo1.c\r\n */\r\n"},{"name":"demo1.h","type":"header","group":"model","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Model files","code":"/*\r\n * File: demo1.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTW_HEADER_demo1_h_\r\n#define RTW_HEADER_demo1_h_\r\n#include \"STM32_Config.h\"\r\n#include \"demo1_External_Functions.h\"\r\n#ifndef demo1_COMMON_INCLUDES_\r\n#define demo1_COMMON_INCLUDES_\r\n#include \"rtwtypes.h\"\r\n#endif                                 /* demo1_COMMON_INCLUDES_ */\r\n\r\n#include \"demo1_types.h\"\r\n\r\n/* GPIOA output mask value declaration. */\r\nextern uint16_t GPIOA_maskWrite;\r\n\r\n/* Macros for accessing real-time model data structure */\r\n#ifndef rtmGetErrorStatus\r\n#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)\r\n#endif\r\n\r\n#ifndef rtmSetErrorStatus\r\n#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))\r\n#endif\r\n\r\n/* Block signals (default storage) */\r\ntypedef struct {\r\n  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */\r\n  real_T PulseGenerator1;              /* '<Root>/Pulse Generator1' */\r\n} B_demo1;\r\n\r\n/* Block states (default storage) for system '<Root>' */\r\ntypedef struct {\r\n  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */\r\n  int32_T clockTickCounter_i;          /* '<Root>/Pulse Generator1' */\r\n} DW_demo1;\r\n\r\n/* Real-time Model Data Structure */\r\nstruct tag_RTM_demo1 {\r\n  const char_T * volatile errorStatus;\r\n};\r\n\r\n/* Block signals (default storage) */\r\nextern B_demo1 demo1_B;\r\n\r\n/* Block states (default storage) */\r\nextern DW_demo1 demo1_DW;\r\n\r\n/* Model entry point functions */\r\nextern void demo1_initialize(void);\r\nextern void demo1_step(void);\r\n\r\n/* Real-time Model object */\r\nextern RT_MODEL_demo1 *const demo1_M;\r\n\r\n/*-\r\n * The generated code includes comments that allow you to trace directly\r\n * back to the appropriate location in the model.  The basic format\r\n * is <system>/block_name, where system is the system number (uniquely\r\n * assigned by Simulink) and block_name is the name of the block.\r\n *\r\n * Use the MATLAB hilite_system command to trace the generated code back\r\n * to the model.  For example,\r\n *\r\n * hilite_system('<S3>')    - opens system 3\r\n * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3\r\n *\r\n * Here is the system hierarchy for this model\r\n *\r\n * '<Root>' : 'demo1'\r\n */\r\n#endif                                 /* RTW_HEADER_demo1_h_ */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] demo1.h\r\n */\r\n"},{"name":"demo1_private.h","type":"header","group":"model","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Model files","code":"/*\r\n * File: demo1_private.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTW_HEADER_demo1_private_h_\r\n#define RTW_HEADER_demo1_private_h_\r\n#include \"rtwtypes.h\"\r\n#endif                                 /* RTW_HEADER_demo1_private_h_ */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] demo1_private.h\r\n */\r\n"},{"name":"demo1_types.h","type":"header","group":"model","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Model files","code":"/*\r\n * File: demo1_types.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTW_HEADER_demo1_types_h_\r\n#define RTW_HEADER_demo1_types_h_\r\n\r\n/* Model Code Variants */\r\n\r\n/* Forward declaration for rtModel */\r\ntypedef struct tag_RTM_demo1 RT_MODEL_demo1;\r\n\r\n#endif                                 /* RTW_HEADER_demo1_types_h_ */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] demo1_types.h\r\n */\r\n"},{"name":"rtwtypes.h","type":"header","group":"utility","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Utility files","code":"/*\r\n * File: rtwtypes.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTWTYPES_H\r\n#define RTWTYPES_H\r\n\r\n/* Logical type definitions */\r\n#if (!defined(__cplusplus))\r\n#ifndef false\r\n#define false                          (0U)\r\n#endif\r\n\r\n#ifndef true\r\n#define true                           (1U)\r\n#endif\r\n#endif\r\n\r\n/*=======================================================================*\r\n * Target hardware information\r\n *   Device type: Intel->x86-64 (Windows64)\r\n *   Number of bits:     char:   8    short:   16    int:  32\r\n *                       long:  32\r\n *                       native word size:  64\r\n *   Byte ordering: LittleEndian\r\n *   Signed integer division rounds to: Zero\r\n *   Shift right on a signed integer as arithmetic shift: on\r\n *=======================================================================*/\r\n\r\n/*=======================================================================*\r\n * Fixed width word size data types:                                     *\r\n *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *\r\n *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *\r\n *   real32_T, real64_T           - 32 and 64 bit floating point numbers *\r\n *=======================================================================*/\r\ntypedef signed char int8_T;\r\ntypedef unsigned char uint8_T;\r\ntypedef short int16_T;\r\ntypedef unsigned short uint16_T;\r\ntypedef int int32_T;\r\ntypedef unsigned int uint32_T;\r\ntypedef float real32_T;\r\ntypedef double real64_T;\r\n\r\n/*===========================================================================*\r\n * Generic type definitions: boolean_T, char_T, byte_T, int_T, uint_T,       *\r\n *                           real_T, time_T, ulong_T.                        *\r\n *===========================================================================*/\r\ntypedef double real_T;\r\ntypedef double time_T;\r\ntypedef unsigned char boolean_T;\r\ntypedef int int_T;\r\ntypedef unsigned int uint_T;\r\ntypedef unsigned long ulong_T;\r\ntypedef char char_T;\r\ntypedef unsigned char uchar_T;\r\ntypedef char_T byte_T;\r\n\r\n/*===========================================================================*\r\n * Complex number type definitions                                           *\r\n *===========================================================================*/\r\n#define CREAL_T\r\n\r\ntypedef struct {\r\n  real32_T re;\r\n  real32_T im;\r\n} creal32_T;\r\n\r\ntypedef struct {\r\n  real64_T re;\r\n  real64_T im;\r\n} creal64_T;\r\n\r\ntypedef struct {\r\n  real_T re;\r\n  real_T im;\r\n} creal_T;\r\n\r\n#define CINT8_T\r\n\r\ntypedef struct {\r\n  int8_T re;\r\n  int8_T im;\r\n} cint8_T;\r\n\r\n#define CUINT8_T\r\n\r\ntypedef struct {\r\n  uint8_T re;\r\n  uint8_T im;\r\n} cuint8_T;\r\n\r\n#define CINT16_T\r\n\r\ntypedef struct {\r\n  int16_T re;\r\n  int16_T im;\r\n} cint16_T;\r\n\r\n#define CUINT16_T\r\n\r\ntypedef struct {\r\n  uint16_T re;\r\n  uint16_T im;\r\n} cuint16_T;\r\n\r\n#define CINT32_T\r\n\r\ntypedef struct {\r\n  int32_T re;\r\n  int32_T im;\r\n} cint32_T;\r\n\r\n#define CUINT32_T\r\n\r\ntypedef struct {\r\n  uint32_T re;\r\n  uint32_T im;\r\n} cuint32_T;\r\n\r\n/*=======================================================================*\r\n * Min and Max:                                                          *\r\n *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *\r\n *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *\r\n *=======================================================================*/\r\n#define MAX_int8_T                     ((int8_T)(127))\r\n#define MIN_int8_T                     ((int8_T)(-128))\r\n#define MAX_uint8_T                    ((uint8_T)(255U))\r\n#define MAX_int16_T                    ((int16_T)(32767))\r\n#define MIN_int16_T                    ((int16_T)(-32768))\r\n#define MAX_uint16_T                   ((uint16_T)(65535U))\r\n#define MAX_int32_T                    ((int32_T)(2147483647))\r\n#define MIN_int32_T                    ((int32_T)(-2147483647-1))\r\n#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))\r\n\r\n/* Block D-Work pointer type */\r\ntypedef void * pointer_T;\r\n\r\n#endif                                 /* RTWTYPES_H */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] rtwtypes.h\r\n */\r\n"},{"name":"STM32_Config.h","type":"header","group":"","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Other files","code":"/*\r\n * File: STM32_Config.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTW_HEADER_STM32_Config_h_\r\n#define RTW_HEADER_STM32_Config_h_\r\n#include \"stm32f4xx.h\"\r\n#include \"stm32f4xx_hal.h\"\r\n\r\n/* For Error_Handler() declaration. */\r\n#include \"main.h\"\r\n#include \"rtwtypes.h\"\r\n#endif                                 /* RTW_HEADER_STM32_Config_h_ */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] STM32_Config.h\r\n */\r\n"},{"name":"demo1_External_Functions.h","type":"header","group":"","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Other files","code":"/*\r\n * File: demo1_External_Functions.h\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n#ifndef RTW_HEADER_demo1_External_Functions_h_\r\n#define RTW_HEADER_demo1_External_Functions_h_\r\n\r\n/* Generated by STM32_Config.*/\r\n/***** External Imported Functions *****/\r\n#endif                              /* RTW_HEADER_demo1_External_Functions_h_ */\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] demo1_External_Functions.h\r\n */\r\n"},{"name":"main.c","type":"source","group":"","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Other files","code":"/*\r\n * File: main.c\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n/* This section of code is going to be merged by the STM32CubeMX tool. */\r\n/* USER CODE BEGIN 0 */\r\n#include <stdio.h>\r\n#include \"demo1.h\"\r\n#include \"rtwtypes.h\"\r\n\r\n/* Flags for taskOverrun */\r\nstatic boolean_T OverrunFlags[1] = { false, };\r\n\r\n/* Number of auto reload timer rotation computed */\r\nstatic volatile uint32_t autoReloadTimerLoopVal_S = 1;\r\n\r\n/* Remaining number of auto reload timer rotation to do */\r\nvolatile uint32_t remainAutoReloadTimerLoopVal_S = 1;\r\n\r\n/* USER CODE END 0 */\r\n\r\n/**\r\n * @brief  The application entry point.\r\n * @retval int\r\n */\r\nint main (void)\r\n{\r\n  /* This section of code is going to be merged by the STM32CubeMX tool. */\r\n  /* USER CODE BEGIN 1 */\r\n  /* USER CODE END 1 */\r\n\r\n  /* This section of code is going to be merged by the STM32CubeMX tool. */\r\n  /* USER CODE BEGIN 2 */\r\n  /* Use Systick arm timer and interrupt to tick step() functions of the Simulink model. */\r\n  /* Fundamental sample time is set to: '0.0001' s */\r\n  if (SysTick_Config((uint32_t)(SystemCoreClock/10000.0))) {\r\n    autoReloadTimerLoopVal_S = 1;\r\n    do {\r\n      autoReloadTimerLoopVal_S++;\r\n    } while ((uint32_t)(SystemCoreClock/10000.0)/autoReloadTimerLoopVal_S >\r\n             SysTick_LOAD_RELOAD_Msk);\r\n\r\n    SysTick_Config((uint32_t)(SystemCoreClock/10000.0)/autoReloadTimerLoopVal_S);\r\n  }\r\n\r\n  /* Set number of loop to do. */\r\n  remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;\r\n\r\n  {\r\n    int i;\r\n    for (i = 0; i < 1; i++) {\r\n      OverrunFlags[i] = false;\r\n    }\r\n  }\r\n\r\n  /* Initialize model */\r\n  demo1_initialize();\r\n\r\n  /* USER CODE END 2 */\r\n\r\n  /* This section of code is going to be merged by the STM32CubeMX tool. */\r\n  /* USER CODE BEGIN WHILE */\r\n  /* Infinite loop */\r\n  /* Real time from systickHandler */\r\n  while (1) {\r\n    /*Process tasks every solver time*/\r\n    if (remainAutoReloadTimerLoopVal_S == 0) {\r\n      remainAutoReloadTimerLoopVal_S = autoReloadTimerLoopVal_S;\r\n\r\n      /* Check base rate for overrun */\r\n      if (OverrunFlags[0]) {\r\n        rtmSetErrorStatus(demo1_M, \"Overrun\");\r\n      }\r\n\r\n      OverrunFlags[0] = true;\r\n\r\n      /* Step the model for base rate */\r\n      demo1_step();\r\n\r\n      /* Get model outputs here */\r\n\r\n      /* Indicate task for base rate complete */\r\n      OverrunFlags[0] = false;\r\n    }\r\n  }\r\n\r\n  /* USER CODE END WHILE */\r\n\r\n  /* USER CODE BEGIN 3 */\r\n  /* USER CODE END 3 */\r\n}\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] main.c\r\n */\r\n"},{"name":"stm32xxxx_it.c","type":"source","group":"","path":"D:\\Simulink_stm32f4\\STM32F407VET6\\demo1\\demo1_stm32","tag":"","groupDisplay":"Other files","code":"/*\r\n * File: stm32xxxx_it.c\r\n *\r\n * Code generated for Simulink model :demo1.\r\n *\r\n * Model version      : 1.1\r\n * Simulink Coder version    : 9.6 (R2021b) 14-May-2021\r\n * TLC version       : 9.6 (Aug 25 2021)\r\n * C/C++ source code generated on  : Wed Dec 15 10:30:35 2021\r\n *\r\n * Target selection: stm32.tlc\r\n * Embedded hardware selection: Intel->x86-64 (Windows64)\r\n * Code generation objectives: Unspecified\r\n * Validation result: Not run\r\n *\r\n *\r\n *\r\n * ******************************************************************************\r\n * * attention\r\n * *\r\n * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS\r\n * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE\r\n * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY\r\n * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING\r\n * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE\r\n * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.\r\n * *\r\n * ******************************************************************************\r\n */\r\n\r\n/**\r\n * @brief This function handles System tick timer.\r\n */\r\nvoid SysTick_Handler(void)\r\n{\r\n  /* This section of code is going to be merged by the STM32CubeMX tool. */\r\n  /* USER CODE BEGIN SysTick_IRQn 0 */\r\n  {\r\n    extern volatile uint32_t remainAutoReloadTimerLoopVal_S;\r\n\r\n    /* Manage number of loop before interrupt has to be processed. */\r\n    if (remainAutoReloadTimerLoopVal_S) {\r\n      remainAutoReloadTimerLoopVal_S--;\r\n    }\r\n  }\r\n\r\n  /* USER CODE END SysTick_IRQn 0 */\r\n\r\n  /* USER CODE BEGIN SysTick_IRQn 1 */\r\n\r\n  /* USER CODE END SysTick_IRQn 1 */\r\n}\r\n\r\n/* File trailer for Real-Time Workshop generated code.\r\n *\r\n * [EOF] stm32xxxx_it.c\r\n */\r\n"}],"coverage":[{"id":"SimulinkCoverage","name":"Simulink Coverage","files":[]},{"id":"Bullseye","name":"Bullseye Coverage","files":[]},{"id":"LDRA","name":"LDRA Testbed","files":[]}]};