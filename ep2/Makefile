.DEFAULT_GOAL := main

data.o: data.h data.c
	gcc -std=gnu99 -Wall -pedantic -c parser.c

interface.o: interface.c interface.h data.h
	gcc -std=gnu99 -Wall -pedantic -c interface.c

main.o: main.c interface.h
	gcc -std=gnu99 -Wall -pedantic -c main.c

all main: data.o interface.o main.o
	gcc -std=gnu99 -Wall -pedantic data.o interface.o main.o -o main

clean:
	rm *.o main
