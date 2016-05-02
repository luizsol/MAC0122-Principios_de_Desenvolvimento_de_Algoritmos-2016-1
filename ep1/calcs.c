/** @file	calcs.c
 *  @brief	Functions that hadle the optimization calculations and presentation
 * 		Source: MAC0122 - University of São Paulo
 * 		Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/04/30
 */

#include "calcs.h"
#include <stdio.h>

extern int n;
extern int ** s;
extern int e[2][1];
extern int x[2][1];
extern int ** t;
extern int ** c;

/** @brief Prints the value of the inputs used to make the calculations
 */
void print_input(){
	puts(">>>>Inputs:\n");
	printf("n=\t%d\n\n", n);
	
	printf("s=");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			printf("\t%d", s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("t=");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n-1; j++){
			printf("\t%d", t[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("e=");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 1; j++){
			printf("\t%d", e[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("x=");
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 1; j++){
			printf("\t%d", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

/** @brief Prints the c matrix
 */
void print_c_matix(){
	puts(">>>>Outputs:\n");
	puts("The resulting c matrix is: ");
	for(int i =0; i < 2; i++){
		for(int j = 0; j < n; j++){
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/** @brief Prints the best combination of of machines
 *
 *  The c matrix represents the minimum time cost needed
 *  to get a product from the beginning to a given machine,
 *  therefore to determine what is the best combination of
 *  machines is necessary to determine the minimal c[i][j]
 *  at any given j-th column, with the exception of the 
 *  last column, in which the minimization needs to include
 *  the exiting time cost x[i][1] of each production line.
 */
void print_best_combination(){
	puts("The optimal combination of machines is the following:");
	for(int j = 0; j < n-1; j++){
		printf("(%d,%d) ",(c[0][j] < c[1][j] ? 1 : 2), j+1);
	}
	printf("(%d,%d)\n",(c[0][n-1] + x[0][0] < c[1][n-1] + x[1][0] ? 1 : 2),n);
}

/** @brief Optimizes the production line cost by generating the c matrix
 *
 *  @return the minimum time cost of the production line
 */
int optimize(){
	int i, j;
	for(j=0;  j<n; j++){
		for(i=0;  i < 2; i++){
			if(j == 0){
				c[i][j] = e[i][j]+s[i][j];
			} else {
				int a = c[i][j-1] + s[i][j];
				int b = c[1-i][j-1] + t[1-i][j-1] + s[i][j];
				c[i][j] = (a < b ? a : b);
			}
		}
	}
	int a = c[0][n-1] + x[0][0];
	int b = c[1][n-1] + x[1][0];
	return (a < b ? a : b);
}

/** @brief Prints all the needed outputs
 */
void print_output(){	
	optimize();
	print_input();
	print_c_matix();
	print_best_combination();
	
}
