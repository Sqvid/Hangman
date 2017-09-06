CC=gcc
CFLAGS=-Wall --std=c99
OBJ=hangman.o parser.o graphics.o
EXE=hangman
DBGFLAGS=-g

all: $(EXE)

debug: CFLAGS+=$(DBGFLAGS)
debug: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: clean uncluttered

clean:
	rm hangman
	rm *.o

uncluttered:
	rm *.o
