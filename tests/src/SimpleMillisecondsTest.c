/*
 * SimpleMillisecondsTest.c
 *
 *  Created on: 31 de ago de 2018
 *      Author: Neitan96
 */

#include "../../src/Base/SimpleCalendarBase.h"
#include "../../src/Milliseconds/SimpleMilliseconds.h"
#include "../heads/SimpleTestBase.h"


/* Adds */

void scMilliAddSecondTest(){
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
void scMilliAddWeekTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;
	scMilliAddWeek(&milliseconds, 1);
	//Sep 29 2019 15:22:00
	scTEqualMilli(__LINE__, 1569770520000, milliseconds);

	//Sep 22 2019 15:22:00
	milliseconds = 1569165720000;
	scMilliAddWeek(&milliseconds, 100);
	//Aug 22 2021 15:22:00
	scTEqualMilli(__LINE__, 1629645720000, milliseconds);

	//Sep 22 2019 15:22:00
	milliseconds = 1569165720000;
	scMilliAddWeek(&milliseconds, -25);
	//Mar 31 2019 15:22:00
	scTEqualMilli(__LINE__, 1554045720000, milliseconds);
}

/* Sets */

void scMilliSetMillisecondTest(){
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
	setNewTest((char*) __func__, __FILE__);

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
void scMilliSetWeekDayTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 26 2019 15:22:00
	Milliseconds milliseconds = 1569511320000;

	scMilliSetWeekDay(&milliseconds, TUESDAY);
	//Sep 24 2019 15:22:00
	scTEqualMilli(__LINE__, 1569338520000, milliseconds);

	scMilliSetWeekDay(&milliseconds, SATURDAY);
	//Sep 28 2019 15:22:00
	scTEqualMilli(__LINE__, 1569684120000, milliseconds);

	scMilliSetWeekDay(&milliseconds, SUNDAY);
	//Sep 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1569165720000, milliseconds);
}
void scMilliSetWeekMonthTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliSetWeekMonth(&milliseconds, 1);
	//Sep 01 2019 15:22:00
	scTEqualMilli(__LINE__, 1567351320000, milliseconds);

	scMilliSetWeekMonth(&milliseconds, 2);
	//Sep 08 2019 15:22:00
	scTEqualMilli(__LINE__, 1567956120000, milliseconds);

	scMilliSetWeekMonth(&milliseconds, 3);
	//Sep 15 2019 15:22:00 
	scTEqualMilli(__LINE__, 1568560920000, milliseconds);

}
void scMilliSetWeekYearTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliSetWeekYear(&milliseconds, 1);
	//Jan 01 2019 15:22:00
	scTEqualMilli(__LINE__, 1546356120000, milliseconds);

	scMilliSetWeekYear(&milliseconds, 20);
	//May 12 2019 15:22:00
	scTEqualMilli(__LINE__, 1557674520000, milliseconds);

	scMilliSetWeekYear(&milliseconds, 39);
	//Sep 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1569165720000, milliseconds);

}

/* Next */

void scMilliNextMillisecondTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00 000
	Milliseconds milliseconds = 1569165720000;

	scMilliNextMillisecond(&milliseconds, 500);
	//Sep 22 2019 15:22:00 500
	scTEqualMilli(__LINE__, 1569165720500, milliseconds);

	scMilliNextMillisecond(&milliseconds, 400);
	//Sep 22 2019 15:22:01 400
	scTEqualMilli(__LINE__, 1569165721400, milliseconds);

	scMilliNextMillisecond(&milliseconds, 999);
	//Sep 22 2019 15:22:01 999
	scTEqualMilli(__LINE__, 1569165721999, milliseconds);
}
void scMilliNextSecondTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextSecond(&milliseconds, 30);
	//Sep 22 2019 15:22:30
	scTEqualMilli(__LINE__, 1569165750000, milliseconds);

	scMilliNextSecond(&milliseconds, 20);
	//Sep 22 2019 15:23:20
	scTEqualMilli(__LINE__, 1569165800000, milliseconds);

	scMilliNextSecond(&milliseconds, 59);
	//Sep 22 2019 15:23:59
	scTEqualMilli(__LINE__, 1569165839000, milliseconds);
}
void scMilliNextMinuteTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextMinute(&milliseconds, 30);
	//Sep 22 2019 15:30:00
	scTEqualMilli(__LINE__, 1569166200000, milliseconds);

	scMilliNextMinute(&milliseconds, 20);
	//Sep 22 2019 16:20:00
	scTEqualMilli(__LINE__, 1569169200000, milliseconds);

	scMilliNextMinute(&milliseconds, 59);
	//Sep 22 2019 16:59:00
	scTEqualMilli(__LINE__, 1569171540000, milliseconds);
}
void scMilliNextHourTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextHour(&milliseconds, 20);
	//Sep 22 2019 20:22:00
	scTEqualMilli(__LINE__, 1569183720000, milliseconds);

	scMilliNextHour(&milliseconds, 12);
	//Sep 23 2019 12:22:00
	scTEqualMilli(__LINE__, 1569241320000, milliseconds);

	scMilliNextHour(&milliseconds, 23);
	//Sep 23 2019 23:22:00
	scTEqualMilli(__LINE__, 1569280920000, milliseconds);
}
void scMilliNextMonthDayTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextMonthDay(&milliseconds, 30);
	//Sep 30 2019 15:22:00
	scTEqualMilli(__LINE__, 1569856920000, milliseconds);

	scMilliNextMonthDay(&milliseconds, 7);
	//Oct 07 2019 15:22:00
	scTEqualMilli(__LINE__, 1570461720000, milliseconds);

	scMilliNextMonthDay(&milliseconds, 14);
	//Oct 14 2019 15:22:00
	scTEqualMilli(__LINE__, 1571066520000, milliseconds);
}
void scMilliNextMonthTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextMonth(&milliseconds, DECEMBER);
	//Dec 22 2019 15:22:00
	scTEqualMilli(__LINE__, 1577028120000, milliseconds);

	scMilliNextMonth(&milliseconds, AUGUST);
	//Aug 22 2020 15:22:00
	scTEqualMilli(__LINE__, 1598109720000, milliseconds);

	scMilliNextMonth(&milliseconds, MAY);
	//May 22 2021 15:22:00
	scTEqualMilli(__LINE__, 1621696920000, milliseconds);
}
void scMilliNextWeekDayTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextWeekDay(&milliseconds, THURSDAY);
	//Sep 26 2019 15:22:00
	scTEqualMilli(__LINE__, 1569511320000, milliseconds);

	scMilliNextWeekDay(&milliseconds, SATURDAY);
	//Sep 28 2019 15:22:00
	scTEqualMilli(__LINE__, 1569684120000, milliseconds);

	scMilliNextWeekDay(&milliseconds, SUNDAY);
	//Sep 29 2019 15:22:00 
	scTEqualMilli(__LINE__, 1569770520000, milliseconds);

}
void scMilliNextWeekMonthTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextWeekMonth(&milliseconds, 2, 1);
	//Oct 06 2019 15:22:00
	scTEqualMilli(__LINE__, 1570375320000, milliseconds);

	//Sep 28 2019 15:22:00
	milliseconds = 1569684120000;
	scMilliNextWeekMonth(&milliseconds, 2, 1);
	//Oct 12 2019 15:22:00
	scTEqualMilli(__LINE__, 1570893720000, milliseconds);

	//Nov 20 2019 15:22:00
	milliseconds = 1574263320000;
	scMilliNextWeekMonth(&milliseconds, 1, 1);
	//Dec 04 2019 15:22:00
	scTEqualMilli(__LINE__, 1575472920000, milliseconds);
}
void scMilliNextWeekYearTest(){
	setNewTest((char*) __func__, __FILE__);

	//Sep 22 2019 15:22:00
	Milliseconds milliseconds = 1569165720000;

	scMilliNextWeekYear(&milliseconds, 22, 1);
	//May 24 2020 15:22:00
	scTEqualMilli(__LINE__, 1590333720000, milliseconds);

	//Sep 28 2019 15:22:00
	milliseconds = 1569684120000;
	scMilliNextWeekYear(&milliseconds, 44, 1);
	//Nov 02 2019 15:22:00
	scTEqualMilli(__LINE__, 1572708120000, milliseconds);

	scMilliNextWeekYear(&milliseconds, 7, 0);
	//Feb 09 2020 15:22:00
	scTEqualMilli(__LINE__, 1581261720000, milliseconds);
}

/* Outros */

void scTestMilliseconds(){

	//Adds
	scMilliAddSecondTest();
	scMilliAddMinuteTest();
	scMilliAddHourTest();
	scMilliAddMonthDayTest();
	scMilliAddMonthTest();
	scMilliAddWeekTest();

	//Sets
	scMilliAddYearTest();
	scMilliSetMillisecondTest();
	scMilliSetSecondTest();
	scMilliSetMinuteTest();
	scMilliSetHourTest();
	scMilliSetMonthDayTest();
	scMilliSetMonthTest();
	scMilliSetYearTest();
	scMilliSetWeekDayTest();
	scMilliSetWeekMonthTest();
	scMilliSetWeekYearTest();

	//Next
	scMilliNextMillisecondTest();
	scMilliNextSecondTest();
	scMilliNextMinuteTest();
	scMilliNextHourTest();
	scMilliNextMonthDayTest();
	scMilliNextMonthTest();
	scMilliNextWeekDayTest();
	scMilliNextWeekMonthTest();
	scMilliNextWeekYearTest();
	
}
