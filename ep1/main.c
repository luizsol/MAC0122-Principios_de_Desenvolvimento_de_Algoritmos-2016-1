/**
 * File: main.c
 * Program dedicated to determine the best production lin
 * Source: MAC0122 - University of São Paulo
 * Repository: https://github.com/luizsol/MAC0122
 * Author: Luiz Sol (luizedusol@gmail.com)
 * Date: 2016/04/30
 */

#include <stdio.h>

///Holds the production time cost of the i-th machine at the j-th production line
int s[2][6] = {
	{7,9,3,4,8,4},
	{8,5,6,4,5,7}
	};
///Holds the set-up (starting time) cost of the i-th production line
int e[2][1] = {
	{2},
	{4}
	};
///Holds the finishing time cost of the i-th production line
int x[2][1] = {
	{3},
	{2}
	};
///Hods the time that it takes to move an item from the machine s[i][j] to the machine s[1-i][j+i]
int t[2][5] = {
	{2,3,1,3,4},
	{2,1,2,2,1}
	};
///Hods the combined cumulative cost of each production line
int c[2][6];

/*void populate(){
	s = {
	{7,9,3,4,8,4},
	{8,5,6,4,5,7}
	};

	e = {
	{2},
	{4}
	};

	x = {
	{3},
	{2}
	};

	t = {
	{2,3,1,3,4},
	{2,1,2,2,1}
	};
}*/


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
	//populate();
	printf("%d\n", optimize());	
	return 0;
} 
