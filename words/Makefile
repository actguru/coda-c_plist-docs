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

TESTER = words

$(TESTER): $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -lcoda-c_plist -o $(TESTER) -lm

test: $(TESTER)
	./$(TESTER) < $(CFILES)

clean:
	rm -f $(OFILES) $(TESTER) $(TESTER).exe words.json

.PHONY:  default clean test

