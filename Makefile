
SRC=./src
TEST=./tests
TESTS-SRC=$(TEST)/src
TESTS-HEADS=$(TEST)/heads

OBJ=./obj
OBJ-LIB=$(OBJ)/Lib
OBJ-TESTS=$(OBJ)/Tests
LIBS=./lib

FLAGS= -O3 -Wall -std=c99
FLAGSLIB= -lsimplecalendar -L $(LIBS)

clean:
	rm -Rf $(OBJ)
	rm -Rf $(LIBS)

makedir:
	mkdir -p $(OBJ-LIB)/Base
	mkdir -p $(OBJ-LIB)/Calendar
	mkdir -p $(OBJ-LIB)/Convert
	mkdir -p $(OBJ-LIB)/Extract
	mkdir -p $(OBJ-LIB)/Milliseconds
	mkdir -p $(OBJ-TESTS)
	mkdir -p $(LIBS)

%.compile:
	gcc -c $(SRC)/$*.c $(FLAGS) $(PARAMFLAGS) -o $(OBJ-LIB)/$*.o

compileobjects: clean makedir \
	Base/SimpleCalendarBase.compile \
	Calendar/SimpleCalendarAdd.compile \
	Calendar/SimpleCalendarGet.compile \
	Calendar/SimpleCalendarOthers.compile \
	Convert/SimpleConverts.compile \
	Extract/SimpleExtract.compile \
	Milliseconds/SimpleMillisecondsAdd.compile \
	Milliseconds/SimpleMillisecondsCount.compile \
	Milliseconds/SimpleMillisecondsGet.compile \
	Milliseconds/SimpleMillisecondsNext.compile \
	Milliseconds/SimpleMillisecondsOthers.compile \
	Milliseconds/SimpleMillisecondsSet.compile

compile: compileobjects
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ-LIB)/Base/*.o
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ-LIB)/Calendar/*.o
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ-LIB)/Convert/*.o
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ-LIB)/Extract/*.o
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ-LIB)/Milliseconds/*.o

%.compiletest:
	gcc -c $(TESTS-SRC)/$*.c -I $(TESTS-HEADS) $(FLAGS) $(PARAMFLAGS) -o $(OBJ-TESTS)/$*.o

compiletests: compile SimpleMillisecondsTest.compiletest
	gcc $(TESTS-SRC)/SimpleTestBase.c $(LIBS)/libsimplecalendar.a $(OBJ-TESTS)/*.o -I $(TESTS-HEADS) $(FLAGS) $(PARAMFLAGS) $(FLAGSLIB) -o $(OBJ-TESTS)/SimpleCalendar

compiledebug: 
	make PARAMFLAGS=-g compiletests

runtests: compiletests
	$(OBJ-TESTS)/SimpleCalendar