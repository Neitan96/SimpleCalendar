/*
 * SimpleMillisecondsCount.c
 *
 *  Created on: 18 de ago de 2019
 *      Author: Nathan Almeida
 */

#include "SimpleMilliseconds.h"
#include "../Base/SimpleCalendarBase.h"

long int scMilliCountMonthDay(Milliseconds milliseconds) {
    return (long int) (milliseconds / DAY_IN_MILLISECONDS);
}

long int scMilliCountHour(Milliseconds milliseconds) {
    return (long int) (milliseconds / HOUR_IN_MILLISECONDS);
}

long long int scMilliCountMinute(Milliseconds milliseconds) {
    return milliseconds / MINUTE_IN_MILLISECONDS;
}

long long int scMilliCountSecond(Milliseconds milliseconds) {
    return milliseconds / SECONDS_IN_MILLISECONDS;
}