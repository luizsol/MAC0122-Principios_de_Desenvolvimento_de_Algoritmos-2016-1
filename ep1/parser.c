#include "parser.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern int n;
extern int ** s;
extern int e[2][1];
extern int x[2][1];
extern int ** t;
extern int ** c;


//! Initializes the variable size arrays
/*!
  \return 0 if there was a problem while initializing the arrays
*/
int initialize_arrays(){
	//s[2][n], t[2][n-1], c[2, n]
	if((s = (int**)malloc(2*sizeof(int*))) == 0)
		return ERROR;
	if((t = (int**)malloc(2*sizeof(int*))) == 0)
		return ERROR;
	if((c = (int**)malloc(2*sizeof(int*))) == 0)
		return ERROR;
	//s
	if((s[0] = (int*)malloc(n*sizeof(int))) == 0)
		return ERROR;
	if((s[1] = (int*)malloc(n*sizeof(int))) == 0)
		return ERROR;
	//t
	if((t[0] = (int*)malloc((n-1)*sizeof(int))) == 0)
		return ERROR;
	if((t[1] = (int*)malloc((n-1)*sizeof(int))) == 0)
		return ERROR;
	//c
	if((c[0] = (int*)malloc(n*sizeof(int))) == 0)
		return ERROR;
	if((c[1] = (int*)malloc(n*sizeof(int))) == 0)
		return ERROR;
	return OK;
}

//! Receives the user input on an interactive mode
/*!
  \return 0 if there was a problem while initializing the arrays
*/
int user_input(){
	char input[100];
	puts("Input the number of machines on the production line (n): ");
	fgets(input, 100, stdin);
	n = atoi(input);

	if(initialize_arrays() == ERROR){
		fprintf(stderr, "Error initializing the arrays. Exiting.\n");
		return  ERROR;
	}
	//s
	puts("Input the s matrix: ")
	for(int i = 0; i < 2; i++){
		for (int j = 0; i < n; j++){
			printf("s[%d][%d]\n",i+1,j+1);
			fgets(input, 100, stdin);
			s[i][j] = atoi(input);
		}
	}
	//t
	puts("Input the t matrix: ")
	for(int i = 0; i < 2; i++){
		for (int j = 0; i < n-1; j++){
			printf("s[%d][%d]\n",i+1,j+1);
			fgets(input, 100, stdin);
			t[i][j] = atoi(input);
		}
	}
	//e
	puts("Input the setup time of the first machine of the fist production line (e[1]): ");
	fgets(input, 100, stdin);
	e[0][0] = atoi(input);
	puts("Input the setup time of the first machine of the second production line (e[2]): ");
	fgets(input, 100, stdin);
	e[1][0] = atoi(input);
	//x
	puts("Input the finishing time cost of the last machine of the first production line (x[1]): ");
	fgets(input, 100, stdin);
	x[0][0] = atoi(input);
	puts("Input the finishing time cost of the last machine of the second production line (x[2]): ");
	fgets(input, 100, stdin);
	x[1][0] = atoi(input);

	return OK;
}

void populate(char * values, int ** target){
	
}







//! Funcion responsible for haldling input
/*!
  \param argc the number of arguments passed to the main funcion
  \param argv the arguments passed to the main funcion
  \return 0 if the input was invalid
*/

int read_params(int argc, char ** argv){
	///The parameters should be:
	/* n, s, t, e, x, 221
	 */
	char ch;
	while((ch = getopt(argc, argv, "n:s:t:e:x:")) != EOF)
		switch(ch){
		case 'n':
			n = atoi(optarg);
			break;
		case 's':
			break;	
		}
	user_input();
	return OK;
}