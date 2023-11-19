/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define MODE_Pin GPIO_PIN_1
#define MODE_GPIO_Port GPIOA
#define ADJ_Pin GPIO_PIN_2
#define ADJ_GPIO_Port GPIOA
#define SET_Pin GPIO_PIN_3
#define SET_GPIO_Port GPIOA
#define R1_Pin GPIO_PIN_4
#define R1_GPIO_Port GPIOA
#define A1_Pin GPIO_PIN_5
#define A1_GPIO_Port GPIOA
#define G1_Pin GPIO_PIN_6
#define G1_GPIO_Port GPIOA
#define R2_Pin GPIO_PIN_7
#define R2_GPIO_Port GPIOA
#define SEG1a_Pin GPIO_PIN_0
#define SEG1a_GPIO_Port GPIOB
#define SEG1b_Pin GPIO_PIN_1
#define SEG1b_GPIO_Port GPIOB
#define SEG1c_Pin GPIO_PIN_2
#define SEG1c_GPIO_Port GPIOB
#define SEG2d_Pin GPIO_PIN_10
#define SEG2d_GPIO_Port GPIOB
#define SEG2e_Pin GPIO_PIN_11
#define SEG2e_GPIO_Port GPIOB
#define SEG2f_Pin GPIO_PIN_12
#define SEG2f_GPIO_Port GPIOB
#define SEG2g_Pin GPIO_PIN_13
#define SEG2g_GPIO_Port GPIOB
#define A2_Pin GPIO_PIN_8
#define A2_GPIO_Port GPIOA
#define G2_Pin GPIO_PIN_9
#define G2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_10
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_11
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_12
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_13
#define EN3_GPIO_Port GPIOA
#define SEG1d_Pin GPIO_PIN_3
#define SEG1d_GPIO_Port GPIOB
#define SEG1e_Pin GPIO_PIN_4
#define SEG1e_GPIO_Port GPIOB
#define SEG1f_Pin GPIO_PIN_5
#define SEG1f_GPIO_Port GPIOB
#define SEG1g_Pin GPIO_PIN_6
#define SEG1g_GPIO_Port GPIOB
#define SEG2a_Pin GPIO_PIN_7
#define SEG2a_GPIO_Port GPIOB
#define SEG2b_Pin GPIO_PIN_8
#define SEG2b_GPIO_Port GPIOB
#define SEG2c_Pin GPIO_PIN_9
#define SEG2c_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
