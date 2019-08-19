/*
 * SimpleMillisecondsGet.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"
#include "../Extract/SimpleExtract.h"


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