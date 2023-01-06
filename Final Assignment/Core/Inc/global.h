/*
 * global.h
 *
 *
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <trafficPeds.h>
#include "timer.h"
//#include "main.h"
#include "button.h"
#include "traffic1.h"
#include "traffic2.h"
#include "configTraffic.h"
#include "utils.h"



#define	INIT			1
#define	AUTO_RED_GREEN	2
#define	AUTO_RED_YELLOW	3
#define	AUTO_GREEN_RED	4
#define	AUTO_YELLOW_RED	5

#define	MAN_RED_GREEN	11
#define	MAN_RED_YELLOW	12
#define	MAN_GREEN_RED	13
#define	MAN_YELLOW_RED	14

#define	SETTING_RED1	20
#define	SETTING_RED2	21
#define	SETTING_GREEN1	22
#define	SETTING_GREEN2	23
#define	SETTING_YELLOW1	24
#define	SETTING_YELLOW2	25

#define	NO_PED		2
#define PED_RED		3
#define PED_GREEN	4

extern char str[];

extern int status;
extern int pedsStatus;
extern int numberCounter;

extern int redDuration1;
extern int greenDuration1;
extern int yellowDuration1;

extern int redDuration2;
extern int greenDuration2;
extern int yellowDuration2;




#endif /* INC_GLOBAL_H_ */
