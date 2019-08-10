
SRC=./src
HEADS=./heads
TESTSSRC=./tests/src
TESTSHEADS=./tests/heads

OBJ=./obj
OBJTESTS=./objtests
LIBS=./lib

FLAGS= -O3 -Wall -std=c99
FLAGSLIB= -lsimplecalendar -L $(LIBS)

makedir:
	mkdir -p $(OBJ)
	mkdir -p $(OBJTESTS)
	mkdir -p $(LIBS)

%.o: $(SRC)/%.c
	gcc -c $< -I $(HEADS) $(FLAGS) -o $(OBJ)/$@

all: makedir \
	SimpleCalendarBase.o \
	SimpleMilliseconds.o \
	SimpleCalendar.o \
	SimpleExtract.o \
	SimpleConverts.o

lib: all
	ar -rcs $(LIBS)/libsimplecalendar.a $(OBJ)/*.o

tests: lib

	gcc -c $(TESTSSRC)/SimpleMillisecondsTest.c -I $(HEADS) -I $(TESTSHEADS) $(FLAGS) -o $(OBJTESTS)/SimpleMillisecondsTest.o
	gcc $(TESTSSRC)/SimpleTestBase.c $(LIBS)/libsimplecalendar.a $(OBJTESTS)/*.o -I $(HEADS) -I $(TESTSHEADS) $(FLAGS) $(FLAGSLIB) -o $(OBJTESTS)/SimpleCalendar

run: tests

	$(OBJTESTS)/SimpleCalendar

clean:
	rm -Rf $(OBJ)
	rm -Rf $(OBJTESTS)
	rm -Rf $(LIBS)