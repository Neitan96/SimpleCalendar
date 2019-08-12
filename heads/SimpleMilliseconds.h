/*
 * SimpleMilliseconds.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLEMILLISECONDS
#define SIMPLEMILLISECONDS

#include "SimpleCalendarBase.h"

/* Compare */

int scMCompareMilliseconds(Milliseconds milliseconds, Milliseconds milliseconds2);

/* Adds */

void scMAddSecond(Milliseconds* milliseconds, int second);
void scMAddMinute(Milliseconds* milliseconds, int minute);
void scMAddHour(Milliseconds* milliseconds, int hour);
void scMAddMonthDay(Milliseconds* milliseconds, int monthDay);
void scMAddMonth(Milliseconds* milliseconds, int month);
void scMAddYear(Milliseconds* milliseconds, int year);
void scMAddWeek(Milliseconds* milliseconds, int week);

/* Sets */

void scMSetMillisecond(Milliseconds* milliseconds, int millisecond);
void scMSetSecond(Milliseconds* milliseconds, int second);
void scMSetMinute(Milliseconds* milliseconds, int minute);
void scMSetHour(Milliseconds* milliseconds, int hour);
void scMSetMonthDay(Milliseconds* milliseconds, int monthDay);
void scMSetMonth(Milliseconds* milliseconds, int month);
void scMSetYear(Milliseconds* milliseconds, int year);
void scMJumpToWeekDay(Milliseconds* milliseconds, int weekDay);
void scMJumpToWeekMonth(Milliseconds* milliseconds, int week);
void scMJumpToWeekYear(Milliseconds* milliseconds, int week);

/* Gets */

int scMGetWeekDay(Milliseconds milliseconds);
int scMGetYearDay(Milliseconds milliseconds);
int scMGetWeekMonth(Milliseconds milliseconds);
int scMGetWeekYear(Milliseconds milliseconds);

/* Counts */

long int scMCountMonthDay(Milliseconds milliseconds);
long int scMCountHour(Milliseconds milliseconds);
long long int scMCountMinute(Milliseconds milliseconds);
long long int scMCountSecond(Milliseconds milliseconds);

/* Outros */

void scMToString(Milliseconds milliseconds, char str[24]);

#endif /* SIMPLEMILLISECONDS */
