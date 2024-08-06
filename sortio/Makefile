# 08/05/2024

UNAME := $(shell uname)
OSCF =
CC = gcc

ifeq ($(UNAME), Darwin)
CC = clang
OSCF = -mmacosx-version-min=10.8 -arch x86_64
endif

CFILES := $(wildcard *.c)

OFILES = $(CFILES:.c=.o)

CFLAGS = $(OSCF) -fPIC -std=gnu17 -g0 -O1 -Wall -Wfatal-errors

default: test

TESTER = sortio

$(TESTER): $(CFILES)
	$(CC)  $(CFLAGS) $(CFILES) -lcoda-c_plist -o $(TESTER) -lm

test: $(TESTER)
	./$(TESTER) < $(CFILES)

test2: $(TESTER)
	printf "a\n1\n5\n3\n7\nX\nY\nZ\nb\nc" | ./$(TESTER)

clean:
	rm -f $(OFILES) $(TESTER) $(TESTER).exe

.PHONY:  default clean test test2

