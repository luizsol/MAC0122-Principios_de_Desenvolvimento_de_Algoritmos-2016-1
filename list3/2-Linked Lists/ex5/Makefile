.DEFAULT_GOAL := main

lists.o: lists.c lists.h
	gcc -std=gnu99 -Wall -pedantic -c lists.c

parse.o: lists.h parse.c parse.h
	gcc -std=gnu99 -Wall -pedantic -c parse.c

main.o: main.c parse.h lists.h
	gcc -std=gnu99 -Wall -pedantic -c main.c

main: main.o parse.o lists.o
	gcc -std=gnu99 -Wall -pedantic main.o parse.o lists.o -o main

all:
	gcc -std=gnu99 -Wall -pedantic main.c lists.c parse.c -o main

clean:
	rm main *.o
