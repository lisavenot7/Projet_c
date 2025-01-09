CC=gcc
CFLAGS=-W -Wall -Werror

prog: arbre.o testArbre.o tableaud.o sequence.o hash_x86_64.o list_x86_64.o 
	$(CC) arbre.o testArbre.o tableaud.o sequence.o hash_x86_64.o list_x86_64.o -o prog -lm

arbre.o: arbre.c arbre.h 
	$(CC) -c $(CFLAGS) arbre.c

testArbre.o: testArbre.c arbre.h 
	$(CC) -c $(CFLAGS) testArbre.c

tableaud.o: tableaud.c tableaud.h 
	$(CC) -c $(CFLAGS) tableaud.c

sequence.o: sequence.c sequence.h 
	$(CC) -c $(CFLAGS) sequence.c

clear:
	rm -f arbre.o testArbre.o tableaud.o sequence.o  prog








