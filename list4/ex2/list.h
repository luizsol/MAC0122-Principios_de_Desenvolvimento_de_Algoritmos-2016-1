/** @file 	list.h
 *  @brief 	Implements linked lists
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/16
 */
 
#ifndef __LIST__H
#define __LIST__H

#include <stdlib.h>
#include <stdio.h>

typedef struct celula_dupla {
	int conteudo;
	struct celula_dupla *prox; //Estava declarado errado no enunciado da lista
} Celula;
 

/** @brief Initializes a cell
 *
 *  @return a pointer to the cell
 */
Celula *inicializa();


/** @brief Determines the size of the list
 *
 *  @param ini the start of the list
 *  @return the size of the list
 */
int length(Celula *ini);

/** @brief Inserts the value of x into the k-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell to be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 *  @return the pointer to the k-th element of the list
 */
int troca(int k, Celula *ini, int x);

/** @brief Inserts the value of x into the (k-1)-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell of which the previous one will be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 */
void insere_esq (int k, Celula *ini, int x);

/** @brief Inserts the value of x into the (k+1)-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell of which the previous one will be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 */
void insere_dir (int k, Celula *ini, int x);

/** @brief Removes a cell from the list, returning its content
 *	
 *  If the cell doesn't exists it will remove the last cell of the list
 *  If the list is empty, it will return 0
 *
 *  @param k the index of the cell to be removed
 *  @param ini the start of the list
 *  @return the content of the list
 */
int remove_(int k, Celula *ini);

#endif
