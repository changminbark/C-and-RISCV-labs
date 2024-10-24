CC=gcc
CFLAGS=-std=c99 -Wall -Werror -g
#SRC=fsm.c tokens.c
#OBJ=fsm.o tokens.o
#EXE=fsm
#SRC=sha_sum.c sha256.c
#OBJ=sha_sum.o sha256.o
#EXE=sha_sum
SRC=speller.c better_dictionary.c
OBJ=speller.o better_dictionary.o
EXE=speller

all: $(EXE)

%.o: %.c dictionary.h
	$(CC) $(CFLAGS) -c $< -o $@

fsm: fsm.o tokens.o
	$(CC) -o $@ $(OBJ)

sha_sum: sha_sum.o sha256.o
	$(CC) -o $@ $(OBJ)

speller: speller.o better_dictionary.o
	$(CC) -o $@ $(OBJ)

clean:
	#/bin/rm -f *.o *~ $(EXE)
