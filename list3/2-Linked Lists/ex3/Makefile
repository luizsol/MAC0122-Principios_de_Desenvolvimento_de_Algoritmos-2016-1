.DEFAULT_GOAL := main

lists.o: lists.c lists.h
	gcc -std=gnu99 -c lists.c

parse.o: lists.h parse.c parse.h
	gcc -std=gnu99 -c parse.c

main.o: main.c parse.h lists.h
	gcc -std=gnu99 -c main.c

main: main.o parse.o lists.o
	gcc -std=gnu99 main.o parse.o lists.o -o main

clean:
	rm main *.o
