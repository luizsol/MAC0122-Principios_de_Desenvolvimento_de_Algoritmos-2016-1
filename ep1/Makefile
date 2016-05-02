.DEFAULT_GOAL := main

parser.o: parser.c parser.h
	gcc -std=c99 -c parser.c

calcs.o: calcs.c calcs.h
	gcc -std=c99 -c calcs.c

main.o: main.c parser.c parser.h calcs.c calcs.h
	gcc -std=c99 -c main.c

main: parser.o main.o calcs.o
	gcc -std=c99 parser.o calcs.o main.o -o main

clean:
	rm *.o main
