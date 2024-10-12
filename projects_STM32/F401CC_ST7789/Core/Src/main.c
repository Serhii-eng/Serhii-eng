/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "AHT10.h"
#include "OneButton.h"
#include "ST7789.h"
#include "fonts.h"
#include "stdio.h"
//як користуватись SWO?
//UART вивід данних в термінал?
//як промальовувати робочий простір раз в секунду?

#define TIMEOUT_ENCODER 						100
#define TIMEOUT_KEY 								500

#define MENU_COORD_X								20
#define MENU_COORD_Y								20
#define MENU_COORD_OFFSIZE					20

#define MENU_COLOR_FON							(RGB565(0, 0, 0))
#define MENU_COLOR_CURRENT					(RGB565(255, 255, 255))
#define MENU_COLOR_OLD							(RGB565(150, 150, 150))

#define MENU_MAX_DEFAULT_VALUE  		60
#define MENU_MIN_DEFAULT_VALUE  		40
#define MENU_VALUE_SET_MAX  				100
#define MENU_VALUE_SET_MIN  				0

#define MENU_FLOAT_DEFAULT_VALUE  	2.5
#define MENU_FLOAT_SET_MAX_VALUE  	5
#define MENU_FLOAT_SET_MIN_VALUE  	0
#define DEVISION_FLOAT_VAL          0.1

#define TEMPERATURE_POSITION_STR    5

typedef enum{
	MENU_MAX_VALUE,
	MENU_MIN_VALUE,
	MENU_BKL,
	MENU_LANG,
	MENU_FLOAT_VALUE,
	
	MENU_COUNT
}TypeMenu;

typedef enum{
	MENU_LANG_EN,
	MENU_LANG_DE,
	MENU_LANG_PL,
	
	MENU_LANG_COUNT
}TypeLang;


typedef enum{
	LIGHT_LOW,
	LIGHT_MID,
	LIGHT_HIGH,
	
	LIGHT_COUNT
}TypeBackLighting;


uint16_t light_values[LIGHT_COUNT] = {200, 500, 1000};
	
//////////

typedef enum{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_STRING
}CurrentTypesValue;

typedef union{
	int32_t current_i;
	float current_f;	
}CurrentValueUnion;

typedef struct{
	CurrentValueUnion current_value;
	CurrentValueUnion max_value;
	CurrentValueUnion min_value;
	char* menu_string[MENU_LANG_COUNT];
	CurrentTypesValue current_type;
	char* current_value_str[MENU_LANG_COUNT][10];
}Menu_unit;

Menu_unit CurrentMenu[MENU_COUNT] = {
	[MENU_MAX_VALUE] = {
												.menu_string = { 
														[MENU_LANG_EN] = "MAX VALUE EN:",
														[MENU_LANG_DE] = "MAX VALUE DE:",
														[MENU_LANG_PL] = "MAX VALUE PL:"
												},
												.current_type = TYPE_INT,
												.max_value.current_i = MENU_VALUE_SET_MAX,
												.min_value.current_i = MENU_VALUE_SET_MIN,
												.current_value.current_i = MENU_MAX_DEFAULT_VALUE,
												.current_value_str = NULL
											},
	[MENU_MIN_VALUE] = {
												.menu_string = { 
														[MENU_LANG_EN] = "MIN VALUE EN:",
														[MENU_LANG_DE] = "MIN VALUE DE:",
														[MENU_LANG_PL] = "MIN VALUE PL:"
												},
												.current_type = TYPE_INT,
												.max_value.current_i = MENU_VALUE_SET_MAX,
												.min_value.current_i = MENU_VALUE_SET_MIN,
												.current_value.current_i = MENU_MIN_DEFAULT_VALUE,
												.current_value_str = NULL
											},
				[MENU_BKL] = {
												.menu_string = { 
														[MENU_LANG_EN] = "BKL EN:",
														[MENU_LANG_DE] = "BKL DE:",
														[MENU_LANG_PL] = "BKL PL:"
												},
												.current_type = TYPE_STRING,
												.max_value.current_i = LIGHT_COUNT-1,
												.min_value.current_i = 0,
												.current_value.current_i = LIGHT_MID,
												.current_value_str = {
													[MENU_LANG_EN] = {
																[LIGHT_LOW] = "LOW EN",
																[LIGHT_MID] = "MID EN",
																[LIGHT_HIGH] = "HIGH EN"
													},
													[MENU_LANG_DE] = {
																[LIGHT_LOW] = "LOW DE",
																[LIGHT_MID] = "MID DE",
																[LIGHT_HIGH] = "HIGH DE"
													},
													[MENU_LANG_PL] = {
																[LIGHT_LOW] = "LOW PL",
																[LIGHT_MID] = "MID PL",
																[LIGHT_HIGH] = "HIGH PL"
													}
												}
											},
	[MENU_LANG] = {
												.menu_string = { 
														[MENU_LANG_EN] = "LANG EN:",
														[MENU_LANG_DE] = "LANG DE:",
														[MENU_LANG_PL] = "LANG PL:"
												},
												.current_type = TYPE_STRING,
												.max_value.current_i = MENU_LANG_COUNT-1,
												.min_value.current_i = 0,
												.current_value.current_i = MENU_LANG_EN,
												.current_value_str = {
												[MENU_LANG_EN] = {
															[MENU_LANG_EN] = "LANG_EN EN",
															[MENU_LANG_DE] = "LANG_EN DE",
															[MENU_LANG_PL] = "LANG_EN PL"
												},
												[MENU_LANG_DE] = {
															[MENU_LANG_EN] = "LANG_DE EN",
															[MENU_LANG_DE] = "LANG_DE DE",
															[MENU_LANG_PL] = "LANG_DE PL"
												},
												[MENU_LANG_PL] = {
															[MENU_LANG_EN] = "LANG_PL EN",
															[MENU_LANG_DE] = "LANG_PL DE",
															[MENU_LANG_PL] = "LANG_PL PL"
												}
											}
										},
		[MENU_FLOAT_VALUE] = {
												.menu_string = { 
														[MENU_LANG_EN] = "FLOAT VALUE EN:",
														[MENU_LANG_DE] = "FLOAT VALUE DE:",
														[MENU_LANG_PL] = "FLOAT VALUE PL:"
												},
												.current_type = TYPE_FLOAT,
												.max_value.current_f = MENU_FLOAT_SET_MAX_VALUE,
												.min_value.current_f = MENU_FLOAT_SET_MIN_VALUE,
												.current_value.current_f =  MENU_FLOAT_DEFAULT_VALUE,
												.current_value_str = NULL
											}
};

//при тіку енкодера, промальвує меню
volatile int8_t menu_draw_flag = 1;
//флаг для входження в параметри меню
volatile int8_t flag_enter_menu_value = 0;
int8_t flag_enter_work_space = 0;
//змінна зберігає поточне значення енкодера (для вибирання рядків меню)
volatile int8_t menu_current = MENU_MAX_VALUE;
// 0.0 -> 5.0 = 0.1

///////////////////////////////////////
//Змінні для відображення показників температури та вологості з датчика
volatile float temperature_value = 0;
volatile float humidity_value = 0;

//Для відображення рядка температури в різних мовах
char* temperature_string[MENU_LANG_COUNT] = {
	[MENU_LANG_EN] = "Temperature EN:",
	[MENU_LANG_DE] = "Temperature DE:",
	[MENU_LANG_PL] = "Temperature PL:"};
//////////////////////////////////////

//Для відображення рядка температури в різних мовах
char* humidity_string[MENU_LANG_COUNT] = {
	[MENU_LANG_EN] = "Humidity EN:",
	[MENU_LANG_DE] = "Humidity DE:",
	[MENU_LANG_PL] = "Humidity PL:"};


//функції для обробки кнопки SW
///////////////////////////////////////
//функція для входу в налаштування параметрів меню//
// функция вызываеться при кратковременном нажатии на кнопку ( одиночный клик )
void attachClick_1(void){
	flag_enter_menu_value = !flag_enter_menu_value; //робить інверсію (постійно міняє значення)
	//AHT10_Initialization();
	//AHT10_SoftReset();
}


//функція для входу в робоче вікно//
// функция вызываеться при старте зажатия и удержания кнопки ( длинное зажатие )
void attachLongPressStart_1(void){
	//printf("%s \r\n", ">>LongPressStart_1");
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	flag_enter_work_space = !flag_enter_work_space;
	
	//функції для очищення екрану, ці функції не повинні крутитись в циклі
	void ST7789_Clear(void);
	ST7789_FillScreen( MENU_COLOR_FON );
	menu_draw_flag = 1;
}
///////////////////////////////////////
//об'єкт для обробки кнопки SW
oneButton bt1;


AHT10_SENSOR sensor_one, sensor_two;


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM3_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
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
	
	//присвоэння адреси функцій до об'єктів кнопок
	bt1.clickFunc = attachClick_1;
	bt1.longPressStartFunc = attachLongPressStart_1;

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
  MX_SPI1_Init();
  MX_TIM3_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

//////////////////////////////////////////////////////////////////
		
	HAL_TIM_Encoder_Start_IT( &htim3, TIM_CHANNEL_ALL );
	HAL_TIM_Base_Start_IT( &htim3 );


	// Процедура инициализации дисплея ST7789
	ST7789_Init();
		
	// установка ротации дисплея не обязательно так как по умолчанию стоит режим 1 ( всего 4 режима 1,2,3,4 )
	ST7789_rotation( 1 );
	
	HAL_StatusTypeDef result1;
			for (uint8_t i=1; i<128; i++)
 	{
 	  /*
 	   * the HAL wants a left aligned i2c address
 	   * &hi2c1 is the handle
 	   * (uint16_t)(i<<1) is the i2c address left aligned
 	   * retries 2
 	   * timeout 2
 	   */
 	  result1 = HAL_I2C_IsDeviceReady(&hi2c1, (uint16_t)(i<<1), 2, 100);
 	  if (result1 == HAL_OK)
 	  {
			ii = i;
// 		  printf("Original I2C_1 add: 0x%X	\r\n", i); // Received an ACK at that address
//		  printf("HAL I2C_1 add << 1: 0x%X	\r\n", i<<1); // Received an ACK at that address
 	  }
 	}
	
	sensor_one.current_I2C = &hi2c1;
	sensor_one.I2C_adress = (0x38 << 1);
	
	sensor_two.current_I2C = &hi2c1;
	sensor_two.I2C_adress = (0x39 << 1);
	
	AHT10_SoftReset(&sensor_one);
	HAL_Delay(20);

/////////////////////////////////////////////////////////////////
	

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
/////////////////////////////////////////////////////////////////
		//перевіряємо кнопку SW
		tickOneButton( &bt1, !HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) );
		
///////////////////////////////////////////////////////////
		AHT10_GetMeasurment(&sensor_one);
		AHT10_SetMeasurment(&sensor_one);

		temperature_value = AHT10_GetTemperature(&sensor_one);	//get temperature
		humidity_value = AHT10_GetHumidity(&sensor_one); //get humidity
		
			//Встановлення налаштувань меню
		if(menu_draw_flag && !flag_enter_work_space)
		{
			//HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			menu_draw_flag = 0;
			char buff[50] = { 0, };
			for(uint8_t i = 0; i < MENU_COUNT; i++){
					
				int8_t current_lang = CurrentMenu[MENU_LANG].current_value.current_i;
				int8_t current_value = CurrentMenu[i].current_value.current_i;
				
				sprintf(buff, "%c %-20s", menu_current == i? '>':' ', CurrentMenu[i].menu_string[current_lang]);
				ST7789_print( MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE*i), menu_current == i? MENU_COLOR_CURRENT:MENU_COLOR_OLD, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);
				
				if( CurrentMenu[i].current_type == TYPE_INT ){
					sprintf(buff, "%-15d", CurrentMenu[i].current_value.current_i);
				}
				else if( CurrentMenu[i].current_type == TYPE_FLOAT ){
					sprintf(buff, "%-15.1f", CurrentMenu[i].current_value.current_f);
				}
				else if( CurrentMenu[i].current_type == TYPE_STRING ){
					sprintf(buff, "%-15s", CurrentMenu[i].current_value_str[current_lang][current_value]);
				}
				ST7789_print( 150 + MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE*i), menu_current == i? MENU_COLOR_CURRENT:MENU_COLOR_OLD, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);
		}
	}
					
	
/////////////////Робочий стіл//////////////// 
	if(flag_enter_work_space)// доробити відображення раз в секунду через таймер
	{
		char buff[50] = { 0, };
		for(uint8_t i = 0; i <= MENU_MIN_VALUE; i++){
					
			int8_t current_lang = CurrentMenu[MENU_LANG].current_value.current_i;
			int8_t current_value = CurrentMenu[i].current_value.current_i;
				
			sprintf(buff, "%-20s", CurrentMenu[i].menu_string[current_lang]);
			ST7789_print( MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE*i), MENU_COLOR_CURRENT, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);
				
			if( CurrentMenu[i].current_type == TYPE_INT ){
				sprintf(buff, "%-15d", CurrentMenu[i].current_value.current_i);
			}
			else if( CurrentMenu[i].current_type == TYPE_FLOAT ){
				sprintf(buff, "%-15.1f", CurrentMenu[i].current_value.current_f);
			}
			else if( CurrentMenu[i].current_type == TYPE_STRING ){
				sprintf(buff, "%-15s", CurrentMenu[i].current_value_str[current_lang][current_value]);
			}
			ST7789_print( 150 + MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE*i), MENU_COLOR_CURRENT, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);
			
			
			sprintf(buff, "%-20s %-15.1f", temperature_string[current_lang], temperature_value);
			ST7789_print( MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE * TEMPERATURE_POSITION_STR), MENU_COLOR_CURRENT, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);
			sprintf(buff, "%-20s %-15.1f", humidity_string[current_lang], humidity_value);
			ST7789_print( MENU_COORD_X, MENU_COORD_Y+(MENU_COORD_OFFSIZE * (TEMPERATURE_POSITION_STR+1)), MENU_COLOR_CURRENT, MENU_COLOR_FON, 1, &Font_7x9, 1, buff);			
		}
	}	
	
/////////////////////////////////////////////////////////////////



	
	

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
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

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

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 4-1;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 15;
  sConfig.IC2Polarity = TIM_ICPOLARITY_FALLING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 15;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
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
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RST_Pin|DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RST_Pin DC_Pin */
  GPIO_InitStruct.Pin = RST_Pin|DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SW_Pin */
  GPIO_InitStruct.Pin = SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */


/////////////////////////////////////////////////////////////////////////////////////////
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if( htim->Instance == TIM3 ){	
		static uint32_t previous_time = 0;
		
		if( HAL_GetTick() - previous_time > TIMEOUT_ENCODER && !flag_enter_work_space){
			previous_time = HAL_GetTick();
			
			menu_draw_flag = 1;
			
			if( TIM3->CR1 & TIM_CR1_DIR ){
				if(!flag_enter_menu_value){	// в меню
					menu_current++;
					if(menu_current > MENU_COUNT -1)
					{
						menu_current = 0;
					}
				}
				else{ // подменю
					//для роботи з типом int або string
					if(CurrentMenu[menu_current].current_type == TYPE_INT || 
						CurrentMenu[menu_current].current_type == TYPE_STRING){
						CurrentMenu[menu_current].current_value.current_i++;
						if( CurrentMenu[menu_current].current_value.current_i > CurrentMenu[menu_current].max_value.current_i ){
							CurrentMenu[menu_current].current_value.current_i = CurrentMenu[menu_current].min_value.current_i;
					}
				}
					//для роботи з типом float
					if(CurrentMenu[menu_current].current_type == TYPE_FLOAT){
						CurrentMenu[menu_current].current_value.current_f += DEVISION_FLOAT_VAL;
						if( CurrentMenu[menu_current].current_value.current_f > CurrentMenu[menu_current].max_value.current_f ){
							CurrentMenu[menu_current].current_value.current_f = CurrentMenu[menu_current].min_value.current_f;
					}
				}
				}
	
			}
			else
			{
				if(!flag_enter_menu_value){ // в меню
					menu_current--;
					if(menu_current < 0)
					{
						menu_current = MENU_COUNT -1;
					}
				}
				else{ // подменю
					//для роботи з типом int або string
					if(CurrentMenu[menu_current].current_type == TYPE_INT || TYPE_STRING){
						CurrentMenu[menu_current].current_value.current_i--;
						if( CurrentMenu[menu_current].current_value.current_i < CurrentMenu[menu_current].min_value.current_i ){
							CurrentMenu[menu_current].current_value.current_i = CurrentMenu[menu_current].max_value.current_i;
						}
					}
					//для роботи з типом float
					if(CurrentMenu[menu_current].current_type == TYPE_FLOAT){
						CurrentMenu[menu_current].current_value.current_f -= DEVISION_FLOAT_VAL;	
						if( CurrentMenu[menu_current].current_value.current_f < CurrentMenu[menu_current].min_value.current_f ){
							CurrentMenu[menu_current].current_value.current_f = CurrentMenu[menu_current].max_value.current_f;
						}
					}
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////


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
