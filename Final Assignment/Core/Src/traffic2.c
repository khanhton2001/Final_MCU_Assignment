/*
 * traffic2.c
 *
 *
 */

#include "traffic2.h"


void Red_2(){
	HAL_GPIO_WritePin(TL2_0_GPIO_Port, TL2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, GPIO_PIN_RESET);
}


void Green_2(){
	HAL_GPIO_WritePin(TL2_0_GPIO_Port, TL2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, GPIO_PIN_SET);
}

void Yellow_2(){
	HAL_GPIO_WritePin(TL2_0_GPIO_Port, TL2_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, GPIO_PIN_SET);
}

void turnOffTraffic2(){
	HAL_GPIO_WritePin(TL2_0_GPIO_Port, TL2_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TL2_1_GPIO_Port, TL2_1_Pin, GPIO_PIN_RESET);
}


void toggleRed2(){
	// Only use when led is clear or red.
	HAL_GPIO_TogglePin(TL2_0_GPIO_Port, TL2_0_Pin);
}

void toggleGreen2(){
	// Only use when led is clear or green.
	HAL_GPIO_TogglePin(TL2_1_GPIO_Port, TL2_1_Pin);
}


void toggleYellow2(){
	// Only use when led is clear or yellow.
	HAL_GPIO_TogglePin(TL2_0_GPIO_Port, TL2_0_Pin);
	HAL_GPIO_TogglePin(TL2_1_GPIO_Port, TL2_1_Pin);
}



