/*
 * SimpleConverts.h
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLECONVERTS
#define SIMPLECONVERTS

#include "SimpleCalendarBase.h"


/**
 * Cria um Calendar a partir de um ano, mês, dia, hora, minuto, segundo e milisegundo.
 */
Calendar scMakeCalendar(int year, int month, int monthDay, int hour, int minute, int second, int millisecond);

/**
 * Converte Milliseconds em Calendar.
 */
Calendar scMillisecondsToCalendar(Milliseconds milliseconds);

/**
 * Converte ExtractCalendar em Calendar.
 */
Calendar scExtractToCalendar(ExtractCalendar extractCalendar);

/**
 * Cria um Milliseconds a partir de um ano, mês, dia, hora, minuto, segundo e milisegundo.
 */
Milliseconds scMakeMilliseconds(int year, int month, int monthDay, int hour, int minute, int second, int millisecond);

/**
 * Converte Calendar em Milliseconds.
 */
Milliseconds scCalendarToMilliseconds(Calendar calendar);

/**
 * Converte ExtractCalendar em Milliseconds.
 */
Milliseconds scExtractToMilliseconds(ExtractCalendar extractCalendar);

/**
 * Cria um ExtractCalendar a partir de um ano, mês, dia, hora, minuto, segundo e milisegundo.
 */
ExtractCalendar scMakeExtractCalendar(int year, int month, int monthDay, int hour, int minute, int second, int millisecond);

/**
 * Converte Calendar em ExtractCalendar.
 */
ExtractCalendar scCalendarToExtract(Calendar calendar);

/**
 * Converte Milliseconds em ExtractCalendar.
 */
ExtractCalendar scMillisecondsToExtract(Milliseconds milliseconds);


#endif /* SIMPLECONVERTS */
