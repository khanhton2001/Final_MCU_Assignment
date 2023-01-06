/*
 * manual_fsm.c
 *
 *
    */
#include "manual_fsm.h"



void manual_run(){
	switch (status) {
		case MAN_RED_GREEN:
			isButtonPressed(3);
			if(timer1_flag == 1) {
				status = INIT;
			}

			if(isButtonPressed(1)){
				manualClickButton1();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_YELLOW;
				Red_1();
				Yellow_2();
				pedsGreen();
				setTimer1(10000);
				pedsStatus = PED_GREEN;
			}
			break;

		case MAN_RED_YELLOW:
			if(isButtonPressed(3));
			if(timer1_flag) {
				status = INIT;
			}

			if(isButtonPressed(1)) {
				manualClickButton1();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_GREEN_RED;
				Green_1();
				Red_2();
				pedsRed();
				pedsStatus = PED_RED;
				setTimer1(10000);
			}
			break;

		case MAN_GREEN_RED:
			isButtonPressed(3);
			if(timer1_flag) {
				status = INIT;
			}

			if(isButtonPressed(1)) {
				manualClickButton1();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_YELLOW_RED;
				Yellow_1();
				Red_2();
				pedsRed();
				pedsStatus = PED_RED;
				setTimer1(10000);
			}

			break;

		case MAN_YELLOW_RED:
			isButtonPressed(3);
			if(timer1_flag) {
				status = INIT;
			}

			if(isButtonPressed(1)) {
				manualClickButton1();
				break;
			}

			if (isButtonPressed(2)) {
				status = MAN_RED_GREEN;
				Red_1();
				Green_2();
				pedsGreen();
				pedsStatus = PED_GREEN;
				setTimer1(10000);
			}


			break;
		default:
			break;
	}
}

