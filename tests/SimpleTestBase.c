/*
 * SimpleTestBase.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include <stdio.h>
#include <stdarg.h>
#include "../heads/SimpleCalendarBase.h"

char* testNameNow;
char* fileNow;

int testNumberNow = 0;
int subTestNumberNow = 0;
int totalSubTest = 0;
int totalFailsSubTest = 0;


void scTError(int line, char* params){
	totalFailsSubTest++;
	printf("\n\nTEST FAIL-> File: %s,\n            Line: %i, Test: %s, Sub-Test: %i\n            Params: %s\n",
			fileNow, line, testNameNow, subTestNumberNow, params);
}


void setNewTest(char* testName, char* file){
	testNameNow = testName;
	fileNow = file;
	testNumberNow++;
	subTestNumberNow = 0;
}

void scTFinalizeTests(){
	printf("\nFinished tests: Total: %i, Total subs: %i, Sucess: %i, Fails: %i",
			testNumberNow, totalSubTest, totalSubTest-totalFailsSubTest, totalFailsSubTest);
}

void scTExecuteAllTests(){
	scTestMilliseconds();
}


void scTEqualMilli(int line, Milliseconds m1, Milliseconds m2){
	subTestNumberNow++;
	totalSubTest++;
	if(m1 != m2){
		char params[50];
		sprintf(&params, "%lli, %lli", m1, m2);
		scTError(line, params);
	}
}

int main() {
	scTExecuteAllTests();
	scTFinalizeTests();
}

