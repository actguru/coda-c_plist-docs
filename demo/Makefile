# 07/17/2024
UNAME := $(shell uname)
OSCF =
CC = gcc

ifeq ($(UNAME), Darwin)
$(info Make for APPLE, uname = $(UNAME))
CC = clang
OSCF = -mmacosx-version-min=10.8 -arch x86_64
endif

CFILES := $(wildcard *.c)

OFILES = $(CFILES:.c=.o)

CFLAGS = $(OSCF) -fPIC -std=gnu17 -g0 -O1 -Wall -Wfatal-errors

default: all

TESTER = demo

PLISTS = plist1.plist plist5.plist plist6.plist plist7.plist plist8.plist plist9.plist

$(TESTER): $(CFILES)
	$(CC) -std=gnu17 -g0 -Wfatal-errors -Wall -O1 $(CFILES) -lcoda-c_plist -o $(TESTER) -lm

test: $(TESTER)
	./demo

all: $(TESTER)

clean:
	rm -f $(OFILES) $(TESTER) $(TESTER).exe
	rm -f $(PLISTS)

.PHONY:  all clean test default

