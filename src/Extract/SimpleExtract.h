/*
 * SimpleExtract.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef HEADS_SIMPLEEXTRACT
#define HEADS_SIMPLEEXTRACT

#include "../Base/SimpleCalendarBase.h"

/**
 * Extrai o ano e milisegundos do início desse ano.
 * Os outros valores ficam nulos.
 */
ExtractCalendar scExtractYearFromCalendar(Calendar calendar);

/**
 * Extrai o mês e milisegundos do início desse mês.
 * O dia, hora, minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMonthFromCalendar(Calendar calendar);

/**
 * Extrai o dia e milisegundos do início desse dia.
 * A hora, minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMonthDayFromCalendar(Calendar calendar);

/**
 * Extrai a hora e milisegundos do início dessa hora.
 * O minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractHourFromCalendar(Calendar calendar);

/**
 * Extrai o minuto e milisegundos do início desse minuto.
 * O segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMinuteFromCalendar(Calendar calendar);

/**
 * Extrai o segundo e milisegundos do início desse segundo.
 * O milisegundo do ExtractCalendar fica nulo.
 */
ExtractCalendar scExtractSecondFromCalendar(Calendar calendar);

/**
 * Extrai os milisegundos de um Calendar.
 */
ExtractCalendar scExtractFromCalendar(Calendar calendar);

/**
 * Extrai o ano e milisegundos do início desse ano.
 * Os outros valores ficam nulos.
 */
ExtractCalendar scExtractYearFromMilliseconds(Milliseconds milliseconds);

/**
 * Extrai o mês e milisegundos do início desse mês.
 * O dia, hora, minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMonthFromMilliseconds(Milliseconds milliseconds);

/**
 * Extrai o dia e milisegundos do início desse dia.
 * A hora, minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMonthDayFromMilliseconds(Milliseconds milliseconds);

/**
 * Extrai a hora e milisegundos do início dessa hora.
 * O minuto, segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractHourFromMilliseconds(Milliseconds milliseconds);

/**
 * Extrai o minuto e milisegundos do início desse minuto.
 * O segundo e milisegundo do ExtractCalendar ficam nulos.
 */
ExtractCalendar scExtractMinuteFromMilliseconds(Milliseconds milliseconds);

/**
 * Extrai o segundo e milisegundos do início desse segundo.
 * O milisegundo do ExtractCalendar fica nulo.
 */
ExtractCalendar scExtractSecondFromMilliseconds(Milliseconds milliseconds);

/**
 * Detalha a data e hora de um Milliseconds.
 */
ExtractCalendar scExtractFromMilliseconds(Milliseconds milliseconds);


#endif /* HEADS_SIMPLEEXTRACT */
