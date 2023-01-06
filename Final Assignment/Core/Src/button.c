/*
 * button.c
 *
 *
 */
#include "button.h"



static int button_buffer[NO_OF_BUTTONS];

static int debounceButtonBuffer1[NO_OF_BUTTONS];
static int debounceButtonBuffer2[NO_OF_BUTTONS];
static int debounceButtonBuffer3[NO_OF_BUTTONS];



int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void button_process(int index){
	if(index >= 0 && index < NO_OF_BUTTONS){
		button_flag[index] = 1;
	}
}

void button_reading(){
	for(uint8_t i = 0 ; i < NO_OF_BUTTONS; i++){

		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];


		if(i == 0) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(PedestrianButton_GPIO_Port, PedestrianButton_Pin);
		else if(i == 1) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		else if(i == 2) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		else if(i == 3) debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);


		if((debounceButtonBuffer3[i] == debounceButtonBuffer2[i]) && debounceButtonBuffer2[i] == debounceButtonBuffer1[i]){
			button_buffer[i] = debounceButtonBuffer3[i];
			switch(buttonState[i]){
			case BUTTON_IS_PRESSED:
				counterForButtonPressed[i]++;
				if(counterForButtonPressed[i] == TIME_OUT_FOR_LONG_KEY_PRESSED/TIMER_CYCLE){
					buttonState[i] = BUTTON_IS_LONG_PRESSED;
					counterForButtonPressed[i] = 0;
					button_process(i);
				}
				if(button_buffer[i] == RELEASED_STATE){
					buttonState[i] = BUTTON_IS_RELEASED;
					counterForButtonPressed[i] = 0;
				}
				break;
			case BUTTON_IS_RELEASED:
				if(button_buffer[i] == PRESSED_STATE){
					buttonState[i] = BUTTON_IS_PRESSED;
					button_process(i);
				}
				break;
			case BUTTON_IS_LONG_PRESSED:
				counterForButtonPressed[i]++;
				if(counterForButtonPressed[i] == TIME_OUT_FOR_KEY_PRESSED/TIMER_CYCLE){
					button_process(i);
					counterForButtonPressed[i] = 0;
				}
				if(button_buffer[i] == RELEASED_STATE){
					buttonState[i] = BUTTON_IS_RELEASED;
					counterForButtonPressed[i] = 0;
				}
				break;
			default:
				break;
			}
		}
	}
}


