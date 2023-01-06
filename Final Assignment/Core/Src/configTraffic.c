/*
 * configTraffic.c
 *
 *
 */

#include "configTraffic.h"

void configRed1(){
	redDuration1 = numberCounter;
	if(redDuration1 <= yellowDuration2) yellowDuration2 = 1;
	greenDuration2 = redDuration1 - yellowDuration2;
}


void configGreen1(){
	greenDuration1 = numberCounter;
	yellowDuration1 = redDuration2 - greenDuration1;
}

void configYellow1(){
	yellowDuration1 = numberCounter;
	greenDuration1 = redDuration2 - yellowDuration1;
}

void configRed2(){
	redDuration2 = numberCounter;
	if(redDuration2 <= yellowDuration1) yellowDuration1 = 1;
	greenDuration1 = redDuration2 - yellowDuration1;
}





