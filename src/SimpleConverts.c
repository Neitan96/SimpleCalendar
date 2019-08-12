/*
 * SimpleConverts.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include "../heads/SimpleConverts.h"
#include "../heads/SimpleCalendarBase.h"
#include "../heads/SimpleExtract.h"


Calendar scMakeCalendar(int year, int month, int monthDay,
        int hour, int minute, int second, int millisecond) {
    Calendar calendar;

    calendar.year = year;
    calendar.month = month;
    calendar.monthDay = monthDay;
    calendar.hour = hour;
    calendar.minute = minute;
    calendar.second = second;
    calendar.millisecond = millisecond;

    return calendar;
}

Calendar scMillisecondsToCalendar(Milliseconds milliseconds) {
    ExtractCalendar calendar = scMillisecondsToExtract(milliseconds);
    return scMakeCalendar(calendar.year.value, calendar.month.value, calendar.monthDay.value,
            calendar.hour.value, calendar.minute.value, calendar.second.value,
            calendar.millisecond.value);
}

Calendar scExtractToCalendar(ExtractCalendar extractCalendar) {
    return scMakeCalendar(extractCalendar.year.value, extractCalendar.month.value, extractCalendar.monthDay.value,
            extractCalendar.hour.value, extractCalendar.minute.value, extractCalendar.second.value,
            extractCalendar.millisecond.value);
}

Milliseconds scMakeMilliseconds(int year, int month, int monthDay, int hour,
        int minute, int second, int millisecond) {
    return scMakeExtractCalendar(year, month, monthDay, hour, minute, second, millisecond).millisecond.milliseconds;
}

Milliseconds scCalendarToMilliseconds(Calendar calendar) {
    return scMakeMilliseconds(calendar.year, calendar.month, calendar.monthDay,
            calendar.hour, calendar.minute, calendar.second, calendar.millisecond);
}

Milliseconds scExtractToMilliseconds(ExtractCalendar extractCalendar) {
    return extractCalendar.millisecond.milliseconds;
}

ExtractCalendar scMakeExtractCalendar(int year, int month, int monthDay, int hour,
        int minute, int second, int millisecond) {
    return scExtractFromCalendar(scMakeCalendar(year, month, monthDay, hour, minute, second, millisecond));
}

ExtractCalendar scCalendarToExtract(Calendar calendar) {
    return scMakeExtractCalendar(calendar.year, calendar.month, calendar.monthDay,
            calendar.hour, calendar.minute, calendar.second,
            calendar.millisecond);
}

ExtractCalendar scMillisecondsToExtract(Milliseconds milliseconds) {
    return scExtractFromMilliseconds(milliseconds);
}
