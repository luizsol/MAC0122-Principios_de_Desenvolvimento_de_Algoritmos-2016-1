/** @file 	main.c
 *  @brief 	Simulates a given function wich turns out to be the n-th Fibonacci series value
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/03
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief The function to be simulated
 *
 *  @param n the argument of the function
 *  @return the value of the function
 */
int zzz(int n){
	int aux;
	if (n <= 2)
		return 1;
	n--;
	aux = zzz(n);
	n--;
	return aux + zzz(n);
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2 && atoi(argv[1])>0){
		printf("%d\n", zzz(atoi(argv[1])));
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <n>\n");
	return 1;
}
