/*
 * SimpleMilliseconds.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include<stdio.h>
#include "../heads/SimpleMilliseconds.h"
#include "../heads/SimpleCalendarBase.h"
#include "../heads/SimpleExtract.h"

/* Adds */

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

/* Sets */

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

/* Next */

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
void scMilliNextYear(Milliseconds* milliseconds, int year){
    //TODO
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
    //TODO
}
void scMilliNextWeekYear(Milliseconds* milliseconds, int week){
    //TODO
}

/* Gets */

int scMilliGetWeekDay(Milliseconds milliseconds) {
    Milliseconds weekDay = (long long int) milliseconds % DAY_IN_MILLISECONDS;
    weekDay = (Milliseconds) (milliseconds - weekDay);
    weekDay = weekDay / DAY_IN_MILLISECONDS;
    weekDay = (weekDay % 7) + 4;
    if (weekDay > 6) weekDay -= 7;
    return (int) weekDay;
}
int scMilliGetYearDay(Milliseconds milliseconds) {
    ExtractCalendar calendar = scExtractMonthDayFromMilliseconds(milliseconds);
    Milliseconds diffDays = calendar.monthDay.milliseconds - calendar.year.milliseconds;
    diffDays = diffDays / DAY_IN_MILLISECONDS;
    return (int) diffDays + 1;
}
int scMilliGetWeekMonth(Milliseconds milliseconds) {
    ExtractCalendar calendar = scExtractMonthDayFromMilliseconds(milliseconds);

    int weekMonth = 0;
    int weekDay = scMilliGetWeekDay(calendar.month.milliseconds);
    int days = calendar.monthDay.value;

    if (weekDay > 0) {
        weekMonth++;
        days -= 7 - weekDay;
    }

    if (days % 7 > 0) {
        weekMonth++;
        days -= days % 7;
    }

    weekMonth += days / 7;

    return weekMonth;
}
int scMilliGetWeekYear(Milliseconds milliseconds) {
    ExtractCalendar calendar = scExtractMonthDayFromMilliseconds(milliseconds);

    int weekYear = 0;
    int weekDay = scMilliGetWeekDay(calendar.year.milliseconds);
    int days = scMilliGetYearDay(milliseconds);

    if (weekDay > 0) {
        weekYear++;
        days -= 7 - weekDay;
    }

    if (days % 7 > 0) {
        weekYear++;
        days -= days % 7;
    }

    weekYear += days / 7;

    return weekYear;
}

/* Counts */

long int scMilliCountMonthDay(Milliseconds milliseconds) {
    return (long int) (milliseconds / DAY_IN_MILLISECONDS);
}
long int scMilliCountHour(Milliseconds milliseconds) {
    return (long int) (milliseconds / HOUR_IN_MILLISECONDS);
}
long long int scMilliCountMinute(Milliseconds milliseconds) {
    return milliseconds / MINUTE_IN_MILLISECONDS;
}
long long int scMilliCountSecond(Milliseconds milliseconds) {
    return milliseconds / SECONDS_IN_MILLISECONDS;
}

/* Outros */

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