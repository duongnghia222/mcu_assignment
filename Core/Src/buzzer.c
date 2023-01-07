/*
 * buzzer.c
 *
 *  Created on: Dec 18, 2022
 *      Author: Minh Duc Quach
 */

#include "buzzer.h"

void FSM_Buzzer(){
	/* If Pedestrian button is pressed and the pedestrian is allowed to cross the road */
	if(FSM_Pedestrian_State == WORK && FSM_Traffic_Light_State_Row == AUTO_RED){
		switch (FSM_Buzzer_State){
		case ON:
			/* Turn on Buzzer */
			if(timer4Flag == 1){
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 999);					// set buzzer volume
				FSM_Buzzer_State = OFF;
				/* The buzzer is ON for DURATION_ON_TIME * TICK ms */
				setTimer4(DURATION_ON_TIME * TICK);
			}
			break;
		case OFF:
			if(timer4Flag == 1){
				FSM_Buzzer_State = ON;
				__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);					// turn off buzzer
				setTimer4(traffic_light_remain_time_row);							// set buzzer frequency based on time left
			}
			break;
		default:
			break;
		}

	}
	/* Other cases */
	else{
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
	}
}
