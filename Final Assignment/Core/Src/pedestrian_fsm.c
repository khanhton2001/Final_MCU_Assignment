/*
 * pedestrian_fsm.c
 *
 *
 */

#include "pedestrian_fsm.h"

int magnitude = 0;

void pedestrian_run(){
	switch(pedsStatus) {
	case NO_PED:
		turnOffPeds();
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
		break;
	case PED_RED:
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
		break;
	case PED_GREEN:
		if(isButtonPressed(0)){
			if(status == MAN_RED_GREEN || status == MAN_RED_YELLOW){
				magnitude = 1000;
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,1000);
				break;
			}
			magnitude = 1000 - 1000*(numberCounter/(double)redDuration1);
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,magnitude);
		}
		break;
	default:
		break;
	}
}
