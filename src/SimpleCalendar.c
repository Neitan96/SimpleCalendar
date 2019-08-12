/*
 * SimpleCalendar.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include "../heads/SimpleCalendar.h"
#include "../heads/SimpleCalendarBase.h"

/* Adds */

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

/* Sets */

/* Gets */

int scCalGetYearDay(Calendar* calendar) {
    int yearDay = calendar->monthDay;
    for (int i = 0; i < calendar->month; i++)
        yearDay += scTotalDaysInMonth(calendar->year, i);
    return yearDay;
}

/* Counts */

/* Outros */

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