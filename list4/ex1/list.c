/** @file 	list.c
 *  @brief 	Implements linked lists
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/16
 */
 
 #include "list.h"
 
/** @brief Initializes a cell
 *
 *  @return a pointer to the cell
 */
 Celula *inicializa(){
 	Celula *cell = (Celula*)malloc(sizeof(Celula));
 	cell->prox = NULL;
 	return cell;
 }

/** @brief Determines the size of the list
 *
 *  @param ini the start of the list
 *  @return the size of the list
 */
int length(Celula *ini){
 	int size = 0;
 	while(ini){
 		size++;
 		ini = ini->prox;
 	}
 	return size-1;
 }
