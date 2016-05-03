/** @file 	main.c
 *  @brief 	Calculates the value of k to the power of n recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Calculates the value of k to the power of n
 *
 *  @param k the base of the operation
 *  @param n the exponent of the operation
 *  @return k^n
 */
int power(int k, int n){
	return (n == 0 ? 1 : k*power(k, n-1));
}

/** @brief Gets the values of k and n from the user
 *
 *  @param v the address of v
 *  @param n the address of n
 */
void get_values(int *k, int *n){
	printf("Type the value of k: ");
	char input[100];
	fgets(input, 100, stdin);
	*k = atoi(input);
	printf("Type the value of n: ");
	fgets(input, 100, stdin);
	*n = atoi(input);
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	int k, n;
	k = n = -1;
	
	if(argc == 3){
		k = atoi(argv[1]);
		n = atoi(argv[2]);
	} else if(argc == 1){
		get_values(&k, &n);
	}
	
	if(k < 0 || n < 0){
		fprintf(stderr, "Error: bad arguments. Exiting.\n");
		printf("Usage:\n./main <k> <n>\nor\n./main\nfor interactive mode\n");
		return 1;
	}
	
	printf("%d\n", power(k, n));
	return 0;
	
}
