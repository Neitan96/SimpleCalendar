/*
 * SimpleMillisecondsSet.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"
#include "../Extract/SimpleExtract.h"

void scMilliSetMillisecond(Milliseconds* milliseconds, int millisecond){
	if(millisecond >= 0 && millisecond < 1000)
		*milliseconds = millisecond + (*milliseconds - (*milliseconds % SECONDS_IN_MILLISECONDS));
}

void scMilliSetSecond(Milliseconds* milliseconds, int second){
	if(second >= 0 && second < 60)
		*milliseconds = (second * SECONDS_IN_MILLISECONDS)
						+ (*milliseconds % SECONDS_IN_MILLISECONDS)
						+ (*milliseconds - (*milliseconds % MINUTE_IN_MILLISECONDS));
}

void scMilliSetMinute(Milliseconds* milliseconds, int minute){
	if(minute >= 0 && minute < 60)
		*milliseconds = (minute * MINUTE_IN_MILLISECONDS)
						+ (*milliseconds % MINUTE_IN_MILLISECONDS)
						+ (*milliseconds - (*milliseconds % HOUR_IN_MILLISECONDS));

}

void scMilliSetHour(Milliseconds* milliseconds, int hour){
	if(hour >= 0 && hour < 24)
		*milliseconds = (hour * HOUR_IN_MILLISECONDS)
						+ (*milliseconds % HOUR_IN_MILLISECONDS)
						+ (*milliseconds - (*milliseconds % DAY_IN_MILLISECONDS));
}

void scMilliSetMonthDay(Milliseconds* milliseconds, int monthDay){
	if(monthDay < 1 || monthDay > 31) return;

	ExtractCalendar extractCalendar = scExtractMonthDayFromMilliseconds(*milliseconds);

	if(monthDay > extractCalendar.monthDay.value){
		Milliseconds diffMonthDays = monthDay - extractCalendar.monthDay.value;
		*milliseconds += diffMonthDays * DAY_IN_MILLISECONDS;
	}

	if(monthDay < extractCalendar.monthDay.value){
		Milliseconds diffMonthDays = extractCalendar.monthDay.value - monthDay;
		*milliseconds -= diffMonthDays * DAY_IN_MILLISECONDS;
	}
}

void scMilliSetMonth(Milliseconds* milliseconds, int month){
	if(month < 0 || month > 11) return;

	ExtractCalendar extractCalendar = scExtractMonthFromMilliseconds(*milliseconds);

	if(month > extractCalendar.month.value){
		int monthNow = extractCalendar.month.value;
		while(monthNow != month){
			*milliseconds += scTotalDaysInMonthMilli(extractCalendar.year.value, monthNow);
			monthNow++;
		}
	}

	if(month < extractCalendar.month.value){
		int monthNow = extractCalendar.month.value;
		int monthPrevious;

		while(monthNow != month){
			monthPrevious = monthNow - 1 < 0 ? DECEMBER : monthNow - 1;
			*milliseconds -= scTotalDaysInMonthMilli(extractCalendar.year.value, monthPrevious);
			monthNow--;
		}
	}

}

void scMilliSetYear(Milliseconds* milliseconds, int year){
	ExtractCalendar extractCalendar = scExtractYearFromMilliseconds(*milliseconds);

	if(year > extractCalendar.year.value){
		int diffYears = year - extractCalendar.year.value;
		int leapYears = scCountLeapYears(extractCalendar.year.value, year);
		*milliseconds += leapYears * YEAR_366_IN_MILLISECONDS;
		*milliseconds += (diffYears - leapYears) * YEAR_365_IN_MILLISECONDS;
	}

	if(year < extractCalendar.year.value){
		int diffYears = extractCalendar.year.value - year;
		int leapYears = scCountLeapYears(year, extractCalendar.year.value);
		*milliseconds -= leapYears * YEAR_366_IN_MILLISECONDS;
		*milliseconds -= (diffYears - leapYears) * YEAR_365_IN_MILLISECONDS;
	}

	if(scIsLeapYear(extractCalendar.year.value) && !scIsLeapYear(year))
		*milliseconds -= DAY_IN_MILLISECONDS;
	if(scIsLeapYear(year) && !scIsLeapYear(extractCalendar.year.value))
		*milliseconds += DAY_IN_MILLISECONDS;
}

void scMilliSetWeekDay(Milliseconds* milliseconds, int weekDay){
    if(weekDay >= 0 && weekDay < 7){
        int weekDayNow = scMilliGetWeekDay(*milliseconds);
        weekDayNow = weekDay - weekDayNow;
        scMilliAddMonthDay(milliseconds, weekDayNow);
    }
}

void scMilliSetWeekMonth(Milliseconds* milliseconds, int week){
    if(week > 0){
        ExtractCalendar calendar = scExtractMonthFromMilliseconds(*milliseconds);

        if(week == 1){
            *milliseconds = calendar.month.milliseconds + (*milliseconds % DAY_IN_MILLISECONDS);
        }else{
            int daysToAdd = scMilliGetWeekDay(calendar.month.milliseconds);
            daysToAdd = 7 - daysToAdd;
            daysToAdd += (week-2) * 7;
            *milliseconds = calendar.month.milliseconds 
                            + ((Milliseconds) daysToAdd * DAY_IN_MILLISECONDS) 
                            + (*milliseconds % DAY_IN_MILLISECONDS);
        }
    }
}

void scMilliSetWeekYear(Milliseconds* milliseconds, int week){
    if(week > 0){
        ExtractCalendar calendar = scExtractYearFromMilliseconds(*milliseconds);

        if(week == 1){
            *milliseconds = calendar.year.milliseconds + (*milliseconds % DAY_IN_MILLISECONDS);
        }else{
            int daysToAdd = scMilliGetWeekDay(calendar.year.milliseconds);
            daysToAdd = 7 - daysToAdd;
            daysToAdd += (week-2) * 7;
            *milliseconds = calendar.year.milliseconds 
                            + ((Milliseconds) daysToAdd * DAY_IN_MILLISECONDS) 
                            + (*milliseconds % DAY_IN_MILLISECONDS);
        }
    }
}