/*
 * utils.c
 *
 *
 */

#include "utils.h"
#include "global.h"

void autoClickButton1() {
	isButtonPressed(2);
	isButtonPressed(3);
	status=MAN_RED_GREEN;
	Red_1();
	Green_2();
	pedsGreen();
	pedsStatus = PED_GREEN;
	setTimer1(10000);
	numberCounter = 60;
	UART_display();
}

void manualClickButton1() {
	isButtonPressed(2);
	status = SETTING_RED1;
	setTimer1(1000);
	numberCounter = redDuration1;
	UART_display();
	turnOffTraffic1();
	turnOffTraffic2();
}

void tuningReturnToAuto(){
	isButtonPressed(2);
	isButtonPressed(3);

	switch(status) {
		case SETTING_RED1:
			configRed1();
			break;
		case SETTING_RED2:
			configRed2();
			break;
		case SETTING_GREEN1:
			configGreen1();
			break;
		case SETTING_GREEN2:
			configGreen2();
			break;
		case SETTING_YELLOW1:
			configYellow1();
			break;
		case SETTING_YELLOW2:
			configYellow2();
			break;
		default:
			break;
	}
	status = AUTO_RED_GREEN;
	setTimer1(1000);
	numberCounter = redDuration1;
	UART_display();
	Red_1();
	Green_2();
}

