/** @file 	main.c
 *  @brief 	Inverts a given string recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>

/** @brief Prints a given string backwards
 *
 *  @param str the string to be inverted
 *  @param idx the index of the char to be printed 
 */
void reverse(char *str, int idx){
	if(idx < 0) return;
	printf("%c",str[idx]);
	reverse(str, idx-1);
}

/** @brief Determines the size of a string
 *
 *  @param str the string to measured
 *  @return the size of the string
 */
int size_of_str(char *str){
	int count = 0;
	while(str[count] != '\0')
		count++;
	return count + 1;
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc == 2){
		reverse(argv[1], size_of_str(argv[1])-1);
		printf("\n");
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <string>\n");
	return 1;
}
