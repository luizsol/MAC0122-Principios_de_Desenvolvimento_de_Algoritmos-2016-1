/** @file 	data.h
 *  @brief 	Deals with the data storage and manipulation
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#ifndef __DATA__H
#define __DATA__H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define OK 		0
#define ERR 		-1

#define VERB_LVL	0

#define NO_VERB		0
#define LOW_VERB	1
#define MED_VERB	2
#define HIG_VERB	3	

/**
 *  Represents the products being bought
 */
typedef struct produto {
	/*@{*/
	char *id;		/**< the product's id */
	char *nome;		/**< the product's name */
	char *marca;		/**< the product's brand */
	double preco;		/**< the product's price */
	struct produto * prox;	/**< the next product on the list */
	/*@}*/
} Produto;

/**
 *  Represents the clients
 */
typedef struct {
	/*@{*/
	long int cpf;		/**< the CPF of the client */
	char *nome;		/**< the name of the client */
	char *fone;		/**< the phone number of the client */
	char *email;		/**< the e-mail of the client */
	Produto *produtos;	/**< the list of products bought by the client */
	/*@}*/
} Cliente;

/** @brief Initializes the array of clients
 *
 *  @param size the maximum number of clients
 */
Cliente ** novo_array_clientes(int size);

/** @brief Searches for a client by his cpf, returning it's position on the clients array
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @return the index of the client pointer on a clients array
 */
int buscar_cliente(long int cpf , Cliente ** clientes, int size);

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
int inserir_novo_cliente(long int cpf, char *nome, char *fone, char *email, Cliente **clientes, int size);

/** @brief Removes a client from a clients array
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int remover_cliente(long int cpf , Cliente ** clientes, int size);

/** @brief Updates the client's phone number
 *
 *  @param novo_telefone the client's new phone number
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int atualizar_telefone(char* novo_telefone, long int cpf , Cliente ** clientes, int size);

/** @brief Updates the client's name
 *
 *  @param novo_nome the client's new name
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int atualizar_nome(char* novo_nome, long int cpf , Cliente ** clientes, int size);

/** @brief Updates the client's CPF
 *
 *  @param novo_cpf the client's new cpf
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int atualizar_cpf(long int novo_cpf, long int cpf , Cliente ** clientes, int size);

/** @brief Updates the client's e-Mail
 *
 *  @param email the client's new e-Mail
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int atualizar_email(char* email, long int cpf , Cliente ** clientes, int size);

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
int inserir_novo_produto(char *id, char *nome, char *marca, double preco, long int cpf, Cliente ** clientes, int size); //TODO checar

/** @brief Removes the last item from the client's products list
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int desfazer_ultima_compra(long int cpf , Cliente ** clientes, int size); //TODO checar

/** @brief Removes all itens from the client's products list
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the status of the operation
 */
int remover_todos_produtos(long int cpf , Cliente ** clientes, int size); //TODO checar

/** @brief Gets a product by its index
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @param idx the index of the product
 *  @return the status of the operation
 */
Produto* selecionar_produto_idx(long int cpf, Cliente** clientes, int size, int idx);

/** @brief Determines the ammount of products bought by a given person
 *
 *  @param cpf the client's CPF
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the ammount of products bought by a given person
 */
int quantidade_produtos(long int cpf, Cliente** clientes, int size);

/** @brief Determines the number of clients on a clients array
 *
 *  @param clientes the clients array
 *  @param size the size of the array
 *  @return the number of clients
 */
int numero_clientes(Cliente ** clientes, int size);

#endif
