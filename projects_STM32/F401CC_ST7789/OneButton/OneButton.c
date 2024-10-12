/*

  ******************************************************************************
  * @file 			( фаил ):   OneButton..c
  * @brief 		( описание ):  	обработка нажатия кнопок
  ******************************************************************************
  * @attention 	( внимание ):	для получения текущего кол-ва миллисекунд
								прошедших со старта MCU исползуем HAL_GetTick()
  ******************************************************************************
  
*/

/* Includes ----------------------------------------------------------*/

#include "OneButton.h"

	uint32_t debounceTicks = DEBOUNCE_TICKS; 	// количество тиков за время отката.
	uint16_t clickTicks = CLICK_TICKS;  		// количество тактов, которые должны пройти, прежде чем будет обнаружен клик.
	uint16_t pressTicks = PRESS_TICKS; 			// количество тиков, которые должны пройти, прежде чем будет обнаружено долгое нажатие кнопки


/*
	******************************************************************************
	* @brief	 ( описание ):  функция которую вызываем постоянно в while(1)
	* @param	( параметры ):	первый ссылка на обьявленую структуру ( псевдо объект )
								второй логическое значение кнопки ( чтение пина кнопки )
								при истене считает что кнопка нажата при ложь кнопка не нажата
	* @return  ( возвращает ):	
	******************************************************************************
*/
void tickOneButton(oneButton *button, uint8_t activeLevel)
{
	uint32_t now = HAL_GetTick();	// текущее (относительное) время в мсек.
	
	  if (button->state == 0) { // ожидание нажатия кнопки меню.
				if (activeLevel) {
				  button->state = 1; // шаг, чтобы заявить 1
				  button->startTime = now; // помните время начала
				} // end if
	  } 
	  else if (button->state == 1) { // ожидание выхода из меню.

				if ((!activeLevel) && ((uint32_t)(now - button->startTime) < debounceTicks)) {
				  // кнопка была отпущена для быстрого, поэтому я предполагаю, что отмена.
				  // возвращаемся в состояние 0 без вызова функции
				  button->state = 0;
				} 
				else if (!activeLevel) {
				  button->state = 2; // шаг, чтобы заявить 2
					button->stopTime = now; // помните время конца
				}
				else if ((activeLevel) && ((uint32_t)(now - button->startTime) > pressTicks)) {
				  button->isLongPressed = 1; 

					// функция старта длинного нажатия (вызываеться когда только зажали кнопку на длительное зажатие )
				  if (button->longPressStartFunc){
						(*button).longPressStartFunc();
				  }
				  // функция при длинном нажатии ( вызываеться когда удерживаем нажатой кнопку долго )
				  if (button->duringLongPressFunc){
					(*button).duringLongPressFunc();
				  }
				  button->state = 6; // шаг, чтобы заявить 6
				  button->stopTime = now; // помните время конца
				} 
				else {
				  // ждать. Оставайтесь в этом состоянии.
				} // end if
	  } 
	  else if (button->state == 2) {
		// ожидание нажатия кнопки меню во второй раз или тайм-аут.
				if (button->doubleClickFunc == NULL || (uint32_t)(now - button->startTime) > clickTicks) {
					// функция вызываеться при кратковременном нажатии
					  if (button->clickFunc){
							(*button).clickFunc();
					  }
					button->state = 0; // restart.
				} 
				else if ((activeLevel) && ((uint32_t)(now - button->stopTime) > debounceTicks)) {
					button->state = 3; // шаг, чтобы заявить 3
					button->startTime = now; // помните время начала
				} // end if
	  }
	  else if (button->state == 3) { // в ожидании, наконец, будет выпущен вывод меню.		
				// Оставайтесь здесь хотя бы для _debounceTicks, потому что иначе мы можем оказаться в
				// состояние 1, если кнопка слишком долго отскакивает.
				if ((!activeLevel) && ((uint32_t)(now - button->startTime) > debounceTicks)) {
					// функция вызываеться при двойном нажатии ( два кратковременных щелчка )
				  if (button->doubleClickFunc){
						(*button).doubleClickFunc();
				  }
				  button->state = 0; // restart.
				  button->stopTime = now; // помните время конца
				} // end if
	  } 
	  else if (button->state == 6) {
		// ожидание выхода из меню после долгого нажатия.
				if (!activeLevel) {
					  button->isLongPressed = 0; 
					// функция вызываеться при окончании длительного нажатия
					  if (button->longPressStopFunc){
							(*button).longPressStopFunc();
					  }
					button->state = 0; // restart.
					button->stopTime = now; // помните время конца
				} 
				else {
					  // кнопка долго нажата
					  button->isLongPressed = 1; 
					// функция при длинном нажатии ( вызываеться когда удерживаем нажатой кнопку долго )
					  if (button->duringLongPressFunc){
							(*button).duringLongPressFunc();
					  }
				} // end if
	  } // end if
} // end tick()

/************************ (C) COPYRIGHT GKP *****END OF FILE****/
