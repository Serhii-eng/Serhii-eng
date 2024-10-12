
#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H


/* C++ detection */
#ifdef __cplusplus
extern C {
#endif


/* Includes -----------------------------------------------------*/
#include "main.h"


/* Declarations and definitions ---------------------------------*/

//Configuration

#define GPIO_BUTTON_NOT_PRESSED						(GPIO_PIN_SET)

#define BUTTONS_LONG_PRESS_MS							500
#define BUTTONS_VERY_LONG_PRESS_MS				3000

typedef enum {
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	BUTTONS_NUM,
} Button_ID;
	
//End of configuration	


#define DEBOUNCE_TIME_MS 						100
#define GPIO_BUTTON_PRESSED					(!GPIO_BUTTON_NOT_PRESSED)

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
} McuPin;

typedef enum
{
	BUTTON_STARTING								= 0,
	BUTTON_NOT_PRESSED						= 1,
	BUTTON_WAIT_DEBOUNCE					= 2,
	BUTTON_PRESSED								= 3,
} ButtonState;


typedef enum
{
	BUTTON_NONE										= 0,
	BUTTON_SHORT_PRESS						= 1,
	BUTTON_LONG_PRESS							= 2,
	BUTTON_VERY_LONG_PRESS				= 3,
} ButtonAction;


typedef enum
{
	TRIG_NOT_SELECTED						= 0,
	TRIG_FALL_ONE_TIME					= 1,
	TRIG_RISE_ONE_TIME					= 2,
	TRIG_RISE_FRIQUENTLY				= 3,
} ButtonMode;


/* Functions ----------------------------------------------------*/

extern void BUTTON_Process();
extern void BUTTON_TimerProcess();
extern ButtonAction BUTTON_GetAction(uint8_t index, uint8_t mode);
extern void BUTTON_ResetActions();
extern void BUTTON_Init();


//typedef enum
//{
//	BUTTON_NONE										= 0,
//	BUTTON_SHORT_PRESS						= 1,
//	BUTTON_LONG_PRESS							= 2,
//	BUTTON_VERY_LONG_PRESS				= 3,
//} ButtonAction;


/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif //ifndef	BUTTON_HANDLER_H
