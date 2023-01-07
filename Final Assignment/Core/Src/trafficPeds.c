/*
 * traffic.c
 *
 *
 */
#include "trafficPeds.h"


void pedsRed(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}

void pedsGreen(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void pedsYellow(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_SET);
}

void turnOffPeds(){
	HAL_GPIO_WritePin(PedestrianLight_0_GPIO_Port, PedestrianLight_0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(PedestrianLight_1_GPIO_Port, PedestrianLight_1_Pin, GPIO_PIN_RESET);
}


void UART_display(){
	int d1 = numberCounter / 10;
	int d2 = numberCounter % 10;
	HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "!7SEG=%d%d#\r\n", d1, d2), 1000);
}
