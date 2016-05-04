/** @file 	main.c
 *  @brief 	Calculates the coordinates of a given value on a "zig-zag" like table
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/03
 */

#include <stdio.h>
#include <stdlib.h>

///The current coordinates of the list sweep
int coords[2] = {0,0}; //{X,Y}
///The value of the current coordinate
int sum = 0;

/** @brief The function to be simulated (a very forced implementation of recursion)
 *
 *  @param n the argument of the function
 *  @return the value of the function
 */
int *tabela(int n){
	if (n == sum) return coords;
	if (coords[0] == 0){
		coords[0] = coords[1]+1;
		coords[1] = 0;	
	} else {
		coords[0] -= 1;
		coords[1] += 1;
	}
	sum++;
	return tabela(n);
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2 && atoi(argv[1])>=0){
		printf("(%d,%d)\n", tabela(atoi(argv[1]))[0], tabela(atoi(argv[1]))[1]);
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <n>\n");
	return 1;
}
