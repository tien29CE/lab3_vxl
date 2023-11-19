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
#define BUTTON_0_Pin GPIO_PIN_0
#define BUTTON_0_GPIO_Port GPIOC
#define BUTTON_2_Pin GPIO_PIN_2
#define BUTTON_2_GPIO_Port GPIOC
#define BUTTON_1_Pin GPIO_PIN_3
#define BUTTON_1_GPIO_Port GPIOC
#define B_0_Pin GPIO_PIN_2
#define B_0_GPIO_Port GPIOA
#define A_0_Pin GPIO_PIN_3
#define A_0_GPIO_Port GPIOA
#define EN_0_Pin GPIO_PIN_7
#define EN_0_GPIO_Port GPIOA
#define D_0_Pin GPIO_PIN_4
#define D_0_GPIO_Port GPIOC
#define F_1_Pin GPIO_PIN_1
#define F_1_GPIO_Port GPIOB
#define TFL_00_Pin GPIO_PIN_2
#define TFL_00_GPIO_Port GPIOB
#define C_1_Pin GPIO_PIN_10
#define C_1_GPIO_Port GPIOB
#define TFL_11_Pin GPIO_PIN_11
#define TFL_11_GPIO_Port GPIOB
#define EN_1_Pin GPIO_PIN_12
#define EN_1_GPIO_Port GPIOB
#define G_0_Pin GPIO_PIN_13
#define G_0_GPIO_Port GPIOB
#define B_1_Pin GPIO_PIN_14
#define B_1_GPIO_Port GPIOB
#define D_1_Pin GPIO_PIN_15
#define D_1_GPIO_Port GPIOB
#define TFL_01_Pin GPIO_PIN_7
#define TFL_01_GPIO_Port GPIOC
#define HORN_Pin GPIO_PIN_9
#define HORN_GPIO_Port GPIOC
#define E_1_Pin GPIO_PIN_8
#define E_1_GPIO_Port GPIOA
#define G_1_Pin GPIO_PIN_9
#define G_1_GPIO_Port GPIOA
#define C_0_Pin GPIO_PIN_10
#define C_0_GPIO_Port GPIOA
#define E_0_Pin GPIO_PIN_3
#define E_0_GPIO_Port GPIOB
#define A_1_Pin GPIO_PIN_4
#define A_1_GPIO_Port GPIOB
#define F_0_Pin GPIO_PIN_5
#define F_0_GPIO_Port GPIOB
#define TFL_10_Pin GPIO_PIN_6
#define TFL_10_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
