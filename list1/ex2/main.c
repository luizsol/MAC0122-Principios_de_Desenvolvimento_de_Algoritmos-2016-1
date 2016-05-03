/** @file 	main.c
 *  @brief 	Calculates the sum of the first n numbers of the Fibonacci series recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/03
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Calculates the n-th number of the Fibonacci series
 *
 *  @param n the position of the number on the Fibonacci series
 *  @return the value of the number on the Fibonacci series
 */
int fib(int n){
	if(n <= 2) return 1;
	return fib(n-1) + fib(n-2);
}

/** @brief Calculates the sum of the first n numbers of the Fibonacci series
 *
 *  @param n the position of the number on the Fibonacci series
 *  @return the sum of the first n numbers of the Fibonacci series
 */
int sum(int n){
	return (n < 1 ? 0: fib(n) + sum(n-1));
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2 && atoi(argv[1])>0){
		printf("%d\n", sum(atoi(argv[1])));
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <n>\n");
	return 1;
}
