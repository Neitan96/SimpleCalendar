# Estrutura

##### Structs

  * Milliseconds: É um typedef para long long int, utilizado para representar millisegundos.
  * Calendar: Representa uma data e hora utilizando variaveis do tipo inteiro.
  * ExtractTime: Feito para ser utilizado com o ExtractCalendar, ele serve para indicar o milissegundo de um determinado ponto da data/hora, exemplo se o ExtractTime representar um determinado ano, esse ano fica indicado na variável "value" e em "milliseconds" fica o milissegundo do início do ano, se representar um mês, esse mês fica indicado na variável "value" e em "milliseconds" fica o milissegundo do início do mês.
  * ExtractCalendar: É o conjunto de varios ExtractTime representando uma data e hora.

##### Cabeçalhos

- SimpleCalendarBase.h  
Cabeçalho base, contém structs e funções necessarias para outros cabeçalhos.

- SimpleConverts.h  
Funções para converter Milliseconds em Calendar ou ExtractCalendar e virse-versa.

- SimpleMilliseconds.h  
Funções que usa como base a struct Milliseconds para fazer cálculos de datas e horas.

- SimpleCalendar.h  
Funções que usa como base a struct Calendar para fazer cálculos de datas e horas.

- SimpleExtract.h
Funções que detalha a data e hora usando o ExtractCalendar, a data pode ser detalhada com Calendar ou Milliseconds.

##### Funções bases

- Orthes: Compare, DiffTime, ToString
- Adds: AddMillisecond, AddSecond, AddMinute, AddHour, AddMonthDay, AddMonth, AddYear, AddWeek
- Sets: SetTimeZone, SetMillisecond, SetSecond, SetMinute, SetHour, SetMonthDay, SetMonth, SetYear, SetWeekDay, SetWeekMonth, SetWeekYear
- Gets: GetYearDay, GetWeekDay, GetWeekMonth, GetWeekYear
- Counts: CountMonthDay, CountHour, CountMinute, CountSecond
