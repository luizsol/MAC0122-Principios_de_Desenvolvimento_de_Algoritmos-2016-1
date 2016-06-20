/** @file 	data.h
 *  @brief 	Deals with user's Inputs and Outputs
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#include "interface.h"

void update(GUI* screen);
void print_screen(GUI* screen);
void goto_add_client(GUI* screen);
void goto_shw_client(GUI* screen);
void goto_shw_clients(GUI* screen);

Cliente ** clientes;

/** @brief Determines the number of columns on the current window
 *
 *  @return the number of columns on the current window
 */
int win_size_col(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}

/** @brief Determines the number of rows on the current window
 *
 *  @return the number of rows on the current window
 */
int win_size_row(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}

/** @brief Clears the screen
 *
 */
void clear_screen(){
#ifdef WINDOWS
    system("cls");
#else
    // Assume POSIX
    system ("clear");
#endif
}

char getrawchar(){
#ifndef WINDOWS
	//Hiding the echo and eliminating the need for the enter
	system("stty -echo");
	system ("stty raw");
#endif
	char c;
	c = getchar();
#ifndef WINDOWS
	//Hiding the echo and eliminating the need for the enter
	system("stty echo");
	system ("stty -raw");
#endif
	return c;
}

void print_colors(){//TODO remover
	 printf("%sred\n", KRED);
	 printf("%sgreen\n", KGRN);
	 printf("%syellow\n", KYEL);
	 printf("%sblue\n", KBLU);
	 printf("%smagenta\n", KMAG);
	 printf("%scyan\n", KCYN);
	 printf("%swhite\n", KWHT);
	 printf("%snormal\n", KNRM);
}

/** @brief Produces the formatted text for the root screen
 *
 *  @return the formated root display string
 */
char * root_display_string(){
	int rows = win_size_row();
	int cols = win_size_col();
	
	int fill_top = (rows - MENU_ROWS - 1)/2;
	int fill_bot = rows - MENU_ROWS - 1 - fill_top;
	
	char* str = "Sistema de Gestao de Mercado";
	int str_len = (int) strlen(str);
	
	int fill_sidel = (cols-str_len)/2;
	
	char* display = (char*)malloc((rows*cols+1)*sizeof(char));
	strcpy(display, "");
	
	for(int i = 0; i<fill_top; i++) strcat(display, "\n");
	for(int i = 0; i<fill_sidel; i++) strcat(display, " ");
	strcat(display, str);
	for(int i = 0; i<=fill_bot; i++) strcat(display, "\n");
	
	
	
	return display;
}

/** @brief Produces the formatted text for the root menu
 *
 *  @return the formated root menu string
 */
char * root_menu_string(){
	int rows = win_size_row();
	int cols = win_size_col();
	
	char * menu = (char*)malloc((rows*cols+1)*sizeof(char));
	strcpy(menu, "");
	
	char *str = "Menu Inicial";
	int str_len = (int) strlen(str);
	
	int fill_sidel = (cols-str_len)/2;
	int fill_sider = cols-str_len-fill_sidel;
	
	for(int i = 0; i<fill_sidel; i++) strcat(menu, "-");
	strcat(menu, str);
	for(int i = 0; i<fill_sider; i++) strcat(menu, "-");
	strcat(menu, "\n");
	
	strcat(menu, "<A>: Adicionar Cliente\t\t\t<S>Salvar Estado Atual\n");
	strcat(menu, "<R>: Remover Cliente\t\t\t<X>Sair\n");
	strcat(menu, "<V>: Visualizar Todos os Clientes\n");
	
	return menu;
	
}

void update_display_string(GUI* screen, char* text){
	int rows = win_size_row();
	int cols = win_size_col();
	
	int fill_top = (rows - MENU_ROWS - 1)/2;
	int fill_bot = rows - MENU_ROWS - 1 - fill_top;
	
	char* display = (char*)malloc((rows*cols+1)*sizeof(char));
	strcpy(display, "");
	
	for(int i = 0; i<fill_top; i++) strcat(display, "\n");
	
	if(screen->current_screen == SCRN_ROOT){
		int str_len = (int) strlen(text);
		int fill_sidel = (cols-str_len)/2;
		for(int i = 0; i<fill_sidel; i++) strcat(display, " ");
	}
	
	strcat(display,text);
	for(int i = 0; i<fill_bot; i++) strcat(display, "\n");
	
	
	if(screen->display_free) free(screen->display);
	else screen->display_free = 1;
	
	screen->display = display;
}

void update_menu_string(GUI* screen, char* name, List* options){
	int rows = win_size_row()-1;
	int cols = win_size_col();
	
	char * menu = (char*)malloc((rows*cols+1)*sizeof(char));
	strcpy(menu, "");
	
	int str_len = (int) strlen(name);
	
	int fill_sidel = (cols-str_len)/2;
	int fill_sider = cols-str_len-fill_sidel;
	
	for(int i = 0; i<fill_sidel; i++) strcat(menu, "-");
	strcat(menu, name);
	for(int i = 0; i<fill_sider; i++) strcat(menu, "-");
	strcat(menu, "\n");
	
	for(int i = 0; i < 3; i++){
		strcat(menu, get_cell_by_idx(options, i)->content);
		if(list_len(options) > 3 + i){
			strcat(menu, "\t\t\t");
			strcat(menu, get_cell_by_idx(options, 3+i)->content);
		}
		strcat(menu, "\n");
		
	}
	
	if(screen->menu_free) free(screen->menu);
	else screen->menu_free = 1;
	
	screen->menu = menu;
}

void update_client_label(char* display_str, char* name_label, char* name_str, char* email_label, char* email_str, char* telefone_label, char* telefone_str, char* cpf_label, char* cpf_str){
	strcpy(display_str, name_label);
	strcat(display_str, name_str);
	strcat(display_str, "\n");
	strcat(display_str, email_label);
	strcat(display_str, email_str);
	strcat(display_str, "\n");
	strcat(display_str, telefone_label);
	strcat(display_str, telefone_str);
	strcat(display_str, "\n");
	strcat(display_str, cpf_label);
	strcat(display_str, cpf_str);
}

void update_client_name(GUI* screen){

}

void goto_add_client(GUI* screen){
	int name_ok = 0;
	int email_ok = 0;
	int telefone_ok = 0;
	int cpf_ok = 0;
	
	List * options = new_empty_list();
	append(options, "<N>: Inserir Nome");
	append(options, "<E>: Inserir e-mail");
	append(options, "<F>: Inserir telefone");
	append(options, "<C>: Inserir CPF");
	//append(options, "<S>: Salvar Alteracoes");
	append(options, "<X>: Sair");
	
	char* name_label = (char*) malloc(100*sizeof(char));
	strcpy(name_label, "Nome:\t");
	char* email_label = (char*) malloc(100*sizeof(char));
	strcpy(email_label, "e-mail:\t");
	char* telefone_label = (char*) malloc(100*sizeof(char));
	strcpy(telefone_label, "Telefone:\t");
	char* cpf_label = (char*) malloc(100*sizeof(char));
	strcpy(cpf_label, "CPF:\t");
	
	char* name_str = (char*) malloc(100*sizeof(char));
	strcpy(name_str, "");
	char* email_str = (char*) malloc(100*sizeof(char));
	strcpy(email_str, "");
	char* telefone_str = (char*) malloc(100*sizeof(char));
	strcpy(telefone_str, "");
	char* cpf_str = (char*) malloc(100*sizeof(char));
	strcpy(cpf_str, "");
	
	
	char* display_str = (char*) malloc(1000*sizeof(char));
	update_client_label(display_str, name_label, name_str, email_label, email_str, telefone_label, telefone_str, cpf_label, cpf_str);
	
	update_display_string(screen, display_str);
	update_menu_string(screen, "Adicionar Cliente", options);
	print_screen(screen);
	
	char c = '.';
	while(c != 'n' && c != 'N' && c != 'e' && c != 'E' && c != 'f' && c != 'F' && c != 'c' && c != 'C' && c != 's' && c != 'S' && c != 'x' && c != 'X') c = getrawchar();
	int loop = 1;
	while (loop){
		switch(c){
		case 'n':
		case 'N':
			//enter is 13
			free(get_cell_by_idx(options, 0)->content);
			get_cell_by_idx(options, 0)->content = strdup("\x1B[31m<N>: Inserir Nome\x1B[0m");
			free(name_label);
			name_label = strdup("\x1B[31mNome:\x1B[0m\t");
			update_client_label(display_str, name_label, name_str, email_label, email_str, telefone_label, telefone_str, cpf_label, cpf_str);
			update_display_string(screen, display_str);
			update_menu_string(screen, "Adicionar Cliente", options);
			print_screen(screen);
			c = getrawchar();
			while(c != 13){
				if(c == 127 || c == 8 || c == '\b'){
					free(name_str);
					name_str = (char*) malloc(100*sizeof(char));
					strcpy(name_str, "");
				}
				else {
					char input[] = {c,'\0'};
					strcat(name_str,input);
				}
				update_client_label(display_str, name_label, name_str, email_label, email_str, telefone_label, telefone_str, cpf_label, cpf_str);
				update_display_string(screen, display_str);
				update_menu_string(screen, "Adicionar Cliente", options);
				print_screen(screen);
				c = getrawchar();
			}
			free(get_cell_by_idx(options, 0)->content);
			get_cell_by_idx(options, 0)->content = strdup("<N>: Inserir Nome");
			free(name_label);
			name_label = strdup("Nome:\t");
			update_client_label(display_str, name_label, name_str, email_label, email_str, telefone_label, telefone_str, cpf_label, cpf_str);
			update_display_string(screen, display_str);
			update_menu_string(screen, "Adicionar Cliente", options);
			print_screen(screen);
		
			if(strlen(name_str)>0) name_ok = 1;
			else name_ok = 0;
		
			
		
			break;
		default:
			break;
		}
		if(name_ok && email_ok && telefone_ok && cpf_ok){
			if(list_len(opcoes) != 5) append(options, "<S>: Salvar Alteracoes");
		}
	}
	
	
}

void goto_rem_client(GUI* screen){
	puts("remove client");
}

void goto_shw_clients(GUI* screen){
	puts("show clients");
}

void goto_shw_client(GUI* screen){
	puts("show client");
}

void save_all(){

}

void goto_root(GUI* screen){
	List * options = new_empty_list();
	append(options, "<A>: Adicionar Cliente");
	append(options, "<R>: Remover Cliente");
	append(options, "<V>: Visualizar Todos os Clientes");
	append(options, "<S>: Salvar Estado Atual");
	append(options, "<X>: Sair");
	screen->current_screen = SCRN_ROOT;
	update_display_string(screen, "Sistema de Gestao de Mercado");
	update_menu_string(screen, "Menu Inicial", options);
	print_screen(screen);
	char c = '.';

	while(c != 'a' && c != 'A' && c != 'r' && c != 'R' && c != 'v' && c != 'V' && c != 's' && c != 'S' && c != 'x' && c != 'X') c = getrawchar();

	switch(c){
	case 'a':
	case 'A':
		screen->current_screen = SCRN_ADD_CLIENT;
		goto_add_client(screen);
		screen->current_screen = SCRN_ROOT;
		break;
	case 'r':
	case 'R':
		screen->current_screen = SCRN_REM_CLIENT;
		goto_rem_client(screen);
		screen->current_screen = SCRN_ROOT;
		break;
	case 'v':
	case 'V':
		screen->current_screen = SCRN_SHW_CLIENTS;
		goto_shw_clients(screen);
		screen->current_screen = SCRN_ROOT;
		break;
	case 's':
	case 'S':
		save_all();
		break;
	default:
		screen->running = 0;
	}	
}

void print_screen(GUI* screen){
	clear_screen();
	printf("%s",screen->display);
	printf("%s",screen->menu);
}

void update(GUI* screen){
	while(1){
		if(screen->running == 1){
			switch(screen->current_screen){
			case SCRN_ROOT:
				goto_root(screen);
				break;
			default:
				break;
			}
		} else {
			system("stty echo");
			system ("stty -raw");
			exit(0);
		}
	}
}

GUI* new_GUI(){
	GUI* screen = (GUI*) malloc(sizeof(GUI));
	screen->current_screen = SCRN_ROOT;
	return screen;
}

int start(){
	clientes = novo_array_clientes(SIZE);
	GUI* screen = new_GUI();
	screen->running = 1;
	screen->display_free = 0;
	screen->menu_free = 0;
	screen->current_screen = 0;
	update(screen);
	
	return 0;
}
