# Simple Calendar
Simple Calendar é uma API simples para fazer cálculos com data e hora totalmente em C, podendo trabalhar tanto com milissegundos ou com a representação numérica da data e hora.

### Exemplos:

```C
	//Criando um Milliseconds para fazer cáulculos.
	Milliseconds milissegundos = 1569165720000;
	//Adicionando 12 horas
	scMilliAddHour(&milissegundos, 12);
	//Subtraindo 3 meses
	scMilliAddMonth(&milissegundos, -3);

	//Criando um Calendar para fazer cálculos.
	Calendar calendario = scMakeCalendar(2019, 09, 22, 15, 22, 00, 000);
	//Adicionando 20 dias
	scCalAddMonthDay(&calendario, 20);
	//Subtraindo 0 minutos
	scCalAddMinute(&calendario, -40);
```

### Links

[Estrutura base do projeto](Structure.md).  
[Manual](Manual.md).  