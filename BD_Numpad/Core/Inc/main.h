/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define led10_Pin GPIO_PIN_13
#define led10_GPIO_Port GPIOC
#define row1_Pin GPIO_PIN_4
#define row1_GPIO_Port GPIOA
#define row2_Pin GPIO_PIN_5
#define row2_GPIO_Port GPIOA
#define row3_Pin GPIO_PIN_6
#define row3_GPIO_Port GPIOA
#define row4_Pin GPIO_PIN_7
#define row4_GPIO_Port GPIOA
#define row5_Pin GPIO_PIN_0
#define row5_GPIO_Port GPIOB
#define col1_Pin GPIO_PIN_1
#define col1_GPIO_Port GPIOB
#define col2_Pin GPIO_PIN_10
#define col2_GPIO_Port GPIOB
#define col3_Pin GPIO_PIN_11
#define col3_GPIO_Port GPIOB
#define col4_Pin GPIO_PIN_12
#define col4_GPIO_Port GPIOB
#define col5_Pin GPIO_PIN_13
#define col5_GPIO_Port GPIOB
#define led1_Pin GPIO_PIN_14
#define led1_GPIO_Port GPIOB
#define led2_Pin GPIO_PIN_15
#define led2_GPIO_Port GPIOB
#define led3_Pin GPIO_PIN_9
#define led3_GPIO_Port GPIOA
#define led4_Pin GPIO_PIN_10
#define led4_GPIO_Port GPIOA
#define led5_Pin GPIO_PIN_5
#define led5_GPIO_Port GPIOB
#define led6_Pin GPIO_PIN_6
#define led6_GPIO_Port GPIOB
#define led7_Pin GPIO_PIN_7
#define led7_GPIO_Port GPIOB
#define led8_Pin GPIO_PIN_8
#define led8_GPIO_Port GPIOB
#define led9_Pin GPIO_PIN_9
#define led9_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
