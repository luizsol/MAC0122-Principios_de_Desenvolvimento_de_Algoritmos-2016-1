/** @file 	main.c
 *  @brief 	Calculates the n-th numbers of the Tribonacci series recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/03
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Prints the countdown from n to 1
 *
 *  @param the value of the start of the conuntdown
 */
void contagemRegressiva(int n){
	if(n<1) return;
	printf("%d, ", n);
	contagemRegressiva(n-1);
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2 && atoi(argv[1])>0){
		contagemRegressiva(atoi(argv[1]));
		printf("Vai!!!\n");
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <n>\n");
	return 1;
}
