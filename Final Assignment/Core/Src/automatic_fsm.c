/*
 * automatic_fsm.c
 *
 *
 */

#include "automatic_fsm.h"



void automatic_run(){
	switch (status)
	{
	case INIT:
		pedsStatus = NO_PED;
		Red_1();
		Green_2();
		pedsGreen();
		status=AUTO_RED_GREEN;
		numberCounter = redDuration1;
		UART_display();
		setTimer1(1000);
		pedsStatus = PED_GREEN;
		//buzzer
		break;
	case AUTO_RED_GREEN:
		if(timer1_flag == 1){
			numberCounter--;
			setTimer1(1000);
			if(numberCounter == yellowDuration2){
				Yellow_2();
				pedsGreen();
				status=AUTO_RED_YELLOW;

			}
			pedsStatus = PED_GREEN;
			UART_display();
		}

		if(isButtonPressed(1)){
			autoClickButton1();
			break;
		}
		break;
	case AUTO_RED_YELLOW:
		if(timer1_flag == 1){
			numberCounter--;
			setTimer1(1000);
			if(numberCounter == 0){
				numberCounter = greenDuration1;
				Green_1();
				Red_2();
				pedsRed();
				status=AUTO_GREEN_RED;
				pedsStatus = PED_RED;
				//buzzer
			}
			UART_display();
		}

		if(isButtonPressed(1)){
			autoClickButton1();
			break;
		}
		break;

	case AUTO_GREEN_RED:
		if(timer1_flag == 1){
			numberCounter--;
			setTimer1(1000);
			if(numberCounter == 0){
				numberCounter = yellowDuration1;
				Yellow_1();
				pedsRed();
				status=AUTO_YELLOW_RED;
				pedsStatus = PED_RED;
			}
			UART_display();
		}

		if(isButtonPressed(1)){
			autoClickButton1();
			break;
		}
		break;

	case AUTO_YELLOW_RED:

		if(timer1_flag == 1){
			numberCounter--;
			setTimer1(1000);
			if(numberCounter == 0){
				numberCounter = redDuration1;
				Red_1();
				Green_2();
				pedsGreen();
				status=AUTO_RED_GREEN;
				pedsStatus = PED_GREEN;
			}
			UART_display();
		}

		if(isButtonPressed(1)==1){
			autoClickButton1();
			break;
		}
		break;
	}

}
