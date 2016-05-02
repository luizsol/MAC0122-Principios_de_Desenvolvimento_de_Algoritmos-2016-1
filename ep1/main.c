/** @file 	main.c
 *  @brief 	Program dedicated to determine the best production line
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/04/30
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "calcs.h"

///Holds the production time cost of the i-th machine at the j-th production line
int **s;
///Holds the set-up (starting time) cost of the i-th production line
int e[2][1];
///Holds the finishing time cost of the i-th production line
int x[2][1];
///Hods the time that it takes to move an item from the machine s[i][j] to the machine s[1-i][j+i]
int **t;
///Hods the combined cumulative cost of each production line
int **c;
///Number of machines on the production line
int n;

/** @brief The program's main function
 */
int main(int argc, char *argv[]){
	if(read_params(argc, argv) == OK){
		print_output();
		return 0;
	}
	return 1;
} 
