/*
 * button.c
 *
 *  Created on: May 27, 2024
 *      Author: MSI
 */

#include "button.h"

#define TIME_FOR_LONG_KEY 25
#define TIME_FOR_PRESS_KEY 200
#define NUM_BUTTONS 3

int KeyRegister0[NUM_BUTTONS] = {SET};
int KeyRegister1[NUM_BUTTONS] = {SET};
int KeyRegister2[NUM_BUTTONS] = {SET};
int KeyRegister3[NUM_BUTTONS] = {SET};
int TOkeyPress = TIME_FOR_PRESS_KEY;
int TOForLongKeyPress = TIME_FOR_LONG_KEY;
int button_flag[NUM_BUTTONS] = {RESET};
int button_flag_1s[NUM_BUTTONS] = {RESET};
int long_button_flag[NUM_BUTTONS] = {RESET};

int is_button_pressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	button_flag[index] = 1;

}
int is_long_button_flag(int index) {
	if (long_button_flag[index] == 1) {
		long_button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput() {
    for (int i = 0; i < 3; i++) {
        KeyRegister2[i] = KeyRegister1[i];
        KeyRegister1[i] = KeyRegister0[i];

        switch (i) {
            case 0:
                KeyRegister0[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
                break;
            case 1:
                KeyRegister0[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
                break;
            case 2:
                KeyRegister0[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
                break;
            default:
                break;
        }

        if ((KeyRegister1[i] == KeyRegister0[i]) && (KeyRegister1[i] == KeyRegister2[i])) {
            if (KeyRegister2[i] != KeyRegister3[i]) {
                KeyRegister3[i] = KeyRegister2[i];

                if (KeyRegister3[i] == PRESSED_STATE) {
                    subKeyProcess(i);
                }
            } else {
                TOkeyPress--;

                if (TOkeyPress == 0) {
                    if (KeyRegister2[i] == PRESSED_STATE) {
                        TOkeyPress = TIME_FOR_PRESS_KEY;
                        button_flag_1s[i] = 1;
                    }
                }

                if ((button_flag_1s[i] == 1)) {
                    TOForLongKeyPress--;

                    if (TOForLongKeyPress == 0) {
                        long_button_flag[i] = 1;
                        TOForLongKeyPress = TIME_FOR_LONG_KEY;
                    }
                }
            }
        } else {
            button_flag_1s[i] = 0;
            TOkeyPress = TIME_FOR_PRESS_KEY;
        }
    }
}

