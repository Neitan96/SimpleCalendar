/*
 * SimpleTestBase.h
 *
 *  Created on: 12 de set de 2018
 *      Author: Neitan96
 */

#ifndef SIMPLETESTBASE
#define SIMPLETESTBASE


void scTError(int line, char* params);

void setNewTest(char* testName, char* file);

void scTFinalizeTests();

void scTExecuteAllTests();


void scTEqualMilli(int line, Milliseconds m1, Milliseconds m2);

#endif /* SIMPLETESTBASE */
