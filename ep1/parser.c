/** @file	parser.c
 *  @brief 	Functions that hadle the input and variable assignments
 * 		Source: MAC0122 - University of São Paulo
 * 		Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/04/30
 */

#include "parser.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>

extern int n;
extern int ** s;
extern int e[2][1];
extern int x[2][1];
extern int ** t;
extern int ** c;

/** @brief Prints a standard message on the case of wrong argument usage
 */
void print_bad_argument(){
	fprintf(stderr, "Error: bad arguments. Use the parameter --usage for an usage example. Exiting.\n");
}

/** @brief Initializes the variable sized arrays
 *
 *  @return 0 if there was a problem while initializing the arrays
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


/** @brief Receives the user input on an interactive mode
 *
 *  @return 0 if there was a problem while initializing the arrays
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
	puts("Input the s matrix: ");
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < n; j++){
			printf("s[%d][%d]\n",i+1,j+1);
			fgets(input, 100, stdin);
			s[i][j] = atoi(input);
		}
	}
	//t
	puts("Input the t matrix: ");
	for(int i = 0; i < 2; i++){
		for (int j = 0; j < n-1; j++){
			printf("t[%d][%d]\n",i+1,j+1);
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

/** @brief Splits a given string based on a given delimiter
 *
 *(source=http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c)
 *
 *  @param a_str the string to be splitted
 *  @param a_delim the splitting delimiter
 *  @return the pointer to the array containing the result
 */
char** str_split(char* a_str, const char a_delim){
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/** @brief Populates an int matrix with the values of a string which separate its values with a given delimiter
 *
 *  @param n_lines number of lines of the matrix
 *  @param n_col number of columns of the matrix
 *  @param str the string to be read
 *  @param matrix the matrix to be writed at
 *  @param delimiter the character used to separate the values
 */
void string_to_matrix(int n_lines, int n_col, char * str, int ** matrix, char delimiter){
	char ** splitted = str_split(str, delimiter);
	int count = 0;
	for(int i = 0; i < n_lines; i++){
		for(int j = 0; j < n_col; j++, count++){
			matrix[i][j] = atoi(splitted[count]);
		}
	}
}

/** @brief Determines the number of elements on a string divided by a given delimiter
 *
 *  @param str the string to be processed
 *  @param delimiter the character used as the delimiter
 *  @return the number of elements on the string
 */
int number_of_elements(char*str, char delimiter){
	int count = 0;
	int i = 0;
	char ch = str[0];
	while(ch != '\0'){
		if(ch == delimiter)
			count++;
		i++;
		ch = str[i];
	}
	return count+1;
}

/** @brief Handles the input from the parameters passed through the terminal
 *
 *  @param argc the number of arguments passed to the main funcion
 *  @param argv the arguments passed to the main funcion
 *  @return 0 if the input was invalid
 */
int terminal_input(int argc, char ** argv){
	int has_n, has_s, has_t, has_e, has_x;
	has_n = has_s = has_t = has_e = has_x = 0;
	char *temp_n; 
	char *temp_s; 
	char *temp_t;
	char *temp_e, **char_e;
	char *temp_x, **char_x;
	char ch;

	while((ch = getopt(argc, argv, "n:s:t:e:x:")) != EOF)
		switch(ch){
		case 'n':
			n = atoi(optarg);
			has_n = 1;
			break;
		case 's':
			temp_s = optarg;
			has_s = 1;
			break;
		case 't':
			temp_t = optarg;
			has_t = 1;
			break;
		case 'e':
			temp_e = optarg;
			has_e = 1;
			break;
		case 'x':
			temp_x = optarg;
			has_x = 1;
			break;
		default:
			print_bad_argument();
			return ERROR;
	}
	
	//Check if all parameters was passed
	if(has_n & has_s & has_t & has_e & has_x == 0){
		print_bad_argument();
		return ERROR;
	}
	
	initialize_arrays();
	//Check if the sizes mach
	if(	number_of_elements(temp_s, ',') != (2*n) ||
		number_of_elements(temp_t, ',') != (2*(n-1)) ||
		number_of_elements(temp_e, ',') != 2 ||
		number_of_elements(temp_x, ',') != 2){
		
		print_bad_argument();
		return ERROR;	
	}
	
	//s[2][n], t[2][n-1], e[2][1], x[2][1]
	string_to_matrix(2,n,temp_s,s,',');
	string_to_matrix(2,n-1,temp_t,t,',');
	char_e = str_split(temp_e, ',');
	e[0][0] = atoi(char_e[0]);
	e[1][0] = atoi(char_e[1]);
	char_x = str_split(temp_x, ',');
	x[0][0] = atoi(char_x[0]);
	x[1][0] = atoi(char_x[1]);
	return OK;
	
}

/** @brief Handles input
 *
 *  @param argc the number of arguments passed to the main funcion
 *  @param argv the arguments passed to the main funcion
 *  @return 0 if the input was invalid
 */
int read_params(int argc, char ** argv){
	if(argc == 1){ //no parameters passed, user input mode
		user_input();
	} else if (argc == 2 && strcmp(argv[1], "--usage") == 0){
		puts("Usage example:\n");
		puts("n=3 s= 1 2 3 t= 5 6 e= 9  x= 11");
		puts("       4 5 6    7 8    10    12\n");
		puts("./main -n 3 -s 1,2,3,4,5,6 -t 5,6,7,8 -e 9,10 -x 11,12");
		return ERROR;
	} else if(argc == 11){
		return terminal_input(argc, argv);
	} else {
		print_bad_argument();
		return ERROR;
	}
}
