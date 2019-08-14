/*
 * SimpleMilliseconds.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLEMILLISECONDS
#define SIMPLEMILLISECONDS

#include "SimpleCalendarBase.h"

/* Adds */

void scMilliAddSecond(Milliseconds* milliseconds, int second);
void scMilliAddMinute(Milliseconds* milliseconds, int minute);
void scMilliAddHour(Milliseconds* milliseconds, int hour);
void scMilliAddMonthDay(Milliseconds* milliseconds, int monthDay);
void scMilliAddMonth(Milliseconds* milliseconds, int month);
void scMilliAddYear(Milliseconds* milliseconds, int year);
void scMilliAddWeek(Milliseconds* milliseconds, int week);

/* Sets */

void scMilliSetMillisecond(Milliseconds* milliseconds, int millisecond);
void scMilliSetSecond(Milliseconds* milliseconds, int second);
void scMilliSetMinute(Milliseconds* milliseconds, int minute);
void scMilliSetHour(Milliseconds* milliseconds, int hour);
void scMilliSetMonthDay(Milliseconds* milliseconds, int monthDay);
void scMilliSetMonth(Milliseconds* milliseconds, int month);
void scMilliSetYear(Milliseconds* milliseconds, int year);
void scMilliSetWeekDay(Milliseconds* milliseconds, int weekDay);
void scMilliSetWeekMonth(Milliseconds* milliseconds, int weekCount);
void scMilliSetWeekYear(Milliseconds* milliseconds, int weekCount);

/* Next */

void scMilliNextMillisecond(Milliseconds* milliseconds, int millisecond);
void scMilliNextSecond(Milliseconds* milliseconds, int second);
void scMilliNextMinute(Milliseconds* milliseconds, int minute);
void scMilliNextHour(Milliseconds* milliseconds, int hour);
void scMilliNextMonthDay(Milliseconds* milliseconds, int monthDay);
void scMilliNextMonth(Milliseconds* milliseconds, int month);
void scMilliNextYear(Milliseconds* milliseconds, int year);
void scMilliNextWeekDay(Milliseconds* milliseconds, int weekDay);
void scMilliNextWeekMonth(Milliseconds* milliseconds, int weekCount);
void scMilliNextWeekYear(Milliseconds* milliseconds, int weekCount);

/* Gets */

int scMilliGetWeekDay(Milliseconds milliseconds);
int scMilliGetYearDay(Milliseconds milliseconds);
int scMilliGetWeekMonth(Milliseconds milliseconds);
int scMilliGetWeekYear(Milliseconds milliseconds);

/* Counts */

long int scMilliCountMonthDay(Milliseconds milliseconds);
long int scMilliCountHour(Milliseconds milliseconds);
long long int scMilliCountMinute(Milliseconds milliseconds);
long long int scMilliCountSecond(Milliseconds milliseconds);

/* Outros */

int scMilliCompare(Milliseconds milliseconds, Milliseconds milliseconds2);

void scMilliToString(Milliseconds milliseconds, char str[24]);

#endif /* SIMPLEMILLISECONDS */
