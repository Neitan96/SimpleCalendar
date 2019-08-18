/*
 * SimpleExtract.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include "../heads/SimpleExtract.h"
#include "../heads/SimpleCalendarBase.h"


ExtractCalendar scExtractYearFromCalendar(Calendar calendar){

    ExtractTime extractYear;
    extractYear.value = calendar.year;
    extractYear.milliseconds = 0;

    int leapYears = scCountLeapYears(1970, calendar.year);
    extractYear.milliseconds += ((calendar.year-1970) - leapYears) * YEAR_365_IN_MILLISECONDS;
    extractYear.milliseconds += leapYears * YEAR_366_IN_MILLISECONDS;

    ExtractCalendar extractCalendar;
    extractCalendar.year = extractYear;
    return extractCalendar;
}

ExtractCalendar scExtractMonthFromCalendar(Calendar calendar){

    ExtractTime extractMonth;
    extractMonth.value = calendar.month;
    extractMonth.milliseconds = 0;

    for (int i = 0; i < calendar.month; i++)
    	extractMonth.milliseconds += scTotalDaysInMonthMilli(calendar.year, i);

    ExtractCalendar extractCalendar = scExtractYearFromCalendar(calendar);
    extractMonth.milliseconds += extractCalendar.year.milliseconds;
    extractCalendar.month = extractMonth;
    return extractCalendar;
}

ExtractCalendar scExtractMonthDayFromCalendar(Calendar calendar){

    ExtractTime extractMonthDay;
    extractMonthDay.value = calendar.monthDay;
    extractMonthDay.milliseconds = ((long long int) calendar.monthDay - 1) * DAY_IN_MILLISECONDS;

    ExtractCalendar extractCalendar = scExtractMonthFromCalendar(calendar);
    extractMonthDay.milliseconds += extractCalendar.month.milliseconds;
    extractCalendar.monthDay = extractMonthDay;
    return extractCalendar;
}

ExtractCalendar scExtractHourFromCalendar(Calendar calendar){

    ExtractTime extractHour;
    extractHour.value = calendar.hour;
    extractHour.milliseconds = ((long long int) calendar.hour) * HOUR_IN_MILLISECONDS;

    ExtractCalendar extractCalendar = scExtractMonthDayFromCalendar(calendar);
    extractHour.milliseconds += extractCalendar.monthDay.milliseconds;
    extractCalendar.hour = extractHour;
    return extractCalendar;
}

ExtractCalendar scExtractMinuteFromCalendar(Calendar calendar){

    ExtractTime extractMinute;
    extractMinute.value = calendar.minute;
    extractMinute.milliseconds = ((long long int) calendar.minute) * MINUTE_IN_MILLISECONDS;

    ExtractCalendar extractCalendar = scExtractHourFromCalendar(calendar);
    extractMinute.milliseconds += extractCalendar.hour.milliseconds;
    extractCalendar.minute = extractMinute;
    return extractCalendar;
}

ExtractCalendar scExtractSecondFromCalendar(Calendar calendar){

    ExtractTime extractSecond;
    extractSecond.value = calendar.second;
    extractSecond.milliseconds = ((long long int) calendar.second) * SECONDS_IN_MILLISECONDS;

    ExtractCalendar extractCalendar = scExtractMinuteFromCalendar(calendar);
    extractSecond.milliseconds += extractCalendar.minute.milliseconds;
    extractCalendar.second = extractSecond;
    return extractCalendar;
}

ExtractCalendar scExtractFromCalendar(Calendar calendar){

    ExtractTime extractMillisecond;
    extractMillisecond.value = calendar.second;
    extractMillisecond.milliseconds = (long long int) calendar.millisecond;

    ExtractCalendar extractCalendar = scExtractSecondFromCalendar(calendar);
    extractMillisecond.milliseconds += extractCalendar.second.milliseconds;
    extractCalendar.millisecond = extractMillisecond;
    return extractCalendar;
}

void scExtractValue(ExtractTime *extract, Milliseconds *milliseconds,
                        Milliseconds valueInMilliseconds, int countMultiplier){
    if(*milliseconds > valueInMilliseconds){
        Milliseconds millisecondsCount = *milliseconds % valueInMilliseconds;
        millisecondsCount = *milliseconds - millisecondsCount;

        if(millisecondsCount > 0){
            *milliseconds -= millisecondsCount;
            extract->milliseconds += millisecondsCount;
            extract->value += (millisecondsCount/valueInMilliseconds)*countMultiplier;
        }
    }
}

ExtractCalendar scExtractYearFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar;

    ExtractTime extractYear;
    extractYear.milliseconds = 0;
    extractYear.value = 1600;

    milliseconds += _1600_TO_1970_IN_MILLISECONDS;

    scExtractValue(&extractYear, &milliseconds, FOUR_HUNDRED_YEARS_IN_MILLISECONDS, 400);
    scExtractValue(&extractYear, &milliseconds, ONE_HUNDRED_YEARS_IN_MILLISECONDS, 100);
    scExtractValue(&extractYear, &milliseconds, FOUR_YEARS_IN_MILLISECONDS, 4);
    scExtractValue(&extractYear, &milliseconds, YEAR_365_IN_MILLISECONDS, 1);

    extractYear.milliseconds -= _1600_TO_1970_IN_MILLISECONDS;

    extractCalendar.year = extractYear;

    return extractCalendar;
}

ExtractCalendar scExtractMonthFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractYearFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.year.milliseconds;

    ExtractTime extractMonth;
    extractMonth.milliseconds = extractCalendar.year.milliseconds;
    extractMonth.value = 0;

    Milliseconds millisecondsTemp;
    while (milliseconds > (millisecondsTemp = scTotalDaysInMonthMilli(extractCalendar.year.value, extractMonth.value))){
        milliseconds -= millisecondsTemp;
        extractMonth.milliseconds += millisecondsTemp;
        extractMonth.value++;
    }

    extractCalendar.month = extractMonth;
    return extractCalendar;
}

ExtractCalendar scExtractMonthDayFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractMonthFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.month.milliseconds;

    ExtractTime extractMonthDay;
    extractMonthDay.milliseconds = extractCalendar.month.milliseconds;
    extractMonthDay.value = 1;

    scExtractValue(&extractMonthDay, &milliseconds, DAY_IN_MILLISECONDS, 1);
    extractCalendar.monthDay = extractMonthDay;

    return extractCalendar;
}

ExtractCalendar scExtractHourFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractMonthDayFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.monthDay.milliseconds;

    ExtractTime extractHour;
    extractHour.milliseconds = extractCalendar.monthDay.milliseconds;
    extractHour.value = 0;

    scExtractValue(&extractHour, &milliseconds, HOUR_IN_MILLISECONDS, 1);
    extractCalendar.hour = extractHour;

    return extractCalendar;
}

ExtractCalendar scExtractMinuteFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractHourFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.hour.milliseconds;

    ExtractTime extractMinute;
    extractMinute.milliseconds = extractCalendar.hour.milliseconds;
    extractMinute.value = 0;

    scExtractValue(&extractMinute, &milliseconds, MINUTE_IN_MILLISECONDS, 1);
    extractCalendar.minute = extractMinute;

    return extractCalendar;
}

ExtractCalendar scExtractSecondFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractMinuteFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.minute.milliseconds;

    ExtractTime extractSecond;
    extractSecond.milliseconds = extractCalendar.minute.milliseconds;
    extractSecond.value = 0;

    scExtractValue(&extractSecond, &milliseconds, SECONDS_IN_MILLISECONDS, 1);
    extractCalendar.second = extractSecond;

    return extractCalendar;
}

ExtractCalendar scExtractFromMilliseconds(Milliseconds milliseconds){
    ExtractCalendar extractCalendar = scExtractSecondFromMilliseconds(milliseconds);
    milliseconds -= extractCalendar.second.milliseconds;

    ExtractTime extractMillisecond;
    extractMillisecond.milliseconds = extractCalendar.second.milliseconds;
    extractMillisecond.value = 0;

    scExtractValue(&extractMillisecond, &milliseconds, 1, 1);
    extractCalendar.millisecond = extractMillisecond;

    return extractCalendar;
}

