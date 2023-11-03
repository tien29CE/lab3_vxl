/*
 * software_timer.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Admin
 */

#define TIME_CYCLE 	10

int timer0_counter = 1;
int timer0_flag = 0;

void setTimer0(int duration){
	timer0_counter = duration/TIME_CYCLE;
	timer0_flag = 0;
}

void timerRun(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter <= 0){
			timer0_flag = 1;
		}
	}
}
