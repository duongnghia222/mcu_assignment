/*
 * global.h
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button_reading.h"
#include "fsm_traffic_light.h"
#include "timer.h"
#include "display_traffic_light.h"
#include "fsm_pedestrian.h"
#include "stdlib.h"
#include <stdio.h>
#include "string.h"
#include "buzzer.h"
#include "uart.h"

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart2;

char str[30];


//////////////BUTTON///////////////////
#define NO_OF_BUTTONS		4
uint16_t INPUT_BUTTON[NO_OF_BUTTONS];
uint8_t buttonPressed_flag[NO_OF_BUTTONS];

#define NORMAL_BUTTON 		0
#define PRESS_BUTTON 		1
#define LONG_PRESS_BUTTON 	2

//////////////FSM//////////////////////
int FSM_Button_State;
int FSM_Traffic_Light_State_Row;
int FSM_Traffic_Light_State_Col;
int FSM_Pedestrian_State;
#define AUTO_RED		0
#define AUTO_GREEN		1
#define AUTO_YEL		2
#define MANUAL_RED		3
#define MANUAL_GREEN 	4
#define MANUAL_YEL 		5
#define BLACK_HOLE		6
#define SET_RED			7
#define SET_GREEN		8
#define SET_YEL			9
#define IDLE			0
#define WORK			1
////////////////Buzzer//////////////////
int FSM_Buzzer_State;
int Increase_Duty_Cycle;
int Increase_Speed;
#define ON	1
#define OFF 0
#define DURATION_ON_TIME 10 //buzzer on in 100ms
////////////////Timer//////////////////
#define TICK	1
int timer1Counter;
int timer1Flag;
int timer2Counter;
int timer2Flag;
int timer3Counter;
int timer3Flag;
int timer4Counter;
int timer4Flag;
int timer5Counter;
int timer5Flag;
///////////////Light time////////////////

int red_time;
int green_time;
int yellow_time;

int traffic_light_remain_time_row;
int traffic_light_remain_time_col;

int TIMER3_PEDESTRIAN_CYCLE;

#define TIMER1_SECOND_DURATION 		100  // 1s
#define TIMER1_10SECOND_DURATION 	1000 // 10s
//#define TIMER3_PEDESTRIAN_CYCLE 	1000 // 10s
int Set_TL_Time;
#endif /* INC_GLOBAL_H_ */
