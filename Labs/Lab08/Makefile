CC=gcc
CFLAGS=-std=c99 -Wall -Werror -g
SRC=c_mystery.c
OBJ=c_mystery.o
EXE=c_mystery

all: $(EXE)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

c_mystery: c_mystery.o
	$(CC) -o $@ $(OBJ)

clean:
	/bin/rm -f *.o *~ $(EXE)
