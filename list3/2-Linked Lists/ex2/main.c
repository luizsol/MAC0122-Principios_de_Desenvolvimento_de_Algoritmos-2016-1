/** @file 	main.c
 *  @brief 	Realizes some basic operations on lists
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
		start_list();
		populate_list(argv[1]);
		print_list();
		printf("Input the value to be searched for on the list: ");
		char str[10];
		fgets(str, 10, stdin);
		int idx = loop_search(inicio, atoi(str));
		if(idx != -1)
			printf("Found it at v[%d]\n", idx);
		else
			printf("Not found.\n");
		printf("Input the value to be appended to the list: ");
		fgets(str, 10, stdin);
		append(atoi(str));
		puts("New list:");
		print_list();
		puts("Removing last element from the list:");
		remove_idx(get_idx_from_last());
		print_list();
		return 0;
	} else if(argc != 1){
		fprintf(stderr, "Bad argumet\n");
	}
	printf("Usage:\n./main <list>\n");
	return 1;
}
