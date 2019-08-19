/*
 * SimpleMillisecondsAdd.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"
#include "../Extract/SimpleExtract.h"

void scMilliAddSecond(Milliseconds* milliseconds, int second) {
    *milliseconds += (Milliseconds) second * SECONDS_IN_MILLISECONDS;
}

void scMilliAddMinute(Milliseconds* milliseconds, int minute) {
    *milliseconds += (Milliseconds) minute * MINUTE_IN_MILLISECONDS;
}

void scMilliAddHour(Milliseconds* milliseconds, int hour) {
    *milliseconds += (Milliseconds) hour * HOUR_IN_MILLISECONDS;
}

void scMilliAddMonthDay(Milliseconds* milliseconds, int monthDay) {
    *milliseconds += (Milliseconds) monthDay * DAY_IN_MILLISECONDS;
}

void scMilliAddMonth(Milliseconds* milliseconds, int month) {

    if(month > 11 || month < -11){
    	int years = (month - (month % 12)) / 12;
    	month -= years * 12;
    	scMilliAddYear(milliseconds, years);
    }

    ExtractCalendar calendar = scExtractMonthFromMilliseconds(*milliseconds);

    for (; month > 0; month--) {
        *milliseconds += scTotalDaysInMonthMilli(calendar.year.value, calendar.month.value);
        calendar.month.value++;
        if (calendar.month.value > 11) {
            calendar.month.value -= 12;
            calendar.year.value++;
        }
    }

    for (; month < 0; month++) {
        calendar.month.value--;
        if (calendar.month.value < 0) {
            calendar.month.value += 12;
            calendar.year.value--;
        }
        *milliseconds -= scTotalDaysInMonthMilli(calendar.year.value, calendar.month.value);
    }
}

void scMilliAddYear(Milliseconds* milliseconds, int year){
    ExtractCalendar calendar = scExtractMonthFromMilliseconds(*milliseconds);

    if(year < 0){
        int leapYears = scCountLeapYears(calendar.year.value+year, calendar.year.value);

        if(scIsLeapYear(calendar.year.value+year)
        		&& !scIsLeapYear(calendar.year.value)
				&& calendar.month.value > FEBRUARY){
			leapYears--;
        }

        if(!scIsLeapYear(calendar.year.value+year)
        		&& scIsLeapYear(calendar.year.value)
				&& calendar.month.value > FEBRUARY){
			leapYears++;
        }

        *milliseconds += ((Milliseconds) year+leapYears)*YEAR_365_IN_MILLISECONDS;
        *milliseconds -= ((Milliseconds) leapYears)*YEAR_366_IN_MILLISECONDS;
    }

    if(year > 0){
        int leapYears = scCountLeapYears(calendar.year.value, calendar.year.value+year);

        if(scIsLeapYear(calendar.year.value)
        		&& !scIsLeapYear(calendar.year.value+year)
				&& calendar.month.value > FEBRUARY){
			leapYears--;
        }

        if(!scIsLeapYear(calendar.year.value)
        		&& scIsLeapYear(calendar.year.value+year)
				&& calendar.month.value > FEBRUARY){
			leapYears++;
        }

        *milliseconds += ((Milliseconds) year-leapYears)*YEAR_365_IN_MILLISECONDS;
        *milliseconds += ((Milliseconds) leapYears)*YEAR_366_IN_MILLISECONDS;
    }

}

void scMilliAddWeek(Milliseconds* milliseconds, int week){
    *milliseconds += (Milliseconds) week * 7 * DAY_IN_MILLISECONDS;
}