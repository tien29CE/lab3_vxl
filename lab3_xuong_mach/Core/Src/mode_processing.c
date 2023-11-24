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
#include "input_processing.h"
#include <stdio.h>
#include <string.h>
UART_HandleTypeDef huart2;
void clearTerminal(){
	char clr[] = "\x0C";
	HAL_UART_Transmit(&huart2, (uint8_t *)clr, sizeof(clr) - 1, HAL_MAX_DELAY);
}
void printString(const char *str){
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}
void printValue(int val){
	char str[100];
	HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d\r\n", val), HAL_MAX_DELAY);
}
void displayTLValues(){
	clearTerminal();
	switch(light_state){
	case Red_Green:
		printString("RED: ");
		printValue(horizontal_countdown);
		printString("GREEN: ");
		printValue(vertical_countdown);
		break;
	case Red_Yellow:
		printString("RED: ");
		printValue(horizontal_countdown);
		printString("AMBER: ");
		printValue(vertical_countdown);
		break;
	case Green_Red:
		printString("GREEN: ");
		printValue(horizontal_countdown);
		printString("RED: ");
		printValue(vertical_countdown);
		break;
	case Yellow_Red:
		printString("AMBER: ");
		printValue(horizontal_countdown);
		printString("RED: ");
		printValue(vertical_countdown);
		break;
	default:
		break;
	}
}

void modify_red(){
	if(timer0_flag == 1){
		HAL_GPIO_WritePin(TFL_00_GPIO_Port, TFL_00_Pin, SET);
		HAL_GPIO_WritePin(TFL_01_GPIO_Port, TFL_01_Pin, RESET);
		HAL_GPIO_WritePin(TFL_10_GPIO_Port, TFL_10_Pin, SET);
		HAL_GPIO_WritePin(TFL_11_GPIO_Port, TFL_11_Pin, RESET);
		seven_segment_state();
		setTimer0(500);
	}
}

void modify_yellow(){
	if(timer0_flag == 1){
		HAL_GPIO_WritePin(TFL_00_GPIO_Port, TFL_00_Pin, SET);
		HAL_GPIO_WritePin(TFL_01_GPIO_Port, TFL_01_Pin, SET);
		HAL_GPIO_WritePin(TFL_10_GPIO_Port, TFL_10_Pin, SET);
		HAL_GPIO_WritePin(TFL_11_GPIO_Port, TFL_11_Pin, SET);
		seven_segment_state();
		setTimer0(500);
	}
}

void modify_green(){
	if(timer0_flag == 1){
		HAL_GPIO_WritePin(TFL_00_GPIO_Port, TFL_00_Pin, RESET);
		HAL_GPIO_WritePin(TFL_01_GPIO_Port, TFL_01_Pin, SET);
		HAL_GPIO_WritePin(TFL_10_GPIO_Port, TFL_10_Pin, RESET);
		HAL_GPIO_WritePin(TFL_11_GPIO_Port, TFL_11_Pin, SET);
		seven_segment_state();
		setTimer0(500);
	}
}

void mode_processing(){
	fsm_for_input_processing();
	if(is_press_flag[0]){
		HAL_GPIO_WritePin(TFL_00_GPIO_Port, TFL_00_Pin, RESET);
		HAL_GPIO_WritePin(TFL_01_GPIO_Port, TFL_01_Pin, RESET);
		HAL_GPIO_WritePin(TFL_10_GPIO_Port, TFL_10_Pin, RESET);
		HAL_GPIO_WritePin(TFL_11_GPIO_Port, TFL_11_Pin, RESET);
		led_time_buffer[RED] =  led_time_buffer[YELLOW] = led_time_buffer[GREEN] = 0;
		if(++mode > 3){
			mode = 0;
		}
		clearTerminal();
		printString("MODE ");
		printValue(mode);
		is_press_flag[0] = 0;
	}else if(is_press_flag[1]){
		printString("INCREASE RED TIMER : ");
		switch(mode){
			case Modify_red:
				led_time_buffer[RED]++;
				printValue(led_time_buffer[RED]);
				break;
			case Modify_yellow:
				led_time_buffer[YELLOW]++;
				printValue(led_time_buffer[YELLOW]);
				break;
			case Modify_green:
				led_time_buffer[GREEN]++;
				printValue(GREEN);
				break;
			default:
				break;
		}
		is_press_flag[1] = 0;
	}else if(is_press_flag[2]){
		switch(mode){
			case Modify_red:
				led_time[RED] = led_time_buffer[RED];
                if(led_time[RED] >= (led_time[GREEN] + led_time[YELLOW])){
                    led_time[GREEN] = led_time[RED] - led_time[YELLOW];
                }
                else{
                    int half = led_time[RED] / 2;
                    int mod = led_time[RED] % 2;
                    led_time[YELLOW] = half;
                    led_time[GREEN] = half + mod;
                }
                clearTerminal();
				printString("SET RED TIMER : ");
				printValue(led_time_buffer[RED]);
				break;
			case Modify_yellow:
				led_time[YELLOW] = led_time_buffer[YELLOW];
                if(led_time[RED] >= (led_time[YELLOW] + led_time[GREEN])){
                    led_time[GREEN] = led_time[RED] - led_time[YELLOW];
                }
                else{
                    if((led_time[GREEN] + led_time[YELLOW]) <= 99){
                        led_time[RED] = led_time[GREEN] + led_time[YELLOW];
                    }
                    else{
                        led_time[RED] = 99;
                        led_time[GREEN] = led_time[RED] - led_time[YELLOW];
                    }
                }
                clearTerminal();
				printString("SET YELLOW TIMER : ");
				printValue(led_time_buffer[YELLOW]);
				break;
			case Modify_green:
				led_time[GREEN] = led_time_buffer[GREEN];
                if(led_time[RED] >= (led_time[GREEN] + led_time[YELLOW])){
                    led_time[YELLOW] = led_time[RED] - led_time[GREEN];
                }
                else{
                    if((led_time[YELLOW] + led_time[GREEN]) <= 99){
                        led_time[RED] = led_time[YELLOW] + led_time[GREEN];
                    }
                    else{
                        led_time[RED] = 99;
                        led_time[YELLOW] = led_time[RED] - led_time[GREEN];
                    }
                }
                clearTerminal();
				printString("SET GREEN TIMER : ");
				printValue(led_time_buffer[GREEN]);
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
				displayTLValues();
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
