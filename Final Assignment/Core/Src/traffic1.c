/*
 * trafffic1.c
 *
 *  Created on: Dec 30, 2022
 *      Author: HuyKiet
 */

#include "traffic1.h"

void Red_1(){
	HAL_GPIO_WritePin(TL1_0_GPIO_Port, TL1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, GPIO_PIN_RESET);

}

void Green_1(){
	HAL_GPIO_WritePin(TL1_0_GPIO_Port, TL1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, GPIO_PIN_SET);
}

void Yellow_1(){
	HAL_GPIO_WritePin(TL1_0_GPIO_Port, TL1_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, GPIO_PIN_SET);
}

void turnOffTraffic1(){
	HAL_GPIO_WritePin(TL1_0_GPIO_Port, TL1_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(TL1_1_GPIO_Port, TL1_1_Pin, GPIO_PIN_RESET);
}

void toggleRed1(){
	// Only use when led is clear or red.
	HAL_GPIO_TogglePin(TL1_0_GPIO_Port, TL1_0_Pin);
}

void toggleGreen1(){
	// Only use when led is clear or green.
	HAL_GPIO_TogglePin(TL1_1_GPIO_Port, TL1_1_Pin);
}

void toggleYellow1(){
	// Only use when led is clear or yellow.
	HAL_GPIO_TogglePin(TL1_0_GPIO_Port, TL1_0_Pin);
	HAL_GPIO_TogglePin(TL1_1_GPIO_Port, TL1_1_Pin);
}





