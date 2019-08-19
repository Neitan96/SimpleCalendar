/*
 * SimpleCalendarGet.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleCalendar.h"
#include "../Base/SimpleCalendarBase.h"

int scCalCompare(Calendar calendar, Calendar calendar2){
    if(calendar.year > calendar2.year) return 1;
    if(calendar.year < calendar2.year) return -1;

    if(calendar.month > calendar2.month) return 1;
    if(calendar.month < calendar2.month) return -1;

    if(calendar.monthDay > calendar2.monthDay) return 1;
    if(calendar.monthDay < calendar2.monthDay) return -1;

    if(calendar.hour > calendar2.hour) return 1;
    if(calendar.hour < calendar2.hour) return -1;

    if(calendar.minute > calendar2.minute) return 1;
    if(calendar.minute < calendar2.minute) return -1;

    if(calendar.second > calendar2.second) return 1;
    if(calendar.second < calendar2.second) return -1;

    if(calendar.millisecond > calendar2.millisecond) return 1;
    if(calendar.millisecond < calendar2.millisecond) return -1;

    return 0;
}