/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define A2_Pin GPIO_PIN_1
#define A2_GPIO_Port GPIOC
#define B2_Pin GPIO_PIN_2
#define B2_GPIO_Port GPIOC
#define C2_Pin GPIO_PIN_3
#define C2_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_4
#define D2_GPIO_Port GPIOC
#define E2_Pin GPIO_PIN_5
#define E2_GPIO_Port GPIOC
#define A1_Pin GPIO_PIN_1
#define A1_GPIO_Port GPIOB
#define B1B2_Pin GPIO_PIN_2
#define B1B2_GPIO_Port GPIOB
#define F2_Pin GPIO_PIN_6
#define F2_GPIO_Port GPIOC
#define G2_Pin GPIO_PIN_7
#define G2_GPIO_Port GPIOC
#define DP2_Pin GPIO_PIN_8
#define DP2_GPIO_Port GPIOC
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define LEFT_DISPLAY_Pin GPIO_PIN_10
#define LEFT_DISPLAY_GPIO_Port GPIOC
#define RIGHT_DISPLAY_Pin GPIO_PIN_11
#define RIGHT_DISPLAY_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define C1_Pin GPIO_PIN_4
#define C1_GPIO_Port GPIOB
#define D1_Pin GPIO_PIN_5
#define D1_GPIO_Port GPIOB
#define E1_Pin GPIO_PIN_6
#define E1_GPIO_Port GPIOB
#define F1_Pin GPIO_PIN_7
#define F1_GPIO_Port GPIOB
#define G1_Pin GPIO_PIN_8
#define G1_GPIO_Port GPIOB
#define DP1_Pin GPIO_PIN_9
#define DP1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
