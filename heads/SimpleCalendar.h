/*
 * SimpleCalendar.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLECALENDAR
#define SIMPLECALENDAR

#include "SimpleCalendarBase.h"


/* Compare */

int scCCompareCalendar(Calendar calendar, Calendar calendar2);

/* Adds */

void scCAddMillisecond(Calendar* calendar, int millisecond);
void scCAddSecond(Calendar* calendar, int second);
void scCAddMinute(Calendar* calendar, int minute);
void scCAddHour(Calendar* calendar, int hour);
void scCAddMonthDay(Calendar* calendar, int monthDay);
void scCAddMonth(Calendar* calendar, int month);
void scCAddYear(Calendar* calendar, int year);

/* Sets */

void scCSetMillisecond(Calendar* calendar, int millisecond);
void scCSetSecond(Calendar* calendar, int second);
void scCSetMinute(Calendar* calendar, int minute);
void scCSetHour(Calendar* calendar, int hour);
void scCSetMonthDay(Calendar* calendar, int monthDay);
void scCSetMonth(Calendar* calendar, int month);
void scCSetYear(Calendar* calendar, int year);
void scCJumpToWeekDay(Calendar* calendar, int weekDay);

/* Gets */

int scCGetWeekDay(Calendar* calendar);
int scCGetYearDay(Calendar* calendar);
int scCGetWeekMonth(Calendar* calendar);
int scCGetWeekYear(Calendar* calendar);

/* Counts */

/* Extracts */

#endif /* SIMPLECALENDAR */
