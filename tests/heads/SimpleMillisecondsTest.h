/*
 * SimpleMilliseconds.h
 *
 *  Created on: 14 de ago de 2019
 *      Author: Neitan96
 */

#ifndef SIMPLEMILLISECONDSTEST
#define SIMPLEMILLISECONDSTEST

#include "../../heads/SimpleCalendarBase.h"
#include "../heads/SimpleMillisecondsTest.h"

/* Adds */

void scMilliAddSecondTest();
void scMilliAddMinuteTest();
void scMilliAddHourTest();
void scMilliAddMonthDayTest();
void scMilliAddMonthTest();
void scMilliAddYearTest();
void scMilliAddWeekTest();

/* Sets */

void scMilliSetMillisecondTest();
void scMilliSetSecondTest();
void scMilliSetMinuteTest();
void scMilliSetHourTest();
void scMilliSetMonthDayTest();
void scMilliSetMonthTest();
void scMilliSetYearTest();
void scMilliJumpToWeekDayTest();
void scMilliJumpToWeekMonthTest();
void scMilliJumpToWeekYearTest();

/* Gets */

void scMilliGetWeekDayTest();
void scMilliGetYearDayTest();
void scMilliGetWeekMonthTest();
void scMilliGetWeekYearTest();

/* Counts */

void scMilliCountMonthDayTest();
void scMilliCountHourTest();
void scMilliCountMinuteTest();
void scMilliCountSecondTest();

/* Outros */

void scTestMilliseconds();

#endif /* SIMPLEMILLISECONDSTEST */
