/*
 * tuning_fsm.c
 *
 *
 */
#include "tuning_fsm.h"




void tuning_run(){
	switch(status){
	case SETTING_RED1:

		if(timer1_flag){
			setTimer1(1000);
			toggleRed1();
		}

		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_RED2;
			setTimer1(1000);
			configRed1();
			numberCounter = redDuration2;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			numberCounter++;
			if(numberCounter > 60){
				numberCounter = 2;
			}
			UART_display();
		}

		break;
	case SETTING_RED2:
		if(timer1_flag){
			setTimer1(1000);
			toggleRed2();
		}

		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}
		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_GREEN1;
			setTimer1(1000);
			configRed2();
			numberCounter = greenDuration1;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			numberCounter++;
			if(numberCounter > 60){
				numberCounter = 2;
			}
			UART_display();
		}
		break;
	case SETTING_GREEN1:

		if(timer1_flag){
			setTimer1(1000);
			toggleGreen1();
		}

		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_GREEN2;
			setTimer1(1000);
			configGreen1();
			numberCounter = greenDuration2;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			numberCounter++;
			if(numberCounter > redDuration2 - 1){
				numberCounter = 1;
			}
			UART_display();
		}
		break;
	case SETTING_GREEN2:

		if(timer1_flag){
			setTimer1(1000);
			toggleGreen2();
		}

		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_YELLOW1;
			setTimer1(1000);
			configGreen2();
			numberCounter = yellowDuration1;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			numberCounter++;
			if(numberCounter > redDuration1 - 1){
				numberCounter = 1;
			}
			UART_display();
		}
		break;
	case SETTING_YELLOW1:
		if(timer1_flag){
			setTimer1(1000);
			toggleYellow1();
		}
		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_YELLOW2;
			setTimer1(1000);
			configYellow1();
			numberCounter = yellowDuration2;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		if(isButtonPressed(3)){
			numberCounter++;
			if(numberCounter > redDuration2 - 1){
				numberCounter = 1;
			}
			UART_display();
		}
		break;
	case SETTING_YELLOW2:
		if(timer1_flag){
			setTimer1(1000);
			toggleYellow2();
		}

		if(isButtonPressed(1)){
			tuningReturnToAuto();
			break;
		}

		if(isButtonPressed(0)){

		}

		if(isButtonPressed(2)){
			isButtonPressed(3);
			status = SETTING_RED1;
			setTimer1(1000);
			configYellow2();
			numberCounter = redDuration1;
			UART_display();
			turnOffTraffic1();
			turnOffTraffic2();
			break;
		}

		
	default:
		break;
	}
}
