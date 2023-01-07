/*
 * global.c
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */

#include "global.h"

////////////////BUTTON/////////////////////
uint8_t buttonPressed_flag[NO_OF_BUTTONS] = {0,0,0,0};
uint16_t INPUT_BUTTON[NO_OF_BUTTONS] = {BUTTON_MOD_Pin, BUTTON_IC_Pin, BUTTON_SET_Pin, BUTTON_PEDE_Pin};
/////////////////FSM//////////////////////
int FSM_Button_State = NORMAL_BUTTON;
int FSM_Traffic_Light_State_Row = AUTO_RED;
int FSM_Traffic_Light_State_Col = AUTO_GREEN;
int FSM_Pedestrian_State = IDLE;
////////////////Buzzer////////////////////
int FSM_Buzzer_State = OFF;
int Increase_Duty_Cycle = 99;
int Increase_Speed = 5;
////////////////Timer/////////////////////
int timer1Counter = 0;
int timer1Flag = 0;
int timer2Counter = 0;
int timer2Flag = 0;
int timer3Counter = 0;
int timer3Flag = 0;
int timer4Counter = 0;
int timer4Flag = 0;
////////////Light time////////////////////
int red_time = 5;
int green_time = 3;
int yellow_time = 2;
int traffic_light_remain_time_row = 5;
int traffic_light_remain_time_col = 3;
int Set_TL_Time = 0;
////////////Pedestrian mode time////////////////////
int TIMER3_PEDESTRIAN_CYCLE = 1000;
