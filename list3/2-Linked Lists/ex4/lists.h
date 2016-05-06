/** @file 	lists.h
 *  @brief 	Implements linked lists without arrays
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/06
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _LISTS_H
#define _LISTS_H
 
/**
 *  The maxumim size of the list
 */
#define MAX 			100

/**
 *  The level of system verbose for debugging
 *  0: no verbose
 *  1: basic function reporting
 *  2: full function reporting
 */
#define VERBOSE_LVL 	0

#define NO_VERBOSE		0
#define LOW_VERBOSE		1
#define HIGH_VERBOSE	2

/**
 *  The structure used to implement the linked list cell
 */
typedef struct cell {
	/*@{*/
	int content;	/**< the content of the cell */
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
Cell *append(List *list, int value);

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

#endif
