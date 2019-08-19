/*
 * SimpleCalendarGet.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleCalendar.h"
#include "../Base/SimpleCalendarBase.h"

int scCalGetYearDay(Calendar* calendar) {
    int yearDay = calendar->monthDay;
    for (int i = 0; i < calendar->month; i++)
        yearDay += scTotalDaysInMonth(calendar->year, i);
    return yearDay;
}