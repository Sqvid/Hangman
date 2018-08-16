CC=gcc
CFLAGS=-Wall --std=c99
LDFLAGS=-lncurses
OBJ=hangman.o parser.o #graphics.o
EXE=hangman
TXT=wordlist.txt
DBGFLAGS=-g

all: $(EXE)

debug: CFLAGS+=$(DBGFLAGS)
debug: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ $(LDFLAGS)

.PHONY: clean uncluttered package

clean:
	rm hangman
	rm *.o

uncluttered:
	rm *.o

package:
	make
	zip $(EXE).zip *.c *.h Makefile $(EXE) $(TXT)
	make uncluttered
