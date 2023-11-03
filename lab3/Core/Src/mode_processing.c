/*
 * mode_processing.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Admin
 */

#include <software_timer.h>
#include "main.h"
#include "normal_mode.h"
#include "mode_processing.h"
#include "input_reading.h"
#include "7seg.h"
#include "input_processing.h"

void modify_red(){
	if(timer0_flag == 1){
		HAL_GPIO_TogglePin(RED_0_GPIO_Port, RED_0_Pin|RED_1_Pin);
		seven_segment_state();
		setTimer0(500);
	}
}

void modify_yellow(){
	if(timer0_flag == 1){
		HAL_GPIO_TogglePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin|YELLOW_1_Pin);
		seven_segment_state();
		setTimer0(500);
	}
}

void modify_green(){
	if(timer0_flag == 1){
		HAL_GPIO_TogglePin(GREEN_0_GPIO_Port, GREEN_0_Pin|GREEN_1_Pin);
		seven_segment_state();
		setTimer0(500);
	}
}

void mode_processing(){
	fsm_for_input_processing();
	if(is_press_flag[0]){
		HAL_GPIO_WritePin(GPIOB, RED_0_Pin|RED_1_Pin|YELLOW_0_Pin|YELLOW_1_Pin|GREEN_0_Pin|GREEN_1_Pin, SET);
		led_time_buffer[RED] =  led_time_buffer[YELLOW] = led_time_buffer[GREEN] = 0;
		if(++mode > 3){
			mode = 0;
		}
		is_press_flag[0] = 0;
	}else if(is_press_flag[1]){
		switch(mode){
			case Modify_red:
				led_time_buffer[RED]++;
				break;
			case Modify_yellow:
				led_time_buffer[YELLOW]++;
				break;
			case Modify_green:
				led_time_buffer[GREEN]++;
				break;
			default:
				break;
		}
		is_press_flag[1] = 0;
	}else if(is_press_flag[2]){
		switch(mode){
			case Modify_red:
				led_time[RED] = led_time_buffer[RED];
				break;
			case Modify_yellow:
				led_time[YELLOW] = led_time_buffer[YELLOW];
				break;
			case Modify_green:
				led_time[GREEN] = led_time_buffer[GREEN];
				break;
			default:
				break;
		}
		is_press_flag[2] = 0;
	}
	switch(mode){
		case Normal_mode:
			if(timer0_flag == 1){
				setTimer0(1000);
				traffic_light();
			}
			break;
		case Modify_red:
			modify_red();
			break;
		case Modify_yellow:
			modify_yellow();
			break;
		case Modify_green:
			modify_green();
			break;
		default:
			break;
	}
}
