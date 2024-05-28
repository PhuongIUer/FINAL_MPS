/*
 * fsm_man.c
 *
 *  Created on: May 28, 2024
 *      Author: MSI
 */
#include <display7seg.h>
#include <fsm_manual.h>
#include "software_timer.h"
#include "button.h"
int counter = 0;
int SecCounter = 0;
int SecCounterFlag = 0;
void wrapAroundCounter(){
	if (counter > 9) counter=0;
	if (counter < 0) counter=9;
}

void fsm_simple_buttons_run() {
    if(timer0_flag == 1) {
        setTimer0(100);
        HAL_GPIO_TogglePin(LED_RED_Port, LED_RED_Pin);
        if(SecCounterFlag == 1) {
            counter--;
            SecCounterFlag = 0;
        }

        display7SEG(counter);
        SecCounter++;

        if(SecCounter >= 10) {
            SecCounter = 0;
            SecCounterFlag = 1;
        }

        if(counter < 0) {
            counter = 9;
        }
    }
    if(is_button_pressed(0) == 1 || is_long_button_flag(0) == 1) {
        counter = 0;
    }
    if(is_button_pressed(1) == 1 || is_long_button_flag(1) == 1) {
        wrapAroundCounter(++counter);
    }
    if(is_button_pressed(2) == 1 || is_long_button_flag(2) == 1) {
        wrapAroundCounter(--counter);
    }
}

