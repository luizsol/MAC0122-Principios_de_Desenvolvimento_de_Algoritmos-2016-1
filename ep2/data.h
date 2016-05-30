/** @file 	data.h
 *  @brief 	Deals with the data storage and manipulation
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#ifndef __DATA__H
#define __DATA__H

/**
 *  Represents the products being bought
 */
typedef struct produto{
	/*@{*/
	char *id;		/**< the id of the product */
	char *nome;		/**< the name of the client */
	char *marca;	/**< the the brand of the product */
	double preco;	/**< the price of the product */
	struct produto * prox;	/**< the next product on the list */
	/*@}*/
} Produto;

/**
 *  Represents the clients
 */
typedef struct {
	/*@{*/
	int content;	/**< the content of the cell */
	char *nome;		/**< the name of the client */
	char *fone;		/**< the phone number of the client */
	char *email;	/**< the e-mail of the client */
	Produto *produto;	/**< the list of products bought by the client */
	/*@}*/
} Cliente;


#endif