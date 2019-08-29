/*
 * SimpleMillisecondsOthers.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"

int scMilliCompare(Milliseconds milliseconds, Milliseconds milliseconds2){
    if(milliseconds > milliseconds2) return 1;
    if(milliseconds2 > milliseconds) return -1;
    return 0;
}