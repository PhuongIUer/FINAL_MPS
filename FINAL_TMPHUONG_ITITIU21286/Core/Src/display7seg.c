/*
 * control_led.c
 *
 *  Created on: May 28, 2024
 *      Author: MSI
 */


#include <display7seg.h>
void display7SEG(int digit) {
    int segmentPatterns[10][7] = {
    		{0, 0, 0, 0, 0, 0, 1}, // 0
    		{1, 0, 0, 1, 1, 1, 1}, // 1
    		{0, 0, 1, 0, 0, 1, 0}, // 2
    		{0, 0, 0, 0, 1, 1, 0}, // 3
    		{1, 0, 0, 1, 1, 0, 0}, // 4
    		{0, 1, 0, 0, 1, 0, 0}, // 5
    		{0, 1, 0, 0, 0, 0, 0}, // 6
    		{0, 0, 0, 1, 1, 1, 1}, // 7
    		{0, 0, 0, 0, 0, 0, 0}, // 8
    		{0, 0, 0, 0, 1, 0, 0}  // 9
    };
    uint16_t segmentPins[7] = {SEG0_Pin,SEG1_Pin,SEG2_Pin,SEG3_Pin,SEG4_Pin,SEG5_Pin,SEG6_Pin};

    for (int i = 0 ; i<7; i++){
    				 HAL_GPIO_WritePin(SEG_GPIO_Port, segmentPins[i], segmentPatterns[digit][i]);
    			}
}

