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
	
	default:
		break;
	}
}
