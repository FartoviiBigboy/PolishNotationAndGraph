CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
EXPORT=../build/graph

all: graph.o stack.o lex_analyzer.o polish_notation.o
	$(CC) graph.o stack.o lex_analyzer.o polish_notation.o -o $(EXPORT)

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c -o graph.o

lex_analyzer.o: lex_analyzer.c lex_analyzer.h
	$(CC) $(CFLAGS) lex_analyzer.c -o lex_analyzer.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c -o stack.o

polish_notation.o: polish_notation.c polish_notation.h
	$(CC) $(CFLAGS) polish_notation.c -o polish_notation.o

clean:
	-rm -rf *.o ../build/*

rebuild: clean all