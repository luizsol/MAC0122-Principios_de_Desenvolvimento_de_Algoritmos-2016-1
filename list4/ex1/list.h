/** @file 	list.h
 *  @brief 	Implements linked lists
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/16
 */
 
#ifndef __LIST__H
#define __LIST__H

#include <stdlib.h>

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

#endif
