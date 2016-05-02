.DEFAULT_GOAL := main

parser.o: parser.c parser.h
	gcc -std=c99 -c parser.c

main.o: main.c parser.c parser.h
	gcc -std=c99 -c main.c

main: parser.o main.o
	gcc -std=c99 parser.o main.o -o main

clean:
	rm *.o main
