
SRC=./src
HEADS=./heads
TESTSSRC=./tests/src
TESTSHEADS=./tests/heads
OBJ=./obj
APPS=./app

makedir:
	mkdir -p $(OBJ)
	mkdir -p $(APPS)

%.o: $(SRC)/%.c
	gcc -c $< -I $(HEADS) -o $(OBJ)/$@

all: makedir SimpleCalendarBase.o SimpleMilliseconds.o SimpleCalendar.o SimpleExtract.o SimpleConverts.o

tests: all

	gcc -c $(TESTSSRC)/SimpleMillisecondsTest.c -I $(HEADS) -I $(TESTSHEADS) -o $(OBJ)/SimpleMillisecondsTest.o
	gcc $(TESTSSRC)/SimpleTestBase.c $(OBJ)/*.o -I $(HEADS) -I $(TESTSHEADS) -o $(APPS)/SimpleCalendar

run: tests

	$(APPS)/SimpleCalendar

clean:
	rm -Rf $(OBJ)
	rm -Rf $(APPS)