/*
 * button_reading.c
 *
 *  Created on: Dec 7, 2022
 *      Author: LENOVO
 */


#include "button_reading.h"
static GPIO_PinState Reg3[NO_OF_BUTTONS];
static GPIO_PinState Reg0[NO_OF_BUTTONS];
static GPIO_PinState Reg1[NO_OF_BUTTONS];
static GPIO_PinState Reg2[NO_OF_BUTTONS];
/* Set time out */
int TimerForKeyPress = 300;
/* Read input then set button flag */
void button_reading(){
    for(int i = 0; i < NO_OF_BUTTONS; i++){
        Reg2[i] = Reg1[i];
        Reg1[i] = Reg0[i];
        Reg0[i] = HAL_GPIO_ReadPin(GPIOA, INPUT_BUTTON[i]);
        if(i <= 1){
            Reg0[i] = HAL_GPIO_ReadPin(GPIOA, INPUT_BUTTON[i]);
        }
        else if(i == 2){
            Reg0[i] = HAL_GPIO_ReadPin(GPIOB, INPUT_BUTTON[i]);
        }
        else{
            Reg0[i] = HAL_GPIO_ReadPin(GPIOA, INPUT_BUTTON[i]);
        }
        /* Check stable state */
        if((Reg0[i] == Reg1[i]) && (Reg1[i] == Reg2[i])){
            if(Reg3[i] != Reg2[i]){
                Reg3[i] = Reg2[i];
                if(Reg2[i] == PRESSED){
                    /* Button is pressed set flag */
                    buttonPressed_flag[i] = 1;
                    TimerForKeyPress = 300;
                }
            }
            else{
                /* Long-press handle*/
                if(Reg2[i] == PRESSED){
                    TimerForKeyPress--;
                    if(TimerForKeyPress == 0){
                        buttonPressed_flag[i] = 1;
                        TimerForKeyPress = 100;
                    }
                }
            }
        }
    }
}

