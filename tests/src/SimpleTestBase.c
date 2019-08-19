/*
 * SimpleTestBase.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include "../../src/Base/SimpleCalendarBase.h"
#include "../heads/SimpleMillisecondsTest.h"

char* testNameNow;
char* fileNow;

int testNumberNow = 0;
int subTestNumberNow = 0;
int totalSubTest = 0;
int totalFailsSubTest = 0;

double executionTime;


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
	if(totalFailsSubTest < 1){
		printf("\n\033[1;32m# Successful tests!!!\033[0m");
	}else{
		printf("\n\033[1;31m# Failed Testing!!!\033[0m");
	}

	printf("\n\033[1;35mResult tests\033[0m: ");
	printf("\n        #Total tests: \033[1;36m%i\033[0m, ", testNumberNow);
	printf("\n        #Total sub-tests: \033[01;33m%i\033[0m, ", totalSubTest);
	printf("\n        #Sucess: \033[1;32m%i\033[0m, ", totalSubTest-totalFailsSubTest);
	printf("\n        #Fails: \033[1;31m%i\033[0m", totalFailsSubTest);

	printf("\nTests finished in \033[1;33m%g milliseconds\033[0m", executionTime);
}

void scTExecuteAllTests(){
	scTestMilliseconds();
}


void scTEqualMilli(int line, Milliseconds m1, Milliseconds m2){
	subTestNumberNow++;
	totalSubTest++;
	if(m1 != m2){
		char params[50];
		sprintf(params, "%lli, %lli", m1, m2);
		scTError(line, params);
	}
}

int main() {
    clock_t start = clock();

	scTExecuteAllTests();

	clock_t end = clock();
	executionTime = (end - start) * 1000.0 / CLOCKS_PER_SEC;

	scTFinalizeTests();
	printf("\n");
}

