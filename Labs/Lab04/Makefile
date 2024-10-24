CC=gcc
CFLAGS=-Wall -Wfatal-errors -Werror -std=c99
LDLIBS=-lm
all: pcalc
node_test: node.o node_test.o node.h
stack_test: stack.o stack_test.o stack.h node.o node.h
pcalc: pcalc.o stack.o stack.h node.o node.h
clean:
	rm -f node_test *.o
	rm -f stack_test *.o
