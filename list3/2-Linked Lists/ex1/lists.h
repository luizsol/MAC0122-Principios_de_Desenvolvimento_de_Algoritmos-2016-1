/** @file 	lists.h
 *  @brief 	Implements linked lists
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/04
 */

#include <stdio.h>
#include <stdlib.h>
 
/**
 *  The maxumim size of the list
 */
#define MAX 		100

/**
 *  The level of system verbose for debugging
 *  0: no verbose
 *  1: basic function reporting
 *  2: full function reporting
 */
#define VERBOSE_LVL 	2

#define NO_VERBOSE	0
#define LOW_VERBOSE	1
#define HIGH_VERBOSE	2

/**
 *  The structure used to implement the linked list
 */
typedef struct celula {
	/*@{*/
	int conteudo;	/**< the content of the cell */
	int prox;	/**< the array index of the next cell on the list */
	/*@}*/
} Celula;

/**
 *  The array used to implement the linked list
 */
Celula v[MAX];

/**
 *  The index of the first element of the list
 */
int inicio;

/**
 *  The index of the next cell available on the array
 */
int livre;

/** @brief Initializes the cells from the list array
 *
 */
void start_list();

/** @brief Removes a cell from the linked list
 *
 *  @rparam the index of the element
 */
void remove_idx(int idx);

/** @brief Updates the value of the lowest index unlinked cell
 *
 *  @return the index of the free cell
 */
int update_free();

/** @brief Gets the inremove(dex of the previous cell of a given cell on the linked list
 *
 *  @param idx the index of the cell of which the previous cell will be searched
 *  @return the index of the previous cell
 */
int get_previous(int idx);

/** @brief Search through the linked list for a cell with a given value
 *
 *  @param start_idx the index of the first cell of the search
 *  @param value the value to search for
 *  @return the index of the cell containing the value
 */
int loop_search(int start_idx, int value);

/** @brief Determines the index of the last cell on the linked list
 *
 *  @return the index of the last cell on the linked list
 */
int get_idx_from_last();

/** @brief Inserts a cell on the end of the linked list
 *
 *  @param value the value to be inserted
 */
void append(int value);

/** @brief Inserts a cell on the linked list
 *
 *  @param idx the index of the cell that will preceed the new inserted cell
 *  @param value the value to be inserted
 */
void insert(int idx, int value);

/** @brief Removes any repeated appearences of a given value from the linked list
 *
 */
void remove_duplicated();

/** @brief Prints the list contents
 *
 */
void print_list();

/** @brief Prints the array containing the list
 *
 */
void print_array();
