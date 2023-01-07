 /*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 18, 2022
 *      Author: duchu
 */

#include "fsm_pedestrian.h"

void FSM_Pedestrian(){
    switch(FSM_Pedestrian_State){
    /* IDLE MODE */
    case IDLE:
    	/* RESET PEDESTRIAN LIGHT */
        HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, RESET);
        HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, RESET);
        /* PEDESTRIAN BUTTON IS PRESSED --> WORK MODE */
        if(buttonPressed_flag[3]){
            buttonPressed_flag[3] = 0;
            FSM_Pedestrian_State = WORK;
            FSM_Buzzer_State = ON;
            setTimer4(1*TICK);									// buzzer timer
            setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);		// pedestrian mode timer, set to 2 cycles of RED + YELLOW + GREEN
        }
        break;

    /* WORK MODE */
    case WORK:
        if(timer3Flag == 1 || FSM_Traffic_Light_State_Row == SET_GREEN
        	|| FSM_Traffic_Light_State_Row == SET_RED || FSM_Traffic_Light_State_Row == SET_YEL
			|| FSM_Traffic_Light_State_Row == MANUAL_RED || FSM_Traffic_Light_State_Row == MANUAL_YEL
			|| FSM_Traffic_Light_State_Row == MANUAL_GREEN){	// 2 cycles passed without pressing the button or MODE changed to SET or MANUAL
            FSM_Pedestrian_State = IDLE;
            break;
        }
        if(buttonPressed_flag[3]){	// the button is pressed before timeout
            setTimer3(2 * TIMER3_PEDESTRIAN_CYCLE * TICK);
        }
        /* Turn on Pedestrian Light */
        switch (FSM_Traffic_Light_State_Col){
        case AUTO_RED:
            HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
            HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, RESET);
            break;
        case AUTO_GREEN:
            HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, RESET);
            HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
            break;
        case AUTO_YEL:
            HAL_GPIO_WritePin(PEDE_SIGNAL1_GPIO_Port, PEDE_SIGNAL1_Pin, SET);
            HAL_GPIO_WritePin(PEDE_SIGNAL2_GPIO_Port, PEDE_SIGNAL2_Pin, SET);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
