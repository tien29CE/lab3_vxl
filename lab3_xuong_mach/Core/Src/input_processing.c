/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#include <software_timer.h>
#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "normal_mode.h"
#include "mode_processing.h"

enum ButtonState_0 { BUTTON_RELEASED_0, BUTTON_PRESSED_0, BUTTON_PRESSED_MORE_THAN_1_SECOND_0 };
enum ButtonState_0 buttonState_0 = BUTTON_RELEASED_0;
enum ButtonState_1 { BUTTON_RELEASED_1, BUTTON_PRESSED_1, BUTTON_PRESSED_MORE_THAN_1_SECOND_1 };
enum ButtonState_1 buttonState_1 = BUTTON_RELEASED_1;
enum ButtonState_2 { BUTTON_RELEASED_2, BUTTON_PRESSED_2, BUTTON_PRESSED_MORE_THAN_1_SECOND_2 };
enum ButtonState_2 buttonState_2 = BUTTON_RELEASED_2;

enum LightState light_state = Red_Green;
int mode_and_time = 0;
enum NO_OF_MODES mode = Normal_mode;

int is_press_flag[N0_OF_BUTTONS] = {0, 0, 0};

void fsm_for_input_processing(void) {
	switch(buttonState_0){
		case BUTTON_RELEASED_0:
			if(is_button_pressed(0)){
				buttonState_0 = BUTTON_PRESSED_0;
				is_press_flag[0] = 1;
			}
				// INCREASE VALUE OF PORT A BY ONE UNIT
			break;
		case BUTTON_PRESSED_0:
			if (!is_button_pressed(0)){
				buttonState_0 = BUTTON_RELEASED_0;
				is_press_flag[0] = 0;
			}else{
				if(is_button_pressed_1s(0)){
					buttonState_0 = BUTTON_PRESSED_MORE_THAN_1_SECOND_0;
					is_press_flag[0] = 1;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND_0:
			if (!is_button_pressed(0)){
				buttonState_0 = BUTTON_RELEASED_0;
				is_press_flag[0] = 0;
			}
			// TODO
			break;
	}
	switch(buttonState_1){
		case BUTTON_RELEASED_1:
			if(is_button_pressed(1)){
				buttonState_1 = BUTTON_PRESSED_1;
				is_press_flag[1] = 1;
			}
				// INCREASE VALUE OF PORT A BY ONE UNIT
			break;
		case BUTTON_PRESSED_1:
			if (!is_button_pressed(1)){
				buttonState_1 = BUTTON_RELEASED_1;
				is_press_flag[1] = 0;
			}else{
				if(is_button_pressed_1s(1)){
					buttonState_1 = BUTTON_PRESSED_MORE_THAN_1_SECOND_1;
					is_press_flag[1] = 1;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND_1:
			if (!is_button_pressed(1)){
				buttonState_1 = BUTTON_RELEASED_1;
				is_press_flag[1] = 0;
			}
			// TODO
			break;
	}
	switch(buttonState_2){
		case BUTTON_RELEASED_2:
			if(is_button_pressed(2)){
				buttonState_2 = BUTTON_PRESSED_2;
				is_press_flag[2] = 1;
			}
				// INCREASE VALUE OF PORT A BY ONE UNIT
			break;
		case BUTTON_PRESSED_2:
			if (!is_button_pressed(2)){
				buttonState_2 = BUTTON_RELEASED_2;
				is_press_flag[2] = 0;
			}else{
				if(is_button_pressed_1s(2)){
					buttonState_2 = BUTTON_PRESSED_MORE_THAN_1_SECOND_2;
					is_press_flag[2] = 1;
				}
			}
			break;
		case BUTTON_PRESSED_MORE_THAN_1_SECOND_2:
			if (!is_button_pressed(2)){
				buttonState_2 = BUTTON_RELEASED_2;
				is_press_flag[2] = 0;
			}
			// TODO
			break;
	}
}
