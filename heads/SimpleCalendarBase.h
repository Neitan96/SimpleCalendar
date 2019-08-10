//
// Created by Neitan96 on 25/07/2018.
//

#ifndef SIMPLECALENDARBASE
#define SIMPLECALENDARBASE

#define _1600_TO_1970_IN_MILLISECONDS 11676009600000
#define FOUR_HUNDRED_YEARS_IN_MILLISECONDS 12622780800000
#define ONE_HUNDRED_YEARS_IN_MILLISECONDS 3155673600000
#define FOUR_YEARS_IN_MILLISECONDS 126230400000
#define YEAR_365_IN_MILLISECONDS 31536000000
#define YEAR_366_IN_MILLISECONDS 31622400000
#define MONTH_28_IN_MILLISECONDS 2419200000
#define MONTH_29_IN_MILLISECONDS 2505600000
#define MONTH_30_IN_MILLISECONDS 2592000000
#define MONTH_31_IN_MILLISECONDS 2678400000
#define DAY_IN_MILLISECONDS 86400000
#define HOUR_IN_MILLISECONDS 3600000
#define MINUTE_IN_MILLISECONDS 60000
#define SECONDS_IN_MILLISECONDS 1000

#define SUNDAY 0
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6

#define JANUARY 0
#define FEBRUARY 1
#define MARCH 2
#define APRIL 3
#define MAY 4
#define JUNE 5
#define JULY 6
#define AUGUST 7
#define SEPTEMBER 8
#define OCTOBER 9
#define NOVEMBER 10
#define DECEMBER 11

/*
 * Structs
 */

typedef long long int Milliseconds;

typedef struct Calendar {
	int timeZone;
    int year;
    int month;
    int monthDay;
    int hour;
    int minute;
    int second;
    int millisecond;
} Calendar;

typedef struct ExtractTime {
    int value;
    Milliseconds milliseconds;
} ExtractTime;

typedef struct ExtractCalendar {
    ExtractTime year;
    ExtractTime month;
    ExtractTime monthDay;
    ExtractTime hour;
    ExtractTime minute;
    ExtractTime second;
    ExtractTime millisecond;
} ExtractCalendar;


/*
 * Helper
 */

/**
 * Verifica se é um ano bissexto.
 * @year: Ano a ser verificado
 *
 * Caso retorne a 0 o ano tem 365 dias, caso retorne 1 o ano tem 366 dias.
 */
int scIsLeapYear(int year);

/**
 * Retorna a quantidade de dias do ano.
 */
int scTotalDaysInYear(int year);

/**
 * Retorna a quantidade de dias do ano em milisegundos.
 */
Milliseconds scTotalDaysInYearMilli(int year);

/**
 * Retorna a quantidade de dias do mês.
 */
int scTotalDaysInMonth(int year, int month);

/**
 * Retorna a quantidade de dias do mês em milisegundos.
 */
Milliseconds scTotalDaysInMonthMilli(int year, int month);

/**
 * Conta a quantidade de anos bissextos em um intervalo de anos.
 * @yearStart: Início do intervalo, esse ano será contado se for um ano bissexto.
 * @yearEnd: Fim do intervalo, mesmo se esse ano for bissexto ele não será contado.
 */
int scCountLeapYears(int yearStart, int yearEnd);

#endif //SIMPLECALENDARBASE

