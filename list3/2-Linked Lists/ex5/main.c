/** @file 	main.c
 *  @brief 	Recursively searchs for the list's middle cell index
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/04
 */

#include "parse.h"

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @param argv the arguments passed to the main function
 *  @return the finishing status of the funcion
 */
int main(int argc, char *argv[]){
	if(argc == 2){
		List list1;
		populate_list(&list1, argv[1]);
		puts("Original list:");
		print_list(&list1);
		sort(&list1);
		puts("Sorted list:");
		print_list(&list1);
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <comma separetad list>\n");
	return 1;
}
