/** @file 	lists.c
 *  @brief 	Implements linked lists
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/04
 */
 
#include "lists.h" 

/** @brief Initializes the cells from the list array
 *
 */
void start_list(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("start_list()\n");
	
 	livre = inicio = 0;
 	
 	for(int i = 0; i < MAX; i++){
 		v[i].prox = -1;
 	}
 	
 	if(VERBOSE_LVL == HIGH_VERBOSE)
		print_array();
 }

/** @brief Removes a cell from the linked list
 *
 *  @rparam the index of the element
 */
void remove_idx(int idx){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("remove_idx(%d)\n",idx);
	if(idx == inicio){
		if(VERBOSE_LVL == HIGH_VERBOSE)
			printf("->Removing initial cell\n");
		inicio = v[idx].prox;
	} else {
		if(VERBOSE_LVL == HIGH_VERBOSE)
			printf("->Removing v[%d]\n",idx);
		v[get_previous(idx)].prox = v[idx].prox;
	}
	v[idx].prox = -1;
	update_free();
}

/** @brief Updates the value of the lowest index unlinked cell
 *
 *  @return the index of the free cell
 */
int update_free(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("update_free()\n");
	for(int i = 0; i < MAX; i++){
		if(get_previous(i) == -1 && i != inicio){
			if(VERBOSE_LVL == HIGH_VERBOSE)
				printf("->New free cell: %d\n", i);
			return livre = i;
		}
	}
	if(VERBOSE_LVL == HIGH_VERBOSE)
		printf("->No free cell available");
	return -1; //There is no free cell
}

/** @brief Gets the index of the previous cell of a given cell on the linked list
 *
 *  @param idx the index of the cell of which the previous cell will be searched
 *  @return the index of the previous cell
 */
int get_previous(int idx){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("get_previous(%d)\n", idx);
	for(int i = 0; i < MAX; i++){
		if(v[i].prox == idx){
			if(VERBOSE_LVL == HIGH_VERBOSE)
				printf("->Found v[%d]\n", i);
			return i;
		}
	}
	if(VERBOSE_LVL == HIGH_VERBOSE)
		printf("->Not found\n");
	return -1; //Has no previous element linked to this cell
}

/** @brief Search through the linked list for a cell with a given value
 *
 *  @param start_idx the index of the first cell of the search
 *  @param value the value to search for
 *  @return the index of the cell containing the value
 */
int loop_search(int start_idx, int value){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("loop_search(%d,%d)\n", start_idx, value);
	int idx = start_idx;
	while(idx != -1){
		if(v[idx].conteudo == value){
			if(VERBOSE_LVL == HIGH_VERBOSE)
				printf("->Found v[%d]\n", idx);
			return idx;	
		}
		idx = v[idx].prox;
	}
	if(VERBOSE_LVL == HIGH_VERBOSE)
		printf("->Not found\n");
	return -1;
}

/** @brief Removes any repeated appearences of a given value from the linked list
 *
 */
void remove_duplicated(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("remove_duplicated()\n");
	int idx = inicio;
	int to_delete = -1;
	while(idx != -1){
		do{
			to_delete = loop_search(v[idx].prox, v[idx].conteudo);
			if(to_delete != -1){
				if(VERBOSE_LVL == HIGH_VERBOSE)
					printf("->Foud cell to be deleted: v[%d]\n", to_delete);
				remove_idx(to_delete);
			}
		} while(to_delete != -1);
		idx = v[idx].prox;
	}
}

/** @brief Determines the index of the last cell on the linked list
 *
 *  @return the index of the last cell on the linked list
 */
int get_idx_from_last(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("get_idx_from_last()\n");
	if(inicio == livre){
		if(VERBOSE_LVL == HIGH_VERBOSE)
			printf("->List empty!\n");
		return -1;
	}
	int idx = inicio;
	while(v[idx].prox != -1)
		idx = v[idx].prox;
	if(VERBOSE_LVL == HIGH_VERBOSE)
		printf("->Index from the last item on list: %d\n", idx);
	return idx;
}

/** @brief Inserts a cell on the end of the linked list
 *
 *  @param value the value to be inserted
 */
void append(int value){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("append(%d)\n", value);
	insert(get_idx_from_last(), value);
}

/** @brief Inserts a cell on the linked list
 *
 *  @param idx the index of the cell that will preceed the new inserted cell
 *  @param value the value to be inserted
 */
void insert(int idx, int value){
	v[livre].conteudo = value;
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("insert(%d,%d)\n", idx, value);
	if(idx == -1){ //Empty list
		if(VERBOSE_LVL == HIGH_VERBOSE)
			printf("->Starting up empty list\n");
		v[livre].prox = -1;
	} else {
		if(VERBOSE_LVL == HIGH_VERBOSE)
			printf("->Contents of the cell to be inserted to: v[%d]:(%d,%d)\n", idx, v[idx].conteudo, v[idx].prox);
		v[livre].prox = v[idx].prox;
		v[idx].prox = livre;
	}
	if(VERBOSE_LVL == HIGH_VERBOSE)
		printf("->Cell to be inserted: v[%d]:(%d,%d)\n", livre, v[livre].conteudo, v[livre].prox);
	update_free();
}

/** @brief Prints the list contents
 *
 */
void print_list(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("print_list()\n");
	int idx = inicio;
	while(v[idx].prox != -1){
		printf("(%d)->", v[idx].conteudo);
		idx = v[idx].prox;
	}

	printf("(%d)\n",v[idx].conteudo);
}

/** @brief Prints the array containing the list
 *
 */
void print_array(){
	if(VERBOSE_LVL > NO_VERBOSE)
		printf("print_array()\n");
	printf("->inicio: %d, livre: %d\n->", inicio, livre);
	for(int i = 0; i < MAX; i++)
		printf("(%d,%d) ", v[i].conteudo, v[i].prox);
	puts("");
}
