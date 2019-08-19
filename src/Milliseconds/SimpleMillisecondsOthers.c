/*
 * SimpleMillisecondsOthers.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"
#include "../Extract/SimpleExtract.h"
#include <stdio.h>

void scMilliToString(Milliseconds milliseconds, char str[24]){
    ExtractCalendar calendar = scExtractFromMilliseconds(milliseconds);
    sprintf(str, "%02i/%02i/%04i %02i:%02i:%02i %03i", calendar.monthDay.value, 
                calendar.month.value + 1, calendar.year.value, calendar.hour.value, 
                calendar.minute.value, calendar.second.value, calendar.millisecond.value);
}

int scMilliCompare(Milliseconds milliseconds, Milliseconds milliseconds2){
    if(milliseconds > milliseconds2) return 1;
    if(milliseconds2 > milliseconds) return -1;
    return 0;
}