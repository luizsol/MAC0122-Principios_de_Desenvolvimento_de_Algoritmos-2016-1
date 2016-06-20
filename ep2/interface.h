/** @file 	data.h
 *  @brief 	Deals with user's Inputs and Outputs
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#ifndef __INTERFACE__H
#define __INTERFACE__H

#include "data.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define SIZE 100
//#define WINDOWS //Uncomment if in a windows enviroment

#define MENU_PRINCIPAL 		0
#define ADICIONAR_CLIENTE	1
#define REMOVER_CLIENTE 	2
#define EDITAR_CLIENTE		3
#define VISUALIZAR_TUDO		4
#define EDITAR_CARRINHO 	5

/** @brief The main loop that executes the system
 *
 *  @return the execution status
 */
int start();

#endif
