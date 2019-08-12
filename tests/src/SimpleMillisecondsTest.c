/*
 * SimpleMillisecondsTest.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include "../../heads/SimpleCalendarBase.h"
#include "../../heads/SimpleMilliseconds.h"
#include "../heads/SimpleTestBase.h"


/* Adds */

void scMilliAddSecondTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2018 15:22:00
	Milliseconds milliseconds = 1537629720000;
	scMilliAddSecond(&milliseconds, 22);
	scTEqualMilli(__LINE__, 1537629742000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddSecond(&milliseconds, 82);
	scTEqualMilli(__LINE__, 1537629802000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddSecond(&milliseconds, -82);
	scTEqualMilli(__LINE__, 1537629638000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddSecond(&milliseconds, -22);
	scTEqualMilli(__LINE__, 1537629698000, milliseconds);


}

void scMilliAddMinuteTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2018 15:22:00
	Milliseconds milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, 22);
	scTEqualMilli(__LINE__, 1537631040000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, 60);
	scTEqualMilli(__LINE__, 1537633320000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, 1462);
	scTEqualMilli(__LINE__, 1537717440000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, -22);
	scTEqualMilli(__LINE__, 1537628400000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, -60);
	scTEqualMilli(__LINE__, 1537626120000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMinute(&milliseconds, -1462);
	scTEqualMilli(__LINE__, 1537542000000, milliseconds);

}

void scMilliAddHourTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2018 15:22:00
	Milliseconds milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, 22);
	scTEqualMilli(__LINE__, 1537708920000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, 3);
	scTEqualMilli(__LINE__, 1537640520000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, 122);
	scTEqualMilli(__LINE__, 1538068920000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, -22);
	scTEqualMilli(__LINE__, 1537550520000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, -3);
	scTEqualMilli(__LINE__, 1537618920000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddHour(&milliseconds, -122);
	scTEqualMilli(__LINE__, 1537190520000, milliseconds);

}

void scMilliAddMonthDayTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2018 15:22:00
	Milliseconds milliseconds = 1537629720000;
	scMilliAddMonthDay(&milliseconds, 1);
	//Sep 23 2018 15:22:00
	scTEqualMilli(__LINE__, 1537716120000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMonthDay(&milliseconds, 30);
	//Oct 22 2018 15:22:00
	scTEqualMilli(__LINE__, 1540221720000, milliseconds);

	//Feb 22 2019 15:22:00
	milliseconds = 1550848920000;
	scMilliAddMonthDay(&milliseconds, 394);
	//Mar 22 2020 15:22:00
	scTEqualMilli(__LINE__, 1584890520000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMonthDay(&milliseconds, 60);
	//Nov 21 2018 15:22:00
	scTEqualMilli(__LINE__, 1542813720000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMonthDay(&milliseconds, -200);
	//Mar 06 2018 15:22:00
	scTEqualMilli(__LINE__, 1520349720000, milliseconds);

}

void scMilliAddMonthTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2018 15:22:00
	Milliseconds milliseconds = 1537629720000;
	scMilliAddMonth(&milliseconds, 12);
	//Sep 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1569165720000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMonth(&milliseconds, 3);
	//Dec 22 2018 15:22:00
	scTEqualMilli(__LINE__, 1545492120000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddMonth(&milliseconds, 16);
	//Jan 22 2020 15:22:00
	scTEqualMilli(__LINE__, 1579706520000, milliseconds);

	//Dec 22 2019 15:22:00
	milliseconds = 1577028120000;
	scMilliAddMonth(&milliseconds, 15);
	//Mar 22 2021 15:22:00
	scTEqualMilli(__LINE__, 1616426520000, milliseconds);

	//Dec 22 2019 15:22:00
	milliseconds = 1577028120000;
	scMilliAddMonth(&milliseconds, -15);
	//Sep 22 2018 15:22:00
	scTEqualMilli(__LINE__, 1537629720000, milliseconds);

}

void scMilliAddYearTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2565 15:22:00
	Milliseconds milliseconds = 18799312920000;
	scMilliAddYear(&milliseconds, -435);
	//Sep 22 2130 15:22:00
	scTEqualMilli(__LINE__, 5071994520000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddYear(&milliseconds, 465);
	//Sep 22 2483 15:22:00
	scTEqualMilli(__LINE__, 16211632920000, milliseconds);

	//Sep 22 2018 15:22:00
	milliseconds = 1537629720000;
	scMilliAddYear(&milliseconds, 4);
	//Sep 22 2022 15:22:00
	scTEqualMilli(__LINE__, 1663860120000, milliseconds);

}

/* Sets */

void scMilliSetMillisecondTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2565 15:22:00 000
	Milliseconds milliseconds = 18799312920000;
	scMilliSetMillisecond(&milliseconds, 560);
	//Sep 22 2565 15:22:00 560
	scTEqualMilli(__LINE__, 18799312920560, milliseconds);

	scMilliSetMillisecond(&milliseconds, 987);
	//Sep 22 2565 15:22:00 987
	scTEqualMilli(__LINE__, 18799312920987, milliseconds);

	scMilliSetMillisecond(&milliseconds, 265);
	//Sep 22 2565 15:22:00 265
	scTEqualMilli(__LINE__, 18799312920265, milliseconds);

	scMilliSetMillisecond(&milliseconds, 156);
	//Sep 22 2565 15:22:00 156
	scTEqualMilli(__LINE__, 18799312920156, milliseconds);

}

void scMilliSetSecondTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2565 15:22:00
	Milliseconds milliseconds = 18799312920000;

	scMilliSetSecond(&milliseconds, 50);
	//Sep 22 2565 15:22:50
	scTEqualMilli(__LINE__, 18799312970000, milliseconds);

	scMilliSetSecond(&milliseconds, 30);
	//Sep 22 2565 15:22:50
	scTEqualMilli(__LINE__, 18799312950000, milliseconds);

	scMilliSetSecond(&milliseconds, 40);
	//Sep 22 2565 15:22:50
	scTEqualMilli(__LINE__, 18799312960000, milliseconds);

}

void scMilliSetMinuteTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2565 15:22:00
	Milliseconds milliseconds = 18799312920000;

	scMilliSetMinute(&milliseconds, 50);
	//Sep 22 2565 15:50:00
	scTEqualMilli(__LINE__, 18799314600000, milliseconds);

	scMilliSetMinute(&milliseconds, 30);
	//Sep 22 2565 15:30:00
	scTEqualMilli(__LINE__, 18799313400000, milliseconds);

	scMilliSetMinute(&milliseconds, 40);
	//Sep 22 2565 15:40:00
	scTEqualMilli(__LINE__, 18799314000000, milliseconds);

}

void scMilliSetHourTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2565 15:22:00
	Milliseconds milliseconds = 18799312920000;

	scMilliSetHour(&milliseconds, 16);
	//Sep 22 2565 16:22:00
	scTEqualMilli(__LINE__, 18799316520000, milliseconds);

	scMilliSetHour(&milliseconds, 0);
	//Sep 22 2565 00:22:00
	scTEqualMilli(__LINE__, 18799258920000, milliseconds);

	scMilliSetHour(&milliseconds, 23);
	//Sep 22 2565 23:22:00
	scTEqualMilli(__LINE__, 18799341720000, milliseconds);

}

void scMilliSetMonthDayTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliSetMonthDay(&milliseconds, 16);
	//Sep 16 2019 15:22:00
	scTEqualMilli(__LINE__, 1568647320000, milliseconds);

	scMilliSetMonthDay(&milliseconds, 1);
	//Sep 01 2019 15:22:00
	scTEqualMilli(__LINE__, 1567351320000, milliseconds);

	scMilliSetMonthDay(&milliseconds, 30);
	//Sep 30 2019 15:22:00
	scTEqualMilli(__LINE__, 1569856920000, milliseconds);

}

void scMilliSetMonthTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliSetMonth(&milliseconds, JANUARY);
	//Jan 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1548170520000, milliseconds);

	scMilliSetMonth(&milliseconds, MARCH);
	//Mar 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1553268120000, milliseconds);

	scMilliSetMonth(&milliseconds, DECEMBER);
	//Dec 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1577028120000, milliseconds);

}

void scMilliSetYearTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliSetYear(&milliseconds, 2018);
	//Sep 22 2018 15:22:00
	scTEqualMilli(__LINE__, 1537629720000, milliseconds);

	scMilliSetYear(&milliseconds, 2022);
	//Sep 22 2022 15:22:00
	scTEqualMilli(__LINE__, 1663860120000, milliseconds);

	scMilliSetYear(&milliseconds, 2965);
	//Sep 22 2965 15:22:00
	scTEqualMilli(__LINE__, 31422093720000, milliseconds);

}

void scMilliJumpToWeekDayTest(){
	setNewTest(__func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliJumpToWeekDay(&milliseconds, THURSDAY);
	//Sep 26 2019 15:22:00
	scTEqualMilli(__LINE__, 1569511320000, milliseconds);

	scMilliJumpToWeekDay(&milliseconds, SATURDAY);
	//Sep 28 2019 15:22:00
	scTEqualMilli(__LINE__, 1569684120000, milliseconds);

	scMilliJumpToWeekDay(&milliseconds, SUNDAY);
	//Sep 29 2019 15:22:00 
	scTEqualMilli(__LINE__, 1569770520000, milliseconds);

}

void scTestMilliseconds(){

	//Adds
	scMilliAddSecondTest();
	scMilliAddMinuteTest();
	scMilliAddHourTest();
	scMilliAddMonthDayTest();
	scMilliAddMonthTest();

	//Sets
	scMilliAddYearTest();
	scMilliSetMillisecondTest();
	scMilliSetSecondTest();
	scMilliSetMinuteTest();
	scMilliSetHourTest();
	scMilliSetMonthDayTest();
	scMilliSetMonthTest();
	scMilliSetYearTest();
	scMilliJumpToWeekDayTest();
}
