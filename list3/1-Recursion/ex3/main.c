/** @file 	main.c
 *  @brief 	Simulates a misterious function
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/03
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief The function to be simulated (a very forced implementation of recursion)
 *
 *  @param n the argument of the function
 *  @return the value of the function
 */
int fd(int x, int n){
	int z;
	if (n == 0) return 1;
	z = fd(x, n/2);
	z = z*z;
	if (n%2 == 1) z = z*x;
	return z;
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 3 && atoi(argv[1])>=0 && atoi(argv[2])>=0){
		printf("%d\n", fd(atoi(argv[1]), atoi(argv[2])));
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <x> <n>\n");
	return 1;
}
