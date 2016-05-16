.DEFAULT_GOAL := main

list.o: list.c list.h
	gcc -std=gnu99 -Wall -pedantic -c list.c
	
main.o: main.c
	gcc -std=gnu99 -Wall -pedantic -c main.c
	
main: main.o list.o
	gcc -std=gnu99 -Wall -pedantic list.o main.o -o main
	
clean:
	rm *.o main
