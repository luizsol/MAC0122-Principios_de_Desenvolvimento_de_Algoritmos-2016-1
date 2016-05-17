/** @file 	main.c
 *  @brief 	Program's main file
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/16
 */
 
#include "list.h"

Celula *lista1, *lista2;


int main(int argc, char *argv[]){
	lista1 = inicializa();
	lista1->prox = inicializa();
	lista1->prox->prox = inicializa();
	troca(1, lista1, 10);
	troca(10, lista1, 10);
	printf("Tamanho da lista: %d\n", length (lista1));
	remove_(10, lista1);
	printf("Tamanho da lista: %d\n", length (lista1));
	return 0;
}
