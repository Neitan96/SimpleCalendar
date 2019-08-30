# Manual

### Iniciando

A primeira coisa à fazer é criar uma váriavel Milliseconds ou Calendar, como o nome já diz Milliseconds representa um millisegundos e Calendar representa uma data e hora em números inteiros.

Exemplo: 
```C
Milliseconds milissegundos = 1569165720000;
Calendar calendario = scMakeCalendar(2019, 08, 22, 15, 22, 00, 000);
```

*OBS: Os Mêses começa do 0, então 8 equivale ao mês de setembro.*

### Conversão

Você pode também converter os tipos de calendário, pelo [SimpleConverts.h](src/Convert/SimpleConverts.h).

Exemplo:
```C
Calendar calendario = scMillisecondsToCalendar(milissegundos);

Milliseconds milissegundos = scCalendarToMilliseconds(calendario);
```

### Funções básicas

Todas funções dessa biblioteca tem o prefixo **sc**, caso queria fazer cálculos com Milliseconds o prefixo é **scMilli** ou **scCal** para cálculos com Calendar.

A funções bases para usar com os dois tipos de variaveis são:

#### Para fazer somas e subtração na data e hora.

*OBS: Para fazer uma subtração passe um valor negativo.*

* AddSecond(Milliseconds/Calendar, int second)
* AddMinute(Milliseconds/Calendar, int minute)
* AddHour(Milliseconds/Calendar, int hour)
* AddMonthDay(Milliseconds/Calendar, int monthDay)
* AddMonth(Milliseconds/Calendar, int month)
* AddYear(Milliseconds/Calendar, int year)
* AddWeek(Milliseconds/Calendar, int week)

#### Para definir um valor na data e hora.

*Essas funções serve para definir um valor sem mecher nos outros valores, podendo avançar ou retroceder no tempo.*

* SetMillisecond(Milliseconds/Calendar, int millisecond)
* SetSecond(Milliseconds/Calendar, int second)
* SetMinute(Milliseconds/Calendar, int minute)
* SetHour(Milliseconds/Calendar, int hour)
* SetMonthDay(Milliseconds/Calendar, int monthDay)
* SetMonth(Milliseconds/Calendar, int month)
* SetYear(Milliseconds/Calendar, int year)
* SetWeekDay(Milliseconds/Calendar, int weekDay)
* SetWeekMonth(Milliseconds/Calendar, int weekCount)
* SetWeekYear(Milliseconds/Calendar, int weekCount)

#### Para ir para o próximo valor na data e hora.

*Essas funções nunca irão retroceder no tempo sempre vai avançar para o próximo valor definido.*


* NextMillisecond(Milliseconds/Calendar, int millisecond)
* NextSecond(Milliseconds/Calendar, int second)
* NextMinute(Milliseconds/Calendar, int minute)
* NextHour(Milliseconds/Calendar, int hour)
* NextMonthDay(Milliseconds/Calendar, int monthDay)
* NextMonth(Milliseconds/Calendar, int month)
* NextWeekDay(Milliseconds/Calendar, int weekDay)
* NextWeekMonth(Milliseconds/Calendar, int weekCount, int keepWeekDay)
* NextWeekYear(Milliseconds/Calendar, int weekCount, int keepWeekDay)

#### Para obter algumas informações sobre a data e hora.

* GetWeekDay(Milliseconds/Calendar)
* GetYearDay(Milliseconds/Calendar)
* GetWeekMonth(Milliseconds/Calendar)
* GetWeekYear(Milliseconds/Calendar)

#### Cálcular a diferença entre duas datas e hora.

* DiffYear(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffMonth(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffMonthDay(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffHour(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffMinute(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffSecond(Milliseconds/Calendar, Milliseconds/Calendar);
* DiffMilliecond(Milliseconds/Calendar, Milliseconds/Calendar);

#### Algumas funções extras.

* Compare(Milliseconds/Calendar, Milliseconds/Calendar)

TODO Terminar manual