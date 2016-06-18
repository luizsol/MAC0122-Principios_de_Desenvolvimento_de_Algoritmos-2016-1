/** @file 	main.c
 *  @brief 	Manages simulated shopping charts
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#include "interface.h"

/** @brief The program's main function
 */
int main(int argc, char *argv[]){

	int size = 100;

	Cliente ** clientes = novo_array_clientes(100);
	inserir_novo_cliente(2963333102, "Luiz Eduardo Sol R. da Silva", "+551199275186", "luizedusol@gmail.com", clientes, size);
	inserir_novo_cliente(2964444102, "Luiz Eduardo Sol R. da Silva", "+551199275186", "luizedusolusa@gmail.com", clientes, size);
	printf("%ld\n", clientes[0]->cpf);
	printf("%ld\n", clientes[1]->cpf);


} 
