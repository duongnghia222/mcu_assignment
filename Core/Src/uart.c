/*
 * uart.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "uart.h"

void uart_transmit(){
	switch(FSM_Traffic_Light_State_Row){
		case AUTO_RED:
		case AUTO_GREEN:
		case AUTO_YEL:
		case MANUAL_RED:
		case MANUAL_GREEN:
		case MANUAL_YEL:
			if (traffic_light_remain_time_row < 10) HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:0%d#", traffic_light_remain_time_row), 1000);
			else HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:%d#", traffic_light_remain_time_row), 1000);
			break;
		case SET_RED:
		case SET_GREEN:
		case SET_YEL:
			if (Set_TL_Time < 10) HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:0%d#", Set_TL_Time), 1000);
			else HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "!7SEG:%d#", Set_TL_Time), 1000);
			break;
		default:
			break;
	}
}
