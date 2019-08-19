//
// Created by Neitan96 on 25/07/2018.
//

#include "SimpleCalendarBase.h"


int scIsLeapYear(int year) {
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}

int scTotalDaysInYear(int year) {
    return scIsLeapYear(year) ? 366 : 365;
}

Milliseconds scTotalDaysInYearMilli(int year) {
    return ((long long int) scTotalDaysInYear(year))*DAY_IN_MILLISECONDS;
}

int scTotalDaysInMonth(int year, int month) {
    static int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int monthDaysLeapYear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (scIsLeapYear(year))
        return monthDaysLeapYear[month];
    return monthDays[month];
}

Milliseconds scTotalDaysInMonthMilli(int year, int month) {
    return ((long long int) scTotalDaysInMonth(year, month))*DAY_IN_MILLISECONDS;
}

int scCountLeapYears(int yearStart, int yearEnd){
    int leapYears = 0;

    if(scIsLeapYear(yearStart)) leapYears++;
    if(yearEnd > yearStart) yearEnd--;

    int fourYearsStart = (yearStart - (yearStart%4))/4;
    int fourYearsEnd = (yearEnd - (yearEnd%4))/4;
    leapYears += fourYearsEnd-fourYearsStart;

    int oneHundredYearsStart = (yearStart - (yearStart%100))/100;
    int oneHundredYearsEnd = (yearEnd - (yearEnd%100))/100;
    leapYears -= oneHundredYearsEnd-oneHundredYearsStart;

    int fourHundredYearsStart = (yearStart - (yearStart%400))/400;
    int fourHundredYearsEnd = (yearEnd - (yearEnd%400))/400;
    leapYears += fourHundredYearsEnd-fourHundredYearsStart;

    return leapYears;
}
