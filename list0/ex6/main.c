/** @file 	main.c
 *  @brief 	Calculates the value of k to the power of n recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Calculates the maximum common divisor between x and y
 *
 *  @param x the first value
 *  @param y the second value
 *  @return the maximum common divisor between x and y
 */
int mcd(int x, int y){
	return (y == 0 ? x : mcd(y, x%y));
}

/** @brief Gets the values of x and y from the user
 *
 *  @param x the address of x
 *  @param y the address of y
 */
void get_values(int *x, int *y){
	printf("Type the value of x: ");
	char input[100];
	fgets(input, 100, stdin);
	*x = atoi(input);
	printf("Type the value of y: ");
	fgets(input, 100, stdin);
	*y = atoi(input);
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	int x, y;
	y = x = -1;
	
	if(argc == 3){
		x = atoi(argv[1]);
		y = atoi(argv[2]);
	} else if(argc == 1){
		get_values(&x, &y);
	}
	
	if(x < 0 || y < 0){
		fprintf(stderr, "Error: bad arguments. Exiting.\n");
		printf("Usage:\n./main <x> <y>\nor\n./main\nfor interactive mode\n");
		return 1;
	}
	
	printf("%d\n", mcd(x, y));
	return 0;
	
}
