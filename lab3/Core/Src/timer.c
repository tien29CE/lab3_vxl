/*
 * timer.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#include <software_timer.h>
#include "main.h"
#include "input_reading.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim -> Instance == TIM2) {
		button_reading();
		timerRun();
	}
}

