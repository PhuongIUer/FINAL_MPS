/*
 * control_led.h
 *
 *  Created on: May 28, 2024
 *      Author: MSI
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "stm32f1xx_hal.h" // Include the HAL header

// Define the GPIO pins
#define SEG0_Pin GPIO_PIN_1
#define SEG1_Pin GPIO_PIN_2
#define SEG2_Pin GPIO_PIN_3
#define SEG3_Pin GPIO_PIN_4
#define SEG4_Pin GPIO_PIN_5
#define SEG5_Pin GPIO_PIN_6
#define SEG6_Pin GPIO_PIN_7
#define SEG_GPIO_Port GPIOA

void display7SEG(int k);


#endif /* INC_DISPLAY7SEG_H_ */
