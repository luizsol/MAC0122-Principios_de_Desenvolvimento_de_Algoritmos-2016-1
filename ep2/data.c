/** @file 	data.c
 *  @brief 	Deals with the data storage and manipulation
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#include "data.h"

void verbose(char* message, int verbose_lvl){
	if(verbose_lvl <= VERB_LVL) printf("verbose_msg (%d): %s\n", verbose_lvl, message);
}

/** @brief Initializes the array of clients
 *
 *  @param size the maximum number of clients
 */
Cliente ** novo_array_clientes(int size){
	verbose("Creating new clients array", LOW_VERB);
	Cliente ** clientes = (Cliente **)malloc(size * sizeof(Cliente*));
	for(int i = 0; i < size; i++) clientes[i] = NULL;
	return clientes;
}

/** @brief Determines the index of a free position on a clients array
 *
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the index of a free position (-1 if not found)
 */
int idx_posicao_livre(Cliente ** clientes, int size){
	verbose("Searching for a free index", MED_VERB);
	int i = 0;
	for(; (clientes[i] !=  NULL) && i < size; i++){}
	if (i == size){ 
		verbose("WARNING: No free index", HIG_VERB);
		return -1;
	}
	char str[100];
	sprintf(str, "New free index: %d", i);
	verbose(str, HIG_VERB);
	return i;
}

/** @brief Designed to be used by C's qsort to rearrange the clients array
 *
 *  @param cliente the pointer to the client to be inserted
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return a positive number if cliente_a is greather than cliente_b
 */
int compare_cpf(const void* cliente_a, const void* cliente_b){
	///The qsort will pass a pointer to the array item, therefore cliente_a and cliente_b are both pointers to pointers to Cliente. We must cast cliente_x into it's original form (Cliente**), then extract the client's cpf from it
	if (*(Cliente**)cliente_a == NULL) return 1;
	if (*(Cliente**)cliente_b == NULL) return -1;
	long int cpf_a = (*(Cliente**)cliente_a)->cpf;
	long int cpf_b = (*(Cliente**)cliente_b)->cpf;
	///If cpf_a is greater than cpf_b, we should return a positive value
	return (cpf_a - cpf_b < 0 ? -1 : 1);
}

/** @brief Searches for a client by his cpf, returning it's position on the clients array
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @return the index of the client pointer on a clients array
 */
int buscar_cliente(long int cpf , Cliente ** clientes, int size){
	Cliente ** result = (Cliente **) bsearch (&cpf, clientes, size, sizeof (Cliente**), compare_cpf);
	if (result == NULL) return ERR;
	return (result - clientes)/sizeof(Cliente*);
}

/** @brief Inserts a client on a clients array
 *
 *  @param cliente the pointer to the client to be inserted
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int inserir_cliente(Cliente *cliente, Cliente **clientes, int size){
	int idx = idx_posicao_livre(clientes, size);
	if (idx == ERR) return ERR;
	if (buscar_cliente(cliente->cpf, clientes, size) != ERR) return ERR;
	clientes[idx] = cliente;
	qsort(clientes, size, sizeof(Cliente *), compare_cpf);
	return OK;
}

/** @brief Creates and inserts a new client on a clients array
 *
 *  @param cpf the client's CPF
 *  @param nome the client's name
 *  @param fone the client's phone number
 *  @param email the client's e-mail
 *  @param cliente the pointer to the client to be inserted
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int inserir_novo_cliente(long int cpf, char *nome, char *fone, char *email, Cliente **clientes, int size){
	Cliente *cliente = (Cliente*)malloc(sizeof(Cliente));
	cliente->cpf = cpf;
	cliente->nome = strdup(nome);
	cliente->fone = strdup(fone);
	cliente->email = strdup(email);
	return inserir_cliente(cliente, clientes, size);
}

/** @brief Removes a client from a clients array
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int remover_cliente(long int cpf , Cliente ** clientes, int size){
	int idx = buscar_cliente(cpf, clientes, size);
	if (idx == ERR) return ERR;
	remover_todos_produtos(cpf ,clientes, size);
	free(clientes[idx]->nome);
	free(clientes[idx]->fone);
	free(clientes[idx]->email);
	free(clientes[idx]);
	clientes[idx] = NULL;
	qsort(clientes, size, sizeof(Cliente *), compare_cpf);
	return OK;
}

/** @brief Updates the client's phone number
 *
 *  @param novo_telefone the client's new phone number
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int atualizar_telefone(char novo_telefone [20], long int cpf , Cliente * clientes [], int size){
	int idx = buscar_cliente(cpf, clientes, size);
	if (idx == ERR) return ERR;
	free(clientes[idx]->fone);
	clientes[idx]->fone = strdup(novo_telefone);
	return OK;
}

/** @brief Inserts a product into a given client's products list
 *
 *  @param produto the pointer to the product to be inserted
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int inserir_produto (Produto * produto, long int cpf , Cliente ** clientes, int size){
	int idx = buscar_cliente(cpf, clientes, size);
	if(idx == ERR) return ERR;
	produto->prox = clientes[idx]->produtos;
	clientes[idx]->produtos = produto;
	return OK;
}

/** @brief Inserts a new product into a given client's products list
 *
 *  @param id the product's id
 *  @param nome the product's name
 *  @param marca the product's brand
 *  @param preco the product's preco
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int inserir_novo_produto(char *id, char *nome, char *marca, double preco, long int cpf, Cliente ** clientes, int size){
	Produto * produto = (Produto*)malloc(sizeof(Produto));

	produto->id = strdup(id);
	produto->nome = strdup(nome);
	produto->marca = strdup(marca);
	produto->preco = preco;
	
	inserir_produto(produto, cpf, clientes, size);
	
	return OK;
}

/** @brief Removes a given product from a product list
 *
 *  @param produto the product to be removed
 *  @return the address of the next product
 */
Produto* remover_produto(Produto* produto){
	free(produto->id);
	free(produto->nome);
	free(produto->marca);
	Produto* prox = produto->prox;
	free(produto);
	return prox;
}

/** @brief Removes the last item from the client's products list
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int desfazer_ultima_compra(long int cpf , Cliente ** clientes, int size){
	int idx = buscar_cliente(cpf, clientes, size);
	if(idx == ERR) return ERR;
	clientes[idx]->produtos = remover_produto(clientes[idx]->produtos);
	return OK;
}

/** @brief Removes all itens from the client's products list
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return 0 if the operation was successful
 *  @return the status of the operation
 */
int remover_todos_produtos(long int cpf , Cliente ** clientes, int size){
	int idx = buscar_cliente(cpf, clientes, size);
	if(idx == ERR) return ERR;
	while(clientes[idx]->produtos != NULL) desfazer_ultima_compra(cpf , clientes, size);
	return OK;
}

