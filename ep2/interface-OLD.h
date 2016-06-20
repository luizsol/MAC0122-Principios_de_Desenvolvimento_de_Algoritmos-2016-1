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
#include "lists.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

//#define WINDOWS //Uncomment this section if using windows

#define KNRM  	"\x1B[0m"
#define KRED  	"\x1B[31m"
#define KGRN  	"\x1B[32m"
#define KYEL 	"\x1B[33m"
#define KBLU  	"\x1B[34m"
#define KMAG  	"\x1B[35m"
#define KCYN  	"\x1B[36m"
#define KWHT  	"\x1B[37m"

#define MENU_ROWS 4
#define SIZE 100

#define SCRN_ROOT		0
#define SCRN_ADD_CLIENT 	1
#define SCRN_REM_CLIENT		2
#define SCRN_SHW_CLIENTS	3
#define SCRN_SHW_CLIENT		4
#define SCRN_ADD_PRODUCT	5

/**
 *  Represents the text that will be displayed on the screen
 */
typedef struct{
	/*@{*/
	int running;		/**< The current screen being displayed */
	int current_screen;	/**< The current screen being displayed */
	char * display;		/**< The main information on the screen */
	int display_free;	/**< Whether there is a display string on the heap */
	char * menu;		/**< The menu options */
	int menu_free;		/**< Whether there is a menu string on the heap */
	char * input;		/**< The optional input area */
	/*@}*/
}GUI;

/** @brief The main loop that executes the system
 *
 *  @return the execution status
 */
int start();

#endif
