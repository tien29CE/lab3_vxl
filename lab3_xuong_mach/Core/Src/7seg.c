/*
 * 7seg.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#include "main.h"
#include "7seg.h"

void display7SEG_0(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, RESET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, SET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, SET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, SET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, SET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, RESET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, SET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, SET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, SET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, SET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, SET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, SET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, RESET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, SET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, SET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, RESET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(A_0_GPIO_Port, A_0_Pin, RESET);
			HAL_GPIO_WritePin(B_0_GPIO_Port, B_0_Pin, RESET);
			HAL_GPIO_WritePin(C_0_GPIO_Port, C_0_Pin, RESET);
			HAL_GPIO_WritePin(D_0_GPIO_Port, D_0_Pin, RESET);
			HAL_GPIO_WritePin(E_0_GPIO_Port, E_0_Pin, SET);
			HAL_GPIO_WritePin(F_0_GPIO_Port, F_0_Pin, RESET);
			HAL_GPIO_WritePin(G_0_GPIO_Port, G_0_Pin, RESET);
			break;
		default:
			break;
	}
}

void display7SEG_1(int number){
	switch(number){
		case 0:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, RESET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, SET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, SET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, SET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, SET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, RESET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, SET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, SET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, SET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, SET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, SET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, SET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, RESET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, SET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, SET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, RESET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(A_1_GPIO_Port, A_1_Pin, RESET);
			HAL_GPIO_WritePin(B_1_GPIO_Port, B_1_Pin, RESET);
			HAL_GPIO_WritePin(C_1_GPIO_Port, C_1_Pin, RESET);
			HAL_GPIO_WritePin(D_1_GPIO_Port, D_1_Pin, RESET);
			HAL_GPIO_WritePin(E_1_GPIO_Port, E_1_Pin, SET);
			HAL_GPIO_WritePin(F_1_GPIO_Port, F_1_Pin, RESET);
			HAL_GPIO_WritePin(G_1_GPIO_Port, G_1_Pin, RESET);
			break;
		default:
			break;
	}
}

void display7SEG(int number){
	display7SEG_0(number%10);
	display7SEG_1(number/10);
}
