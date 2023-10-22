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
#define SEGa_Pin GPIO_PIN_0
#define SEGa_GPIO_Port GPIOB
#define SEGb_Pin GPIO_PIN_1
#define SEGb_GPIO_Port GPIOB
#define SEGc_Pin GPIO_PIN_2
#define SEGc_GPIO_Port GPIOB
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
#define SEGd_Pin GPIO_PIN_3
#define SEGd_GPIO_Port GPIOB
#define SEGe_Pin GPIO_PIN_4
#define SEGe_GPIO_Port GPIOB
#define SEGf_Pin GPIO_PIN_5
#define SEGf_GPIO_Port GPIOB
#define SEGg_Pin GPIO_PIN_6
#define SEGg_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
