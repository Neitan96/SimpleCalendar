/*
 * SimpleMillisecondsNext.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"
#include "../Extract/SimpleExtract.h"

void scMilliNextMillisecond(Milliseconds* milliseconds, int millisecond){
	if(millisecond >= 0 && millisecond < 1000){
        int milliToAdd = *milliseconds % SECONDS_IN_MILLISECONDS;
        milliToAdd = millisecond - milliToAdd;
        if(milliToAdd < 1) milliToAdd += 1000;
		*milliseconds += milliToAdd;
    }
}

void scMilliNextSecond(Milliseconds* milliseconds, int second){
	if(second >= 0 && second < 60){
        int milliToAdd = *milliseconds % MINUTE_IN_MILLISECONDS;
        milliToAdd = second - (milliToAdd / SECONDS_IN_MILLISECONDS);
        if(milliToAdd < 1) milliToAdd += 60;
		*milliseconds += (Milliseconds) milliToAdd * SECONDS_IN_MILLISECONDS;
    }
}

void scMilliNextMinute(Milliseconds* milliseconds, int minute){
	if(minute >= 0 && minute < 60){
        int milliToAdd = *milliseconds % HOUR_IN_MILLISECONDS;
        milliToAdd = minute - (milliToAdd / MINUTE_IN_MILLISECONDS);
        if(milliToAdd < 1) milliToAdd += 60;
		*milliseconds += (Milliseconds) milliToAdd * MINUTE_IN_MILLISECONDS;
    }
}

void scMilliNextHour(Milliseconds* milliseconds, int hour){
	if(hour >= 0 && hour < 24){
        int milliToAdd = *milliseconds % DAY_IN_MILLISECONDS;
        milliToAdd = hour - (milliToAdd / HOUR_IN_MILLISECONDS);
        if(milliToAdd < 1) milliToAdd += 24;
		*milliseconds += (Milliseconds) milliToAdd * HOUR_IN_MILLISECONDS;
    }
}

void scMilliNextMonthDay(Milliseconds* milliseconds, int monthDay){
	if(monthDay > 1 && monthDay <= 31){
        ExtractCalendar calendar = scExtractMonthDayFromMilliseconds(*milliseconds);
        int milliToAdd = monthDay - calendar.monthDay.value;
        if(milliToAdd < 1) 
            milliToAdd += scTotalDaysInMonth(calendar.year.value, calendar.month.value);
		*milliseconds += (Milliseconds) milliToAdd * DAY_IN_MILLISECONDS;
    }
}

void scMilliNextMonth(Milliseconds* milliseconds, int month){
	if(month >= 0 && month < 12){
        ExtractCalendar calendar = scExtractMonthFromMilliseconds(*milliseconds);
        int monthToAdd = month - calendar.month.value;
        if(monthToAdd < 1) monthToAdd += 12;
		scMilliAddMonth(milliseconds, monthToAdd);
    }
}

void scMilliNextWeekDay(Milliseconds* milliseconds, int weekDay) {
    if(weekDay >= 0 && weekDay < 7){
        int weekDayNow = scMilliGetWeekDay(*milliseconds);
        weekDayNow = weekDay - weekDayNow;
        if (weekDayNow < 1) weekDayNow += 7;
        scMilliAddMonthDay(milliseconds, weekDayNow);
    }
}

void scMilliNextWeekMonth(Milliseconds* milliseconds, int week){
        //TODO make Milli Next WeekMonth
}

void scMilliNextWeekYear(Milliseconds* milliseconds, int week){
    //TODO make Milli Next WeekYear
}