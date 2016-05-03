/** @file 	main.c
 *  @brief 	Adds any given ammout of numbers recursively
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/02
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Adds all the elements of a given array
 *
 *  @param array the array to be added
 *  @param idx the index of the element to be added
 *  @return the value of the sum
 */
int sum(int * array, int idx){
	return (idx == 0 ? array[idx] : array[idx] + sum(array, idx-1));
}

/** @brief Prepares the array to be added
 *
 *  @param argc the number of arguments passed to the main function
 *  @param argv the arguments passed to the main function
 *  @param array the array to be populated
 */
void build_array(int argc, char *argv[], int *array){
	int count = 1;
	while(count < argc){
		array[count-1] = atoi(argv[count]);
		count++;
	}
}

/** @brief The main function
 *
 *  @param argc the number of arguments passed to the main function
 *  @return argv the arguments passed to the main function
 */
int main(int argc, char *argv[]){
	if(argc > 2){
		int array[argc-1];
		build_array(argc, argv, array);
		printf("%d\n", sum(array, argc-2));
		return 0;
	}
	printf("Usage:\n./main <int1> [int2] [int3] ...\n");
	return 1;
}
