/*
 * SimpleMilliseconds.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLEMILLISECONDS
#define SIMPLEMILLISECONDS

#include "../Base/SimpleCalendarBase.h"

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
void scMilliNextWeekDay(Milliseconds* milliseconds, int weekDay);
void scMilliNextWeekMonth(Milliseconds* milliseconds, int weekCount, int keepWeekDay);
void scMilliNextWeekYear(Milliseconds* milliseconds, int weekCount, int keepWeekDay);

/* Gets */

int scMilliGetWeekDay(Milliseconds milliseconds);
int scMilliGetYearDay(Milliseconds milliseconds);
int scMilliGetWeekMonth(Milliseconds milliseconds);
int scMilliGetWeekYear(Milliseconds milliseconds);

/* Diffs */

Calendar scMilliDiff(Milliseconds milliseconds1, Milliseconds milliseconds2);
int scMilliDiffYear(Milliseconds milliseconds1, Milliseconds milliseconds2);
long int scMilliDiffMonth(Milliseconds milliseconds1, Milliseconds milliseconds2);
long int scMilliDiffMonthDay(Milliseconds milliseconds1, Milliseconds milliseconds2);
long long int scMilliDiffHour(Milliseconds milliseconds1, Milliseconds milliseconds2);
long long int scMilliDiffMinute(Milliseconds milliseconds1, Milliseconds milliseconds2);
long long int scMilliDiffSecond(Milliseconds milliseconds1, Milliseconds milliseconds2);
long long int scMilliDiffMilliecond(Milliseconds milliseconds1, Milliseconds milliseconds2);

/* Outros */

int scMilliCompare(Milliseconds milliseconds, Milliseconds milliseconds2);

#endif /* SIMPLEMILLISECONDS */
