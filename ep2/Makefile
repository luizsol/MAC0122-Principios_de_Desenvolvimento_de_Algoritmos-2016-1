.DEFAULT_GOAL := main

#lists.o: lists.h lists.c
#	gcc -std=gnu11 -Wall -pedantic -c lists.c

data.o: data.h data.c
	gcc -std=gnu11 -Wall -pedantic -c data.c

interface.o: interface.c interface.h data.h
	gcc -std=gnu11 -Wall -pedantic -c interface.c

main.o: main.c interface.h
	gcc -std=gnu11 -Wall -pedantic -c main.c

all main: data.o interface.o main.o lists.o
	gcc -std=gnu11 -Wall -pedantic lists.o data.o interface.o main.o -o main

clean:
	rm *.o main
