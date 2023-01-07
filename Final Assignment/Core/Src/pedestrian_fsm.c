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
		if(status == SETTING_GREEN1 || status == SETTING_GREEN2 || status == SETTING_YELLOW2 || status == SETTING_YELLOW1 || status == SETTING_RED2 || status == SETTING_RED1) {
			turnOffPeds();
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
		} else {
			pedsRed();
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);

		}
		break;
	case PED_GREEN:
		if(status == SETTING_GREEN1 || status == SETTING_GREEN2 || status == SETTING_YELLOW2 || status == SETTING_YELLOW1 || status == SETTING_RED2 || status == SETTING_RED1) {
			turnOffPeds();
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,0);
		} else if(isButtonPressed(0)){
			if(status == MAN_RED_GREEN || status == MAN_RED_YELLOW){
				magnitude = 1000;
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,magnitude);
			} else if(status == AUTO_RED_GREEN || status == AUTO_RED_YELLOW){
				magnitude = 1000 - 1000*(numberCounter/(double)redDuration1);
				__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1,magnitude);

			}
		}
		break;
	default:
		break;
	}
}
