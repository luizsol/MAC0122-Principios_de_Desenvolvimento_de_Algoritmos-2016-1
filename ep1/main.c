/**
 * File: main.c
 * Program dedicated to determine the best production lin
 * Source: MAC0122 - University of São Paulo
 * Repository: https://github.com/luizsol/MAC0122
 * Author: Luiz Sol (luizedusol@gmail.com)
 * Date: 2016/04/30
 */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

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


int optimize(){
	int i, j;
	for(j=0;  j<6; j++){
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
	int a = c[0][5] + x[0][0];
	int b = c[1][5] + x[1][0];
	return (a < b ? a : b);
}

int main(int argc, char *argv[]){
	user_input();
	return 0;
} 
