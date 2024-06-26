/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


// Libs declaration:
#include <string.h>
#include <stdio.h>


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


// Pin definitions:



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */


// Deklaracja zmiennych:
uint16_t raw;
char msg[10];

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

//HAL_GPIO_WritePin(GPIOA, A_Pin , GPIO_PIN_RESET);

// Test: GPIO set pin high:
//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);

// Get ADC Value:
HAL_ADC_Start(&hadc1);
HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
raw = HAL_ADC_GetValue(&hadc1);


// Test: GPIO set pin low:
//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);

 // USART check:
// Convert to string and print:
sprintf(msg, "%hu\r\n", raw);
HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

// 7seg display - if statement:

if (raw == 0)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);

}
else if (raw > 0 && raw < 124)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 124 && raw < 248)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 248 && raw < 372)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 372 && raw < 496) //0.4
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 496 && raw < 620)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 620 && raw < 744) //0.6
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);

}
else if (raw >= 744 && raw < 868)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);

}
else if (raw >= 868 && raw < 992)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 992 && raw < 1116)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1116 && raw < 1240) //1.0
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1240 && raw < 1364)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1364 && raw < 1488)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1488 && raw < 1612)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1612 && raw < 1736) //1.4
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1736 && raw < 1860)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1860 && raw < 1984)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 1984 && raw < 2108)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2108 && raw < 2232)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2232 && raw < 2356)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2356 && raw < 2480) // 2.0
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2480 && raw < 2604)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2604 && raw < 2728)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2728 && raw < 2852)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2852 && raw < 2976)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 2976 && raw < 3100)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3100 && raw < 3224)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3224 && raw < 3348)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3348 && raw < 3472)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3472 && raw < 3596)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3596 && raw < 3720) // 3.0
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3720 && raw < 3844)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else if (raw >= 3844 && raw < 3968)
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}
else
{
	// Left num:
	HAL_GPIO_WritePin(GPIOB, A1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, B1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, C1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, E1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, F1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, G1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, DP1_Pin, GPIO_PIN_RESET);

	// Right num:
	HAL_GPIO_WritePin(GPIOC, A2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, B2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, C2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, D2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, E2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, F2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, G2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, DP2_Pin, GPIO_PIN_SET);
}

HAL_Delay(100);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_ADC12;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_1;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, A2_Pin|B2_Pin|C2_Pin|D2_Pin
                          |E2_Pin|F2_Pin|G2_Pin|DP2_Pin
                          |LEFT_DISPLAY_Pin|RIGHT_DISPLAY_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LD2_Pin|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A1_Pin|B1B2_Pin|C1_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|DP1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : A2_Pin B2_Pin C2_Pin D2_Pin
                           E2_Pin F2_Pin G2_Pin DP2_Pin
                           LEFT_DISPLAY_Pin RIGHT_DISPLAY_Pin */
  GPIO_InitStruct.Pin = A2_Pin|B2_Pin|C2_Pin|D2_Pin
                          |E2_Pin|F2_Pin|G2_Pin|DP2_Pin
                          |LEFT_DISPLAY_Pin|RIGHT_DISPLAY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LD2_Pin PA10 */
  GPIO_InitStruct.Pin = LD2_Pin|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A1_Pin B1B2_Pin C1_Pin D1_Pin
                           E1_Pin F1_Pin G1_Pin DP1_Pin */
  GPIO_InitStruct.Pin = A1_Pin|B1B2_Pin|C1_Pin|D1_Pin
                          |E1_Pin|F1_Pin|G1_Pin|DP1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
