/** @file 	lists.c
 *  @brief 	Implements linked lists without arrays
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/06
 */
 
#include "lists.h" 

/** @brief creates a new List
 *
 *  @param first the first cell of the list
 *  @return the pointer to the newly created List
 */
List *new_list(Cell *first){
	List *addr = (List*)malloc(sizeof(List));
	addr->first = first;
	return addr;
}

/** @brief creates a new empty List
 *
 *  @return the pointer to the newly created List
 */
List *new_empty_list(){
	return new_list((Cell*)0);
}

/** @brief Finds the last Cell on a List
 *
 *  @param list the list to be searched
 *  @return the addres of the last cell (0 if the list is empty)
 */
Cell *get_last_cell(List *list){
	if(is_empty(list)){ //Empty list
 		return list->first;
 	}
 	Cell *ptr = list->first;
 	while(1){
 		if(ptr->next == 0) break;
 		ptr = ptr->next;
 	}
 	return ptr;
}

/** @brief Inserts a value at the endo of a List
 *
 *  @param list the List into which the value will be appended
 *  @param value the value to be appended
 *  @return the pointer to the newly created cell
 */
Cell *append(List *list, int value){
 	Cell *addr = (Cell*)malloc(sizeof(Cell));
 	addr->content = value;
 	addr->next = (Cell*)0;
 	Cell *ptr = get_last_cell(list);
 	if(ptr) return ptr->next = addr; //Not empty list
 	return list->first = addr; 	//empty list
}

/** @brief Determines if a List is empty
 *
 *  @param list the List to be analyzed
 *  @return 1 if the List is empty, 0 if it isn't
 */
int is_empty(List *list){
	return (list->first == 0 ? 1 : 0);
}

/** @brief Determines if a Cell has a next element
 *
 *  @param list the List to be analyzed
 *  @return 1 if the Cell has a next element, 0 if it hasn't
 */
int has_next(Cell *cell){
	return (cell->next == 0 ? 0 : 1);
}

/** @brief Prints the contents of a list
 *
 *  @param list the List to be printed
 */
void print_list(List *list){
	if(is_empty(list)){
		puts("[Empty List]");
		return;
	}
	Cell *ptr = list->first;
	while(has_next(ptr)){
		printf("(%d)->", ptr->content);
		ptr = ptr->next;
	}
	printf("(%d)\n", ptr->content);
}

/** @brief Reverses the order of the list recursively
 *
 *  @param list the List to be reversed
 *  @param current_cell the current cell to be worked with
 *  @param last_cell the last cell of the list
 */
void recursive_reverse_list(List *list, Cell *current_cell, Cell *last_cell){
	if(current_cell->next != last_cell){ //Not dealing with the last cell yet
		recursive_reverse_list(list, current_cell->next, last_cell);
	}
	current_cell->next->next = current_cell; //Making the next cell point to this cell
	if(current_cell == list->first){
		list->first = last_cell;
		current_cell->next = 0;
	}
}

/** @brief Reverses the order of the list
 *
 *  @param list the List to be reversed
 */
void reverse_list(List *list){
	recursive_reverse_list(list, list->first, get_last_cell(list));
}