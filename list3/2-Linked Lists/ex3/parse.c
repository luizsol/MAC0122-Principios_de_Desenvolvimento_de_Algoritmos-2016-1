/** @file 	parse.c
 *  @brief 	Handles terminal user input
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/04
 */
 
 #include "parse.h"
 
/** @brief Splits a given string based on a given delimiter
 *
 *  (source=http://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c)
 *
 *  @param a_str the string to be splitted
 *  @param a_delim the splitting delimiter
 *  @return the pointer to the array containing the result
 */
char** str_split(char* a_str, const char a_delim){
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

/** @brief Determines the ammount of values passed by the user
 *
 *  @param str the string to scanned
 *  @param delim the splitting delimiter
 *  @return the ammount of values passed by the user
 */
int input_len(char *str, char delim){
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == delim){
			count++;
		}
	}
	return count + 1;
}

/** @brief Populates the list with the user input
 *
 *  @param str the string to scanned
 */
void populate_list(char *str){
	int size = input_len(str, ',');
	char **values = str_split(str, ',');
	for(int i = 0; i < size; i++){
		append(atoi(values[i]));
	}
	
}
