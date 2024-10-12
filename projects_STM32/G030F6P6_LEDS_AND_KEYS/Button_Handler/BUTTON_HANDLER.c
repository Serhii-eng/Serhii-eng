/* Includes -----------------------------------------------------*/

#include "BUTTON_HANDLER.h"



/* Declaration and definitions ----------------------------------*/

//Configuration

static McuPin buttons[BUTTONS_NUM] = { /////////заповнити кнопки до кінця////////////
		{KEY_0_GPIO_Port, KEY_0_Pin},
		{KEY_1_GPIO_Port, KEY_1_Pin},
		{KEY_2_GPIO_Port, KEY_2_Pin},
		{KEY_3_GPIO_Port, KEY_3_Pin},
		{KEY_4_GPIO_Port, KEY_4_Pin}
};

//End of configuration
																		 
																		 
static uint16_t debounceCounter[BUTTONS_NUM];
static uint8_t waitButtonRelease[BUTTONS_NUM];
static uint16_t buttonPressCounter[BUTTONS_NUM];
																		 
static ButtonAction buttonActions[BUTTONS_NUM];
static ButtonMode buttonMode[BUTTONS_NUM];				//режим роботи кнопки: по фронту один раз, по спаду один раз і по фронту постійне спрацювання
static ButtonState buttonState[BUTTONS_NUM];


/* Function -----------------------------------------------------*/																		 

void BUTTON_Low_LevelManager()
{
	uint8_t currentStates[BUTTONS_NUM];
	
	for(uint8_t i = 0; i < BUTTONS_NUM; i++)
	{
		currentStates[i] = HAL_GPIO_ReadPin(buttons[i].port, buttons[i].pin);
		
		switch (buttonState[i])
		{
			case BUTTON_STARTING:
				if(currentStates[i] == GPIO_BUTTON_NOT_PRESSED)
				{
					buttonState[i] = BUTTON_NOT_PRESSED;
				}
				break;
				
			case BUTTON_NOT_PRESSED:
				if(currentStates[i] == GPIO_BUTTON_PRESSED)
				{
					buttonState[i] = BUTTON_WAIT_DEBOUNCE;
					debounceCounter[i] = 0;
				}
				break;
				
			case BUTTON_WAIT_DEBOUNCE:
				if(debounceCounter[i] == DEBOUNCE_TIME_MS)
				{
					if(currentStates[i] == GPIO_BUTTON_PRESSED)
					{
						buttonState[i] = BUTTON_PRESSED;
					}
					else
					{
						buttonState[i] = BUTTON_NOT_PRESSED;
					}
				}
				break;
				
			case BUTTON_PRESSED:
				if(currentStates[i] == GPIO_BUTTON_NOT_PRESSED)
				{
					buttonState[i] = BUTTON_WAIT_DEBOUNCE;
					debounceCounter[i] = 0;
				}
				break;
				
			default:
				break;			
		}		
	}
}


void BUTTON_HighLevelManager()
{
	for(uint8_t i = 0; i < BUTTONS_NUM; i++)
	{
		if(buttonActions[i] == BUTTON_NONE)//перевірити що відбувається другий раз як заходим і кнопка натиснена
		{
			if(waitButtonRelease[i] == 0)
			{
				if(buttonState[i] == BUTTON_PRESSED)
				{
					waitButtonRelease[i] = 1;
				}
			}
			else
			{
				switch (buttonMode[i])
				{

					//////////////////////////////////////////////
					case TRIG_FALL_ONE_TIME:
					
						if(buttonState[i] == BUTTON_NOT_PRESSED)
						{
							waitButtonRelease[i] = 0;
							
							if(buttonPressCounter[i] >= BUTTONS_VERY_LONG_PRESS_MS)
							{
								buttonActions[i] = BUTTON_VERY_LONG_PRESS;
							}
							else
							{
								if(buttonPressCounter[i] >= BUTTONS_LONG_PRESS_MS)
								{
									buttonActions[i] = BUTTON_LONG_PRESS;
								}
								else
								{
									buttonActions[i] = BUTTON_SHORT_PRESS;
								}
							}
						}
					
					break;
					//////////////////////////////////////////////
						
					//////////////////////////////////////////////
					case TRIG_RISE_ONE_TIME:
				
						//waitButtonRelease[i] = 0;
						if(buttonState[i] == BUTTON_NOT_PRESSED)////////
						{
							waitButtonRelease[i] = 0;
						}
						
						if(buttonPressCounter[i] >= BUTTONS_VERY_LONG_PRESS_MS && waitButtonRelease[i] == BUTTON_VERY_LONG_PRESS)
						{
							buttonActions[i] = BUTTON_VERY_LONG_PRESS;
							waitButtonRelease[i] = BUTTON_SHORT_PRESS;
						}
						else
						{
							if(buttonPressCounter[i] >= BUTTONS_LONG_PRESS_MS && waitButtonRelease[i] == BUTTON_LONG_PRESS)
							{
								buttonActions[i] = BUTTON_LONG_PRESS;
								waitButtonRelease[i] = BUTTON_VERY_LONG_PRESS;
							}
							else
							{
								if(buttonPressCounter[i] < BUTTONS_LONG_PRESS_MS && waitButtonRelease[i] == BUTTON_SHORT_PRESS)
								{
									buttonActions[i] = BUTTON_SHORT_PRESS;
									waitButtonRelease[i] = BUTTON_LONG_PRESS;
								}
							}
						}
	
					break;
					//////////////////////////////////////////////
							
					//////////////////////////////////////////////Кейс TRIG_RISE_FRIQUENTLY працює тільки з режимом BUTTON_SHORT_PRESS
					case TRIG_RISE_FRIQUENTLY:
					
						waitButtonRelease[i] = 0;
						buttonActions[i] = BUTTON_SHORT_PRESS;
		
					break;
					//////////////////////////////////////////////
							
					default:
						break;
				}
			}
		}
	}
}

void BUTTON_Process()
{
	BUTTON_Low_LevelManager();
	BUTTON_HighLevelManager();
}


//функція для роботи з таймером або з перериванням в файлі stm32f4xx_it.c і функції void SysTick_Handler(void)
void BUTTON_TimerProcess()
{
  for (uint8_t i = 0; i < BUTTONS_NUM; i++)
  {
    if (debounceCounter[i] < DEBOUNCE_TIME_MS)
    {
      debounceCounter[i]++;
    }

    if (waitButtonRelease[i] >= 1)
    {
      buttonPressCounter[i]++;
    }
    else
    {
      buttonPressCounter[i] = 0;
    }
  }
}


//функція повертає статус кнопки
ButtonAction BUTTON_GetAction(uint8_t index, uint8_t mode)
{
	buttonMode[index] = mode;
	return buttonActions[index];
}


void BUTTON_ResetActions()
{
	for(uint8_t i = 0; i < BUTTONS_NUM; i++)
	{
		buttonActions[i] = BUTTON_NONE;
	}
}


void BUTTON_Init()
{
	for(uint8_t i = 0; i < BUTTONS_NUM; i++)
	{
		debounceCounter[i] = 0;
		waitButtonRelease[i] = 0;
		buttonPressCounter[i] = 0;
		buttonActions[i] = BUTTON_NONE;
		buttonState[i] = BUTTON_STARTING;
		buttonMode[i] = TRIG_NOT_SELECTED;
	}
}


















