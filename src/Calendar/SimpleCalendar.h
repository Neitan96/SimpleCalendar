/*
 * SimpleCalendar.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLECALENDAR
#define SIMPLECALENDAR

#include "../Base/SimpleCalendarBase.h"

/* Adds */

void scCalAddMillisecond(Calendar* calendar, int millisecond);
void scCalAddSecond(Calendar* calendar, int second);
void scCalAddMinute(Calendar* calendar, int minute);
void scCalAddHour(Calendar* calendar, int hour);
void scCalAddMonthDay(Calendar* calendar, int monthDay);
void scCalAddMonth(Calendar* calendar, int month);
void scCalAddYear(Calendar* calendar, int year);
void scCalAddWeek(Calendar* calendar, int week);

/* Sets */

void scCalSetMillisecond(Calendar* calendar, int millisecond);
void scCalSetSecond(Calendar* calendar, int second);
void scCalSetMinute(Calendar* calendar, int minute);
void scCalSetHour(Calendar* calendar, int hour);
void scCalSetMonthDay(Calendar* calendar, int monthDay);
void scCalSetMonth(Calendar* calendar, int month);
void scCalSetYear(Calendar* calendar, int year);
void scCalSetWeekDay(Calendar* calendar, int weekDay);
void scCalSetWeekMonth(Calendar* calendar, int weekCount);
void scCalSetWeekYear(Calendar* calendar, int weekCount);

/* Next */

void scCalNextMillisecond(Calendar* calendar, int millisecond);
void scCalNextSecond(Calendar* calendar, int second);
void scCalNextMinute(Calendar* calendar, int minute);
void scCalNextHour(Calendar* calendar, int hour);
void scCalNextMonthDay(Calendar* calendar, int monthDay);
void scCalNextMonth(Calendar* calendar, int month);
void scCalNextWeekDay(Calendar* calendar, int weekDay);
void scCalNextWeekMonth(Calendar* calendar, int weekCount);
void scCalNextWeekYear(Calendar* calendar, int weekCount);

/* Gets */

int scCalGetWeekDay(Calendar* calendar);
int scCalGetYearDay(Calendar* calendar);
int scCalGetWeekMonth(Calendar* calendar);
int scCalGetWeekYear(Calendar* calendar);

/* Diffs */

int scCalDiffYear(Calendar calendar1, Calendar calendar2);
long int scCalDiffMonth(Calendar calendar1, Calendar calendar2);
long int scCalDiffMonthDay(Calendar calendar1, Calendar calendar2);
long long int scCalDiffHour(Calendar calendar1, Calendar calendar2);
long long int scCalDiffMinute(Calendar calendar1, Calendar calendar2);
long long int scCalDiffSecond(Calendar calendar1, Calendar calendar2);
long long int scCalDiffMilliecond(Calendar calendar1, Calendar calendar2);

/* Outros */

int scCalCompare(Calendar calendar, Calendar calendar2);

#endif /* SIMPLECALENDAR */
