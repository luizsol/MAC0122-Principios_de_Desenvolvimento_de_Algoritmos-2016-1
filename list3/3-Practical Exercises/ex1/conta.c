#include <stdio.h> 
#include <string.h>


int read_word (FILE * arq, char * word) {
	/* This function reads a sequence of characters that contains only alphabetic */ 
	/* letters and underscore */
	/* For this exercise, you really do not2need to understand fully this function */ 
	/* Just use it */
	fscanf (arq, "%[^a-zA-Z_]", word);
	return fscanf (arq, "%[a-zA-Z_]", word);
}


int reserved (char *word, char ** reserved_words) {
	/* This function returns 1 if word is a reserved word; 0, otherwise */
	if (strcmp ("", *reserved_words) == 0) return 0;
	if (strcmp (word, *reserved_words) == 0) return 1;
	return reserved (word, reserved_words+1);
}

/* This program reads a C program and count the number of reserved words */
int main (int argc, char * argv[]) {
	FILE * arq;
	char * reservadas [] = {
		"auto", "break",  "case", "char",  "const", "continue", "default", "do",
		"double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    	"long", "register", "return", "short", "signed", "sizeof", "static", "struct",
    	"switch", "typedef", "union", "unsigned", "void", "volatile", "while", ""};
	int count;
	char word[1000], *filename;
	if (argc != 2) {
		printf ("Use: %s <source C programa filename>\n", argv[0]);
		return 0; 
	}
	filename = argv[1];
	arq = fopen (filename, "r");
	if (arq == NULL) {
    	printf ("File %s could not be found\n", filename);
		return 0; 
	}
	count = 0;
	while (read_word (arq, word) == 1)
		if (reserved (word, reservadas) == 1) count++;
    printf ("File %s contains %d reserved words\n", filename, count);
    fclose (arq);
    return 0;
}
