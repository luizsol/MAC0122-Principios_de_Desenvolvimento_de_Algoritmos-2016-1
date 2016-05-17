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

/** @brief Inserts the value of x into the k-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell to be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 *  @return the pointer to the k-th element of the list
 */
int troca(int k, Celula *ini, int x){
	if(k > 0) return troca((ini->prox == NULL ? 0 : k-1), (ini->prox == NULL ? ini : ini->prox), x);
	return ini->conteudo = x;
}


/** @brief Inserts the value of x into the (k-1)-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell of which the previous one will be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 */
void insere_esq (int k, Celula *ini, int x){
	if(k > length(ini))
		troca(0, ini, x);
	else 
		troca(k-1, ini, x);
}

/** @brief Inserts the value of x into the (k+1)-th element of the list ini.
 *	
 *  If the cell doesn't exists it will insert a new one on the list
 *
 *  @param k the index of the cell of which the previous one will be modified
 *  @param ini the start of the list
 *  @param x the value to be inserted
 */
void insere_dir (int k, Celula *ini, int x){
	troca(k+1, ini, x);
}


/** @brief Removes a cell from the list, returning its content
 *	
 *  If the cell doesn't exists it will remove the last cell of the list
 *  If the list is empty, it will return 0
 *
 *  @param k the index of the cell to be removed
 *  @param ini the start of the list
 *  @return the content of the list
 */
int remove_(int k, Celula *ini){
	Celula *ptr = ini;
	int flag = 0;
	while (k-1){
		if(ptr->prox->prox != NULL) ptr = ptr->prox;
		else{
			flag = 1;
			break;
		}
		k--;
	}
	int content = ptr->prox->conteudo;
	Celula *buff = ptr->prox;
	
	if(flag == 0) ptr->prox = ptr->prox->prox;
	else ptr->prox = NULL;
	
	free(buff);
	return content;
}

