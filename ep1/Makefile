.DEFAULT_GOAL := main

parser.o: parser.c parser.h
	gcc -std=gnu99 -Wall -pedantic -c parser.c

calcs.o: calcs.c calcs.h
	gcc -std=gnu99 -Wall -pedantic -c calcs.c

main.o: main.c parser.c parser.h calcs.c calcs.h
	gcc -std=gnu99 -Wall -pedantic -c main.c

all main: parser.o main.o calcs.o
	gcc -std=gnu99 -Wall -pedantic parser.o calcs.o main.o -o main

clean:
	rm *.o main
