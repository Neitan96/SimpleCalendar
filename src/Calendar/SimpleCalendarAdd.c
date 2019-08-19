/*
 * SimpleCalendarAdd.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleCalendar.h"
#include "../Base/SimpleCalendarBase.h"

void scCalAddMonthDay(Calendar* calendar, int monthDay) {

    if (monthDay > 0) {
        calendar->monthDay += monthDay;

        int daysInMonth;
        while (calendar->monthDay > (daysInMonth = scTotalDaysInMonth(calendar->year, calendar->month))) {
            calendar->monthDay -= daysInMonth;
            calendar->month++;
            while (calendar->month > 11) {
                calendar->month -= 12;
                calendar->year++;
            }
        }
		
    }

    if (monthDay < 0) {
        calendar->monthDay += monthDay;

        while (calendar->monthDay < 1) {
            calendar->month--;
            calendar->monthDay += scTotalDaysInMonth(calendar->year, calendar->month);
            while (calendar->month < 0) {
                calendar->month += 12;
                calendar->year--;
            }
        }

    }

}

void scCalAddMonth(Calendar* calendar, int month) {

    for (; month > 0; month--) {
        calendar->month++;
        if (calendar->month > 11) {
            calendar->month -= 12;
            calendar->year++;
        }
    }

    for (; month < 0; month++) {
        calendar->month--;
        if (calendar->month < 0) {
            calendar->month += 12;
            calendar->year--;
        }
    }

    if (calendar->monthDay > scTotalDaysInMonth(calendar->year, calendar->month)) {
        calendar->monthDay = calendar->monthDay - scTotalDaysInMonth(calendar->year, calendar->month);
        month++;
        if (calendar->month > 11) {
            calendar->month -= 12;
            calendar->year++;
        }
    }

}