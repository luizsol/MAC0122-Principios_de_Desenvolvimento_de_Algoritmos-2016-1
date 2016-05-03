/** @file 	main.c
 *  @brief 	Determines the sum from 1 to n
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Adds all the numbers between 1 and n
 *
 *  @param the delimiter value
 *  @return the result of the sum
 */
int sum(int n){
	return (n == 1 ? 1 : n + sum(n-1));
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2){
		int value = atoi(argv[1]);
		if(value > 0){
			printf("%d\n", sum(value));
			return 0;
		}
		printf("Error: <int1> must be greater than 0\n");
	}
	printf("Usage:\n./main <int1>\n");
	return 1;
}
