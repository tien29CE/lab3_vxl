/*
 * normal_mode.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Admin
 */
#include "main.h"
#include "7seg.h"
#include "normal_mode.h"
#include "mode_processing.h"

int led_time[3] = {5, 2, 3};
int led_time_buffer[3] = {0, 0, 0};
int horizontal_countdown = 0;
int vertical_countdown = 0;
int hori_verti_state = HORI;

void seven_segment_state(void){
	if(mode != Normal_mode){
		if(mode_and_time == 0){
			switch(mode){
				case Modify_red:
					display7SEG(led_time_buffer[RED]);
					break;
				case Modify_yellow:
					display7SEG(led_time_buffer[YELLOW]);
					break;
				case Modify_green:
					display7SEG(led_time_buffer[GREEN]);
					break;
				default:
					break;
			}
			HAL_GPIO_WritePin(GPIOB, EN_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, EN_1_Pin, SET);
			mode_and_time = 1;
		}else{
			display7SEG(mode);
			HAL_GPIO_WritePin(GPIOB, EN_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, EN_1_Pin, RESET);
			mode_and_time = 0;
		}
	}else{
		switch(hori_verti_state){
			case HORI:
				display7SEG(horizontal_countdown);
				HAL_GPIO_WritePin(GPIOB, EN_0_Pin, RESET);
				HAL_GPIO_WritePin(GPIOB, EN_1_Pin, SET);
				hori_verti_state = VERTI;
				break;
			case VERTI:
				display7SEG(vertical_countdown);
				HAL_GPIO_WritePin(GPIOB, EN_0_Pin, SET);
				HAL_GPIO_WritePin(GPIOB, EN_1_Pin, RESET);
				hori_verti_state = HORI;
				break;
			default:
				break;
		}
	}
}

void traffic_light(void){
	seven_segment_state();
	switch(light_state){
		case Init:
			HAL_GPIO_WritePin(GPIOB, RED_0_Pin|YELLOW_0_Pin|GREEN_0_Pin|RED_1_Pin|YELLOW_1_Pin|GREEN_1_Pin, RESET);
			horizontal_countdown = led_time[RED];
			vertical_countdown = led_time[GREEN];
			light_state = Red_Green;
			break;
		case Red_Green:
			horizontal_countdown--;
			vertical_countdown--;
			HAL_GPIO_WritePin(GPIOB, RED_0_Pin|GREEN_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin|GREEN_0_Pin|RED_1_Pin|YELLOW_1_Pin, SET);
			if(vertical_countdown <= 0){
				 light_state = Red_Yellow;
				 vertical_countdown = led_time[YELLOW];
			}
			break;
		case Red_Yellow:
			horizontal_countdown--;
			vertical_countdown--;
			HAL_GPIO_WritePin(GPIOB, RED_0_Pin|YELLOW_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin|GREEN_0_Pin|RED_1_Pin|GREEN_1_Pin, SET);
			if(horizontal_countdown <= 0){
				 light_state = Green_Red;
				 horizontal_countdown = led_time[GREEN];
				 vertical_countdown = led_time[RED];
			}
			break;
		case Green_Red:
			horizontal_countdown--;
			vertical_countdown--;
			HAL_GPIO_WritePin(GPIOB, GREEN_0_Pin|RED_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin|GREEN_1_Pin|RED_0_Pin|YELLOW_1_Pin, SET);
			if(horizontal_countdown <= 0){
				 light_state = Yellow_Red;
				 horizontal_countdown = led_time[YELLOW];
			}
			break;
		case Yellow_Red:
			horizontal_countdown--;
			vertical_countdown--;
			HAL_GPIO_WritePin(GPIOB, YELLOW_0_Pin|RED_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, RED_0_Pin|YELLOW_1_Pin|GREEN_0_Pin|GREEN_1_Pin, SET);
			if(horizontal_countdown <= 0){
				 light_state = Red_Green;
				 horizontal_countdown = led_time[RED];
				 vertical_countdown = led_time[GREEN];
			}
			break;
		default:
			break;
	}
}

