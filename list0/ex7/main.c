/** @file 	main.c
 *  @brief 	Calculates the number of times that a given algarism x appears on another given number
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Calculates the number of times that a character number appears on the string str
 *
 *  @param str the string in which the character will be searched
 *  @param number the caracter to be searched in the string
 *  @return the number of appearances
 */
int appearances(char *str, char number, int idx){
	int equals = 0;
	if (str[idx] == number)
		equals = 1;
	
	return (idx == 0 ? equals : equals+appearances(str, number, idx-1));
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
	char *str;
	char *value;
	
	if(argc == 3){
		str = argv[1];
		value = argv[2];
	} else {
		printf("Usage:\n./main <x> <y>\n");
		return 1;
	}
	
	printf("%d\n", appearances(str, value[0], size_of_str(str)-1));
	return 0;
	
}
