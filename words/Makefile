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

default: runtest

TESTER = words

$(TESTER): $(CFILES)
	$(CC) -std=gnu17 -g0 -Wfatal-errors -Wall -O1 $(CFILES) -lcoda-c_plist -o $(TESTER) -lm

runtest: $(TESTER) # manual:  make runtest
	./$(TESTER) < $(CFILES)

clean:
	rm -f $(OFILES) $(TESTER) $(TESTER).exe words.plist # DOS

.PHONY:  default clean runtest

