/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include<stdlib.h>
#include <stdbool.h>
#include "BUTTON_HANDLER.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct {
	GPIO_TypeDef* port;
	uint16_t pin;
	bool state; 
} pinStructLED;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define QUANTITY_SEQUENCE 			7
#define QUANTITY_LEDS						5
#define QUANTITY_KEYS						5

#define LED_ALL_PORT LED_0_GPIO_Port
#define LED_ALL_PIN ( LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin )
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
uint8_t sequences[QUANTITY_SEQUENCE][QUANTITY_LEDS]; //масив для зберігання всих послідовностей світлодіодів.
uint8_t number_of_sequence = 0;											 //Номер відображення послідовності
uint16_t speed = 1000;															 //чим менше число, тим більша швидкість послідовного запалювання світлодіодів

pinStructLED led[] = {
		{LED_0_GPIO_Port, LED_0_Pin, false},
		{LED_1_GPIO_Port, LED_1_Pin, false},
		{LED_2_GPIO_Port, LED_2_Pin, false},
		{LED_3_GPIO_Port, LED_3_Pin, false},
		{LED_4_GPIO_Port, LED_4_Pin, false}
};

typedef enum{
	C5,
	E5,
	G5,
	H5,
	C6,
	tone_6,
	tone_7,
	num_tones
} bzTones;

uint16_t toneSound[num_tones] = { 1912 ,1517 ,1277 ,1013, 956, 4292, 447};//масив з тонами для бузера

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

void generateSequence(void);
void showSequence(void);
void getSequence(void);
void wrongSequence(void);
void rightSequence(void);
void pressManyKeys(void);
void buzzSound(bzTones tone, uint32_t length);

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
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
	BUTTON_Init();
	
	
	generateSequence();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
			if(number_of_sequence < QUANTITY_SEQUENCE)
			{
				showSequence();
				getSequence();
			}
				
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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 8;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 64-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 200-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_4_Pin|LED_3_Pin|LED_2_Pin|LED_1_Pin
                          |LED_0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : KEY_4_Pin */
  GPIO_InitStruct.Pin = KEY_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY_4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : KEY_0_Pin KEY_1_Pin KEY_2_Pin KEY_3_Pin */
  GPIO_InitStruct.Pin = KEY_0_Pin|KEY_1_Pin|KEY_2_Pin|KEY_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_4_Pin LED_3_Pin LED_2_Pin LED_1_Pin
                           LED_0_Pin */
  GPIO_InitStruct.Pin = LED_4_Pin|LED_3_Pin|LED_2_Pin|LED_1_Pin
                          |LED_0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BUZZER_Pin */
  GPIO_InitStruct.Pin = BUZZER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUZZER_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void generateSequence(void)
{
		srand(1);
	
		for(uint8_t i = 0; i < QUANTITY_SEQUENCE; i++)
		{
				for(uint8_t j = 0; j < QUANTITY_LEDS; j++)
				{
							sequences[i][j] = (uint8_t) rand() % 5;
				}
		}
}


void showSequence(void)
{
		for(uint8_t j = 0; j < QUANTITY_LEDS; j++)
		{
				HAL_GPIO_WritePin(led[sequences[number_of_sequence][j]].port, led[sequences[number_of_sequence][j]].pin, GPIO_PIN_SET);
				buzzSound(sequences[number_of_sequence][j] ,speed);
				HAL_GPIO_WritePin(led[sequences[number_of_sequence][j]].port, led[sequences[number_of_sequence][j]].pin, GPIO_PIN_RESET);
				HAL_Delay(speed);
		}		
}


void getSequence(void)
{
		uint8_t right_sequences = 0;
	
		for(uint8_t i = 0; i < QUANTITY_LEDS; i++)
		{
				bool butt_was_pressed = false;
				uint8_t pos_key = -1; 										//позиція натисненої кнопки (яка саме кнопка натиснена)
				bool flag = false;
										
				while(flag == false)
				{
						uint8_t is_key_press[QUANTITY_KEYS] = {0};	//кількість натиснених кнопок (одночасно повинно бути не більше однієї)
						
						BUTTON_Process();
						for(uint8_t j = 0; j < QUANTITY_KEYS; j++)
						{	
								
								if(BUTTON_GetAction(j, TRIG_RISE_FRIQUENTLY) == BUTTON_SHORT_PRESS)
								{
										is_key_press[j] = 1;	
								}
						}
						BUTTON_ResetActions();
						
						uint8_t num = 0;
						for(uint8_t j = 0; j < QUANTITY_KEYS; j++)
						{	
									if(is_key_press[j])
									{
											num++;
											pos_key = j;
									}
									is_key_press[j] = 0;
						}
						if(num > 1)
						{
								pressManyKeys();
								butt_was_pressed = false;
						}
						
						else if(num == 1)
						{
								HAL_GPIO_WritePin(led[pos_key].port, led[pos_key].pin, GPIO_PIN_SET);
								
							__HAL_TIM_SET_AUTORELOAD(&htim3, toneSound[pos_key]);//відтворювати звук поки натиснута кнопка
								HAL_TIM_Base_Start_IT(&htim3);
								
								while(1)		
								{
										BUTTON_Process();
										if(BUTTON_GetAction(pos_key, TRIG_RISE_FRIQUENTLY) != BUTTON_SHORT_PRESS)
										{
												BUTTON_ResetActions();
												break;
										}
								}
								
								butt_was_pressed = true;
						}
						
						else if(num == 0)
						{
								if(butt_was_pressed)
								{									
									HAL_GPIO_WritePin(led[pos_key].port, led[pos_key].pin, GPIO_PIN_RESET);
									
									HAL_TIM_Base_Stop_IT(&htim3);	//зупинити відтворювання звуку після відпущеної кнопки
									HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
									
									if(pos_key == sequences[number_of_sequence][i]) //В кінці комбінації перевіряється самий останній світлодіод
									{
											if(i == QUANTITY_LEDS-1)
											{
													number_of_sequence++;
													speed -= 100;
													rightSequence();
											}
									}
									else
									{
											i = QUANTITY_LEDS;
											number_of_sequence = 0;
											speed = 1000;
											wrongSequence();
									}
									
									butt_was_pressed = false;
									flag = true;
								}
						}	
				}	
		}		
}


void wrongSequence(void)
{
		for(uint8_t i = 0; i < 3; i++)
		{
				HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_SET);
				buzzSound(tone_6, 500);
				HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_RESET);
				HAL_Delay(500);
		}	
		HAL_Delay(1000);
}


void rightSequence(void)
{
		/////////////////////////////////////////////////////////////перший звук продовжується 700мс.	
	__HAL_TIM_SET_AUTORELOAD(&htim3, toneSound[tone_6]);
		HAL_TIM_Base_Start_IT(&htim3);
	
		uint8_t i = 0;
		uint8_t j = QUANTITY_LEDS - 1;
		do // 5 комбінацій по запаленню світлодіодів разом зі звуком
		{
			HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(led[j].port, led[j].pin, GPIO_PIN_SET);
			HAL_Delay(140);
			HAL_GPIO_WritePin(led[i].port, led[i].pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(led[j].port, led[j].pin, GPIO_PIN_RESET);
		 
				++i;
				--j;	
		}
		while(i != QUANTITY_LEDS);
		
		HAL_TIM_Base_Stop_IT(&htim3);	//зупинка звуку
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
		///////////////////////////////////////////////////////////
		
	__HAL_TIM_SET_AUTORELOAD(&htim3, toneSound[tone_7]); //відтворити звук, та блимнути всима світлодіодами
		HAL_TIM_Base_Start_IT(&htim3);
		
		HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_RESET);
		
		HAL_TIM_Base_Stop_IT(&htim3); //зупинка звуку
		HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
		
		HAL_Delay(1000);
}


void pressManyKeys(void)
{
		for(uint8_t i = 0; i < 2; i++)
		{
				HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_SET);
				buzzSound(C5, 75);
				HAL_GPIO_WritePin(LED_ALL_PORT, LED_ALL_PIN, GPIO_PIN_RESET);
				HAL_Delay(75);
		}
}


void buzzSound(bzTones tone, uint32_t length)
{
	
	__HAL_TIM_SET_AUTORELOAD(&htim3, toneSound[tone]);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_Delay(length);
	HAL_TIM_Base_Stop_IT(&htim3);
	HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, GPIO_PIN_RESET);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
		HAL_GPIO_TogglePin(BUZZER_GPIO_Port, BUZZER_Pin);
}

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
