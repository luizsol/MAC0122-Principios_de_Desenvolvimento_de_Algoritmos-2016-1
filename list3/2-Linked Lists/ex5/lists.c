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
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("new_list(%p)\n", (void*)first);
	}
	List *addr = (List*)malloc(sizeof(List));
	addr->first = first;
	return addr;
}

/** @brief creates a new empty List
 *
 *  @return the pointer to the newly created List
 */
List *new_empty_list(){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("new_empty_list()\n");
	}
	return new_list((Cell*)0);
}

/** @brief Finds the last Cell on a List
 *
 *  @param list the list to be searched
 *  @return the addres of the last cell (0 if the list is empty)
 */
Cell *get_last_cell(List *list){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("get_last_cell(%p)\n", (void*)list);
	}
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

/** @brief Inserts a value at the end of a List
 *
 *  @param list the List into which the value will be appended
 *  @param value the value to be appended
 *  @return the pointer to the newly created cell
 */
Cell *append(List *list, int value){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("append(%p, %d)\n", (void*)list, value);
	}
 	Cell *addr = (Cell*)malloc(sizeof(Cell));
 	addr->content = value;
 	addr->next = (Cell*)0;
 	Cell *ptr = get_last_cell(list);
 	if(ptr) return ptr->next = addr; //Not empty list
 	return list->first = addr; 	//empty list
}

/** @brief Inserts a cell at the end of a List
 *
 *  @param list the List into which the Cell will be appended
 *  @param cell the cell to be inserted
 *  @return the pointer to the newly created cell
 */
Cell *append_cell(List *list, Cell *cell){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("append_cell(%p, %p)\n", (void*)list, (void*)cell);
	}
	get_last_cell(list)->next = cell;
	return cell;
}

/** @brief Determines if a List is empty
 *
 *  @param list the List to be analyzed
 *  @return 1 if the List is empty, 0 if it isn't
 */
int is_empty(List *list){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("is_empty(%p)\n", (void*)list);
	}
	return (list->first == 0 ? 1 : 0);
}

/** @brief Determines if a Cell has a next element
 *
 *  @param list the List to be analyzed
 *  @return 1 if the Cell has a next element, 0 if it hasn't
 */
int has_next(Cell *cell){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("has_next(%p)\n", (void*)cell);
	}
	return (cell->next == 0 ? 0 : 1);
}

/** @brief Prints the contents of a list
 *
 *  @param list the List to be printed
 */
void print_list(List *list){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("print_list(%p)\n", (void*)list);
	}
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
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("recursive_reverse_list(%p, %p, %p)\n", (void*)list, (void*)current_cell, (void*)last_cell);
	}
	if(current_cell->next != last_cell){ //Not dealing with the last cell yet
		recursive_reverse_list(list, current_cell->next, last_cell);
	}
	current_cell->next->next = current_cell; //Making the next cell point to this cell
	if(current_cell == list->first){
		list->first = last_cell;
		current_cell->next = 0;
	}
}

/** @brief Determines the size of the list
 *
 *  @param list the List to be measured
 *  @return the size of the list
 */
int list_len(List *list){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("list_len(%p)\n", (void*)list);
	}
	int i = 0;
	Cell *cell = list->first;
	while(cell != 0){
		i++;
		cell = cell->next;
	}
	if(VERBOSE_LVL == HIGH_VERBOSE){
		printf("->list_len(%p): %d\n", (void*)list, i);
	}
	return i;
}

/** @brief Reverses the order of the list
 *
 *  @param list the List to be reversed
 */
void reverse_list(List *list){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("reverse_list(%p)\n", (void*)list);
	}
	recursive_reverse_list(list, list->first, get_last_cell(list));
}

/** @brief Merges two lists together
 *
 *  @param list1 the List to which the second list will be merged
 *  @param list2 the List that will be merged to the first one and will be emptied
 */
List *merge_lists(List *list1, List *list2){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("merge_lists(%p, %p)\n", (void*)list1, (void*)list2);
	}
	get_last_cell(list1)->next = list2->first;
	list2->first = 0;
	return list1;
}

/** @brief Gets the address of a given Cell based on its position on a List
 *
 *  @param list the List on which the cell will be searched
 *  @param idx the index of the element on the list
 *  @return the address of idx-th element on the list (0 if not found)
 */
Cell *get_cell_by_idx(List *list, int idx){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("get_cell_by_idx(%p, %d)\n", (void*)list, idx);
	}
	int i = 0;
	Cell *cell = list->first;
	while(i < idx && cell != 0){ //When i == idx or &cell ==0, return
		cell = cell->next;
		i++;
	}
	printf("i=%d, address=%p, content %d\n", i, (void*)cell, cell->content);	
	return cell;
}

/** @brief Splits a list into two
 *
 *  @param list the List to be splitted
 *  @param idx the index of the element that will start the new list
 *  @return the address of the new list
 */
List *split(List *list, int idx){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("split(%p, %d)\n", (void*)list, idx);
	}
	List *list2 = (List*)malloc(sizeof(List));
	Cell *cell = get_cell_by_idx(list, idx);
	if(cell == 0) return 0;
	get_cell_by_idx(list, idx-1)->next = 0;
	list2->first = cell;
	return list2;
}

/** @brief Removes a cell from a List
 *
 *  @param list the List to be modified
 *  @param idx the index of the Cell that will be removed
 *  @return the address of the removed Cell
 */
Cell *remove_by_idx(List *list, int idx){
	if(VERBOSE_LVL >= LOW_VERBOSE){
		printf("remove_by_idx(%p, %d)\n", (void*)list, idx);
	}
	Cell *cell = get_cell_by_idx(list, idx);
	if(cell == 0) return cell;
	if(idx == 0){//First element
		list->first = cell->next;
	} else {
		get_cell_by_idx(list, idx-1)->next = cell->next;
	}
	cell->next = 0;
	return cell;
}

/** @brief Searches for the lowest element on the list
 *
 *  @param list the List to be searched
 *  @return the index of the lowest Cell
 */
int get_min(List *list){
	if(is_empty(list) == 0) return 0;
	int min = 0;
	for(int i = list_len(list), i > 0; i--){
		if(get_cell_by_idx(i-1)->value <= cell->value)
	}
}