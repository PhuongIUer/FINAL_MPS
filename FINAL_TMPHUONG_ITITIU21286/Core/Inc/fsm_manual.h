/*
 * fsm_man.h
 *
 *  Created on: May 28, 2024
 *      Author: MSI
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "stm32f1xx_hal.h"

#define LED_RED_Port GPIOA
#define LED_RED_Pin GPIO_PIN_8

void wrapAroundCounter();
void fsm_simple_buttons_run();

#endif /* INC_FSM_MANUAL_H_ */
