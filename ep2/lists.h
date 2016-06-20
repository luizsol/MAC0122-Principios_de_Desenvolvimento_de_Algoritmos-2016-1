/** @file 	lists.h
 *  @brief 	Implements linked lists without arrays
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/06
 */


#ifndef _LISTS_H
#define _LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  The level of system verbose for debugging
 *  0: no verbose
 *  1: basic function reporting
 *  2: full function reporting
 */
#define VERBOSE_LVL 	0

#define NO_VERBOSE	0
#define LOW_VERBOSE	1
#define HIGH_VERBOSE	2

/**
 *  The structure used to implement the linked list cell
 */
typedef struct cell {
	/*@{*/
	char* content;	/**< the content of the cell */
	struct cell * next;	/**< the pointer to the next cell on the list */
	/*@}*/
} Cell;

/**
 *  The structure used to implement the linked list cell
 */
typedef struct{
	/*@{*/
	Cell *first; /**< the pointer to the first cell of the list */
	/*@}*/
} List;

/** @brief creates a new List
 *
 *  @param first the first cell of the list
 *  @return the pointer to the newly created List
 */
List *new_list(Cell *first);

/** @brief creates a new empty List
 *
 *  @return the pointer to the newly created List
 */
List *new_empty_list();

/** @brief Finds the last Cell on a List
 *
 *  @param list the list to be searched
 *  @return the addres of the last cell (0 if the list is empty)
 */
Cell *get_last_cell(List *list);

/** @brief Inserts a value at the endo of a List
 *
 *  @param list the List into which the value will be appended
 *  @param value the value to be appended
 *  @return the pointer to the newly created cell
 */
Cell *append(List *list, char* content);

/** @brief Inserts a cell at the end of a List
 *
 *  @param list the List into which the Cell will be appended
 *  @param cell the cell to be inserted
 *  @return the pointer to the newly created cell
 */
Cell *append_cell(List *list, Cell *cell);

/** @brief Determines if a list is empty
 *
 *  @param list the List to be analyzed
 */
int is_empty(List *list);

/** @brief Prints the contents of a list
 *
 *  @param list the List to be printed
 */
void print_list(List *list);

/** @brief Determines the size of the list
 *
 *  @param list the List to be measured
 *  @return the size of the list
 */
int list_len(List *list);

/** @brief Reverses the order of the list
 *
 *  @param list the List to be reversed
 */
void reverse_list(List *list);

/** @brief Merges two lists together
 *
 *  @param list1 the List to which the second list will be merged
 *  @param list2 the List that will be merged to the first one and will be emptied
 */
List *merge_lists(List *list1, List *list2);

/** @brief Gets the address of a given Cell based on its position on a List
 *
 *  @param list the List on which the cell will be searched
 *  @param idx the index of the element on the list
 *  @return the address of idx-th element on the list (0 if not found)
 */
Cell *get_cell_by_idx(List *list, int idx);

/** @brief Splits a list into two
 *
 *  @param list the List to be splitted
 *  @param idx the index of the element that will start the new list
 *  @return the address of the new list
 */
List *split(List *list, int idx);

/** @brief Removes a cell from a List
 *
 *  @param list the List to be modified
 *  @param idx the index of the Cell that will be removed
 *  @return the address of the removed Cell
 */
Cell *remove_by_idx(List *list, int idx);

#endif
