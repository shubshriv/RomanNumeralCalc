#
# Makefile for the romanCalc library and the test file - testRomanCalc
# Author: Shubham Shrivastava
#

# compiler	
CC = gcc

# compile flags
CFLAGS = -Wall -c

# extra compile flags
EXTRA_CFLAGS =

# link flags
LFLAGS = -Wall

# source files:
SRCS = 	testRomanCalc.c \
		romanCalc.c \
		romanCalcFunc.c
		

# the build target executable:
BIN = testRomanCalc

# object files
OBJS = 	$(SRCS:.c=.o)

# libraries
LIBS = 

# tool to use for clean
RM = rm -f

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o $(BIN)
	
testRomanCalc.o: testRomanCalc.c \
				romanCalc.h
				$(CC) $(CFLAGS) $(EXTRA_CFLAGS) testRomanCalc.c	

romanCalc.o: romanCalc.c \
			romanCalc.h
			$(CC) $(CFLAGS) $(EXTRA_CFLAGS) romanCalc.c
			
romanCalcFunc.o: romanCalcFunc.c \
				romanCalc.h
				$(CC) $(CFLAGS) $(EXTRA_CFLAGS) romanCalcFunc.c			

clean:
	$(RM) $(OBJS) $(BIN)

