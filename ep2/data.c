/** @file 	data.c
 *  @brief 	Deals with the data storage and manipulation
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#include "data.h"


/** @brief Initializes the array of clients
 *
 *  @param size the maximum number of clients
 */
Cliente ** new_clients_array(int size){
	return (Cliente **)malloc(size * sizeof(Cliente*));
}

/** @brief Determines the index of a free position on the clients array
 *
 *  @param array the clients array
 *  @param size the size of the array
 *  @return the index of a free position (-1 if not found)
 */
int get_free_position_idx(Cliente ** array, int size){
	int i = 0;
	for(; (*array[i]) != NULL && i < size; i++){}
	if (i == size) return -1;
	return i;
}

int inserir_cliente(Cliente *cliente, Cliente **clientes){

}

