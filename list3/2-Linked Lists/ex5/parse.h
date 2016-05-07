/** @file 	parse.h
 *  @brief 	Handles terminal user input
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/04
 */
 
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>
#include "lists.h"

/** @brief Splits a given string based on a given delimiter
 *
 *  (source=http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c)
 *
 *  @param a_str the string to be splitted
 *  @param a_delim the splitting delimiter
 *  @return the pointer to the array containing the result
 */
char** str_split(char* a_str, const char a_delim);

/** @brief Determines the ammount of values passed by the user
 *
 *  @param str the string to scanned
 *  @param delim the splitting delimiter
 *  @return the ammount of values passed by the user
 */
int input_len(char *str, char delim);

/** @brief Populates a List with a comma separated string
 *
 *  @param list the List to be populated
 *  @param str the comma separated string
 */
void populate_list(List *list, char *str);
