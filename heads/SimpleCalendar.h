/*
 * SimpleCalendar.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLECALENDAR
#define SIMPLECALENDAR

#include "SimpleCalendarBase.h"

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
void scCalJumpToWeekDay(Calendar* calendar, int weekDay);
void scCalJumpToWeekMonth(Calendar* calendar, int week);
void scCalJumpToWeekYear(Calendar* calendar, int week);

/* Gets */

int scCalGetWeekDay(Calendar* calendar);
int scCalGetYearDay(Calendar* calendar);
int scCalGetWeekMonth(Calendar* calendar);
int scCalGetWeekYear(Calendar* calendar);

/* Counts */

long int scCalCountMonthDay(Calendar calendar);
long int scCalCountHour(Calendar calendar);
long long int scCalCountMinute(Calendar calendar);
long long int scCalCountSecond(Calendar calendar);

/* Outros */

int scCalCompare(Calendar calendar, Calendar calendar2);

void scCalToString(Calendar calendar, char str[24]);

#endif /* SIMPLECALENDAR */
