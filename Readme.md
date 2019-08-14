# Simple Calendar
Simple Calendar é uma API simples para fazer cálculos com data e hora totalmente em C, podendo trabalhar tanto com milissegundos ou com a representação numérica da data e hora.

### Exemplos:

Funções com milissegundos:
```C
    Milliseconds dataHora = 1569165720000;

    //Adicionando 12 horas
    scMilliAddHour(&dataHora, 12);

    //Subtraindo 3 meses
    scMilliAddMonth(&dataHora, -3);

    //Definindo o ano como 2020
    scMilliSetYear(&dataHora, 2020);

    //Indo para o próximo sábado
	scMilliNextWeekDay(&dataHora, SATURDAY);
```

Funções com Calendar:
```C
    // 22/09/2019 15:22:00 000
    Calendar dataHora = scMakeCalendar(2019, 09, 22, 15, 22, 00, 000);

    //Adicionando 20 dias
    scCalAddMonthDay(&dataHora, 20);

    //Subtraindo 0 minutos
    scCalAddMinute(&dataHora, -40);

    //Definindo a hora como 12
    scCalSetHour(&dataHora, 12);

    //Indo para a próxima segunda semana do ano
	scCalNextWeekYear(&dataHora, 2);

    //Imprimindo a data
    printf("%i/%i/%i", dataHora.monthDay, dataHora.month+1, dataHora.year)
```

Outras funções:

```C
    //Convertendo Milliseconds para Calendar
    Calendar dataHora = scMillisecondsToCalendar(1569165720000);

    //Convertendo Calendar para Milliseconds
    Milliseconds dataHoraMilli = scCalendarToMilliseconds(dataHora);
```

Clique [aqui](structure.md) saber mais sobre a estrutura do projeto.