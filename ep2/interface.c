/** @file 	data.h
 *  @brief 	Deals with user's Inputs and Outputs
 *         	Source: MAC0122 - University of São Paulo
 *         	Repository: https://github.com/luizsol/MAC0122
 *  @author 	Luiz Sol (luizedusol@gmail.com)
 *  @date	2016/05/30
 */

#include "interface.h"

Cliente ** clientes;
int tela_atual = MENU_PRINCIPAL;

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

void trim (char *s) {
	int i = strlen(s)-1;
	if ((i > 0) && (s[i] == '\n')) s[i] = '\0';
}

int win_size_row(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}

void GUI_menu_inicio(){
	clear_screen();
	puts("Selecione uma das opcoes:");
	puts("[1]Adicionar cliente");
	puts("[2]Remover cliente");
	puts("[3]Editar informacoes de cliente");
	puts("[4]Visualizar todos os clientes");
	puts("[5]Editar carrinho de compras de um cliente");
	puts("[6]Salvar alteracoes e Sair");
	
	char c = getrawchar();
	while(c != '1' && c !='2' && c != '3' && c != '4' && c != '5' && c != '6') c = getrawchar();
	switch(c){
	case '1':
		tela_atual = ADICIONAR_CLIENTE;
		break;
	case '2':
		tela_atual = REMOVER_CLIENTE;
		break;
	case '3':
		tela_atual = EDITAR_CLIENTE;
		break;
	case '4':
		tela_atual = VISUALIZAR_TUDO;
		break;
	case '5':
		tela_atual = EDITAR_CARRINHO;
		break;
	default:
		exit(0);
	}
}

void GUI_adicionar_cliente(){
	int incorreto = 1;
	clear_screen();
	while(incorreto){
		puts("Insira o nome do Cliente:");
		char* nome = (char*)malloc(100*sizeof(char));
		fgets(nome, 100, stdin);
		trim(nome);
	
		puts("Insira o CPF do Cliente:");
		char* cpf = (char*)malloc(100*sizeof(char));
		fgets(cpf, 100, stdin);
		trim(cpf);
	
		puts("Insira o telefone do Cliente:");
		char* telefone = (char*)malloc(100*sizeof(char));
		fgets(telefone, 100, stdin);
		trim(telefone);
	
		puts("Insira o e-Mail do Cliente:");
		char* email = (char*)malloc(100*sizeof(char));
		fgets(email, 100, stdin);
		trim(email);
		
		clear_screen();
		printf("Nome:\t\t%s\n", nome);
		printf("CPF:\t\t%s\n", cpf);
		printf("Telefone:\t%s\n", telefone);
		printf("e-Mail:\t\t%s\n", email);
		puts("Essas informacoes estao corretas?[s/n]");
		char c = getrawchar();
		while(c != 's' && c !='S' && c != 'n' && c != 'N') c = getrawchar();
		if(c == 's'){
			incorreto = 0;
			inserir_novo_cliente(atol(cpf), nome, telefone, email, clientes, SIZE);
			tela_atual = MENU_PRINCIPAL;
		}
	}
}

void GUI_remover_cliente(){
	int incorreto = 1;
	clear_screen();
	while(incorreto){
		puts("Insira o CPF do cliente a ser removido:");
		char* cpf = (char*)malloc(100*sizeof(char));
		fgets(cpf, 100, stdin);
		
		int idx = buscar_cliente(atol(cpf) , clientes, SIZE);
		
		if(idx == ERR){
			puts("CPF Inexistente!");
		} else {
		
			clear_screen();
			printf("Nome:\t\t%s\n", clientes[idx]->nome);
			printf("CPF:\t\t%ld\n", clientes[idx]->cpf);
			printf("Telefone:\t%s\n", clientes[idx]->fone);
			printf("e-Mail:\t\t%s\n", clientes[idx]->email);
			puts("Deseja remover esse cliente?[s/n]");
			char c = getrawchar();
			while(c != 's' && c !='S' && c != 'n' && c != 'N') c = getrawchar();
			if(c == 's'){
				remover_cliente(clientes[idx]->cpf , clientes, SIZE);
				puts("Cliente removido. Pressione qualquer tecla para continuar...");
			} else puts("Operacao cancelada. Pressione qualquer tecla para continuar...");
			getrawchar();
			clear_screen();
		}
		 	
		puts("Deseja remover outro cliente?[s/n]");
		char c = getrawchar();
		while(c != 's' && c !='S' && c != 'n' && c != 'N') c = getrawchar();
		if(c == 'n'){
			incorreto = 0;
			tela_atual = MENU_PRINCIPAL;
		}
	}
}

void GUI_editar_cliente(){
	int incorreto = 1;
	clear_screen();
	while(incorreto){
		puts("Insira o CPF do cliente a ser editado:");
		char* cpf = (char*)malloc(100*sizeof(char));
		fgets(cpf, 100, stdin);
		
		int idx = buscar_cliente(atol(cpf) , clientes, SIZE);
		
		if(idx == ERR){
			puts("CPF Inexistente!");
		} else {
			int edit = 1;
			while(edit){
				clear_screen();
			
				printf("Nome:\t\t%s\n", clientes[idx]->nome);
				printf("CPF:\t\t%ld\n", clientes[idx]->cpf);
				printf("Telefone:\t%s\n", clientes[idx]->fone);
				printf("e-Mail:\t\t%s\n", clientes[idx]->email);
				puts("Qual informacao deseja editar?");
				puts("[1]Nome");
				puts("[2]CPF");
				puts("[3]Telefone");
				puts("[4]e-Mail");
				puts("[5]Sair");
				char c = getrawchar();
				while(c != '1' && c !='2' && c != '3' && c != '4' && c != '5') c = getrawchar();
				switch(c){
				case '1':
					clear_screen();
					puts("Insira o nome do Cliente:");
					char* nome = (char*)malloc(100*sizeof(char));
					fgets(nome, 100, stdin);
					trim(nome);
					atualizar_nome(nome, atol(cpf), clientes, SIZE);
					free(nome);
					break;
				case '2':
					clear_screen();
					puts("Insira o CPF do Cliente:");
					char* n_cpf = (char*)malloc(100*sizeof(char));
					fgets(n_cpf, 100, stdin);
					trim(n_cpf);
					int result = atualizar_cpf(atol(n_cpf), atol(cpf), clientes, SIZE);
					if(result != ERR) cpf = n_cpf;
					else{
						puts("Erro na operacao");
						puts("Pressione qualquer tecla para continuar...");
						getrawchar();	
					}
					break;
				case '3':
					clear_screen();
					puts("Insira o telefone do Cliente:");
					char* telefone = (char*)malloc(100*sizeof(char));
					fgets(telefone, 100, stdin);
					trim(telefone);
					atualizar_telefone(telefone, atol(cpf), clientes, SIZE);
					free(telefone);
					break;
				case '4':
					clear_screen();
					puts("Insira o e-Mail do Cliente:");
					char* email = (char*)malloc(100*sizeof(char));
					fgets(email, 100, stdin);
					trim(email);
					atualizar_email(email, atol(cpf), clientes, SIZE);
					free(email);
					break;
				default:
					edit = 0;
					break;
				}
			}
		}
		clear_screen();
		puts("Deseja editar outro cliente?[s/n]");
		char c = getrawchar();
		while(c != 's' && c !='S' && c != 'n' && c != 'N') c = getrawchar();
		if(c == 'n'){
			incorreto = 0;
			tela_atual = MENU_PRINCIPAL;
		}
	}
}

int print_client(Cliente* cliente){
	int rows = 5;
	printf("CPF: %ld\n", cliente->cpf);
	printf("\tNome: %s\n", cliente->nome);
	printf("\tTelefone: %s\n", cliente->fone);
	printf("\te-Mail: %s\n", cliente->email);
	int n_products = quantidade_produtos(cliente->cpf, clientes, SIZE);
	double total = 0.0;
	for(int i = 0; i < n_products; i++) total+=selecionar_produto_idx(cliente->cpf, clientes, SIZE, i)->preco;
	printf("\tCompras(Total: R$%.2f):\n", total);
	if(n_products == 0) puts("\t\t[Sem produtos]");
	else{
		for(int i = 0; i<n_products;i++){
			Produto* prod = selecionar_produto_idx(cliente->cpf, clientes, SIZE, i);
			printf("\t\tID:%s\tNome:%s\tMarca:%s\tPreco:%.2f\n",prod->id ,prod->nome, prod->marca, prod->preco);
		}
	}
	return rows;
}

void GUI_visualizar_tudo(){ //TODO
	clear_screen();
	
	//int rows = win_size_row();
	int n_clientes =  numero_clientes(clientes, SIZE);
	
	for(int i = 0; i < n_clientes; i++){
		print_client(clientes[i]);
	}
	
	tela_atual = MENU_PRINCIPAL;
	puts("Pressione qualquer tecla para continuar...");
	getrawchar();
	
	
}

void GUI_editar_carrinho(){
	clear_screen();
	int incorreto = 1;
	while(incorreto){
		puts("Insira o CPF do cliente a ser editado:");
		char* cpf = (char*)malloc(100*sizeof(char));
		fgets(cpf, 100, stdin);
	
		int idx = buscar_cliente(atol(cpf) , clientes, SIZE);
		
		if(idx == ERR){
			puts("CPF Inexistente!");
		} else {
			int edit = 1;
			while(edit){
				clear_screen();
				print_client(clientes[idx]);
		
				puts("Selecione uma acao:");
				puts("[1]Desfazer ultima compra");
				puts("[2]Adicionar produto");
				puts("[3]Sair");
	
				char c = getrawchar();
				while(c != '1' && c !='2' && c != '3') c = getrawchar();
				switch(c){
				case '1':
					desfazer_ultima_compra(atol(cpf) , clientes, SIZE);
					break;
				case '2':
					puts("Insira o ID do produto:");
					char* id = (char*)malloc(100*sizeof(char));
					fgets(id, 100, stdin);
					trim(id);
					puts("Insira o nome do produto:");
					char* nome = (char*)malloc(100*sizeof(char));
					fgets(nome, 100, stdin);
					trim(nome);
					puts("Insira a marca do produto:");
					char* marca = (char*)malloc(100*sizeof(char));
					fgets(marca, 100, stdin);
					trim(marca);
					puts("Insira o preco do produto:");
					char* preco = (char*)malloc(100*sizeof(char));
					fgets(preco, 100, stdin);
					trim(preco);
			
					inserir_novo_produto(id, nome, marca, atof(preco), atol(cpf), clientes, SIZE);
					break;
				case '3':
					edit = 0;
				}
			}
		}
		clear_screen();
		puts("Deseja editar outro carrinho de compras?[s/n]");
		char c = getrawchar();
		while(c != 's' && c !='S' && c != 'n' && c != 'N') c = getrawchar();
		if(c == 'n'){
			incorreto = 0;
			tela_atual = MENU_PRINCIPAL;
		}
	}
}

int print_client_txt(Cliente* cliente, FILE *pfile){
	int rows = 5;
	fprintf(pfile, "CPF: %ld\n", cliente->cpf);
	fprintf(pfile, "\tNome: %s\n", cliente->nome);
	fprintf(pfile, "\tTelefone: %s\n", cliente->fone);
	fprintf(pfile, "\te-Mail: %s\n", cliente->email);
	int n_products = quantidade_produtos(cliente->cpf, clientes, SIZE);
	double total = 0.0;
	for(int i = 0; i < n_products; i++) total+=selecionar_produto_idx(cliente->cpf, clientes, SIZE, i)->preco;
	fprintf(pfile, "\tCompras(Total: R$%.2f):\n", total);
	if(n_products == 0) puts("\t\t[Sem produtos]");
	else{
		for(int i = 0; i<n_products;i++){
			Produto* prod = selecionar_produto_idx(cliente->cpf, clientes, SIZE, i);
			fprintf(pfile, "\t\tID:%s\tNome:%s\tMarca:%s\tPreco:%.2f\n",prod->id ,prod->nome, prod->marca, prod->preco);
		}
	}
	return rows;
}

void GUI_salva(){
	FILE * pFile;
   	pFile = fopen ("mercadinho_out.txt","w+");
   	int n_clientes =  numero_clientes(clientes, SIZE);
	
	for(int i = 0; i < n_clientes; i++){
		print_client_txt(clientes[i], pFile);
	}
   	fclose (pFile);
   	tela_atual = -1;
}

void main_loop(){
	while(1){
		switch(tela_atual){
		case MENU_PRINCIPAL:
			GUI_menu_inicio();
			break;
		case ADICIONAR_CLIENTE:
			GUI_adicionar_cliente();
			break;
		case REMOVER_CLIENTE:
			GUI_remover_cliente();
			break;
		case EDITAR_CLIENTE:
			GUI_editar_cliente();
			break;
		case VISUALIZAR_TUDO:
			GUI_visualizar_tudo();
			break;
		case EDITAR_CARRINHO:
			GUI_editar_carrinho();
			break;
		default:
			GUI_salva();
			exit(0);
			break;
		}
	}
}


int start(){
	clientes = novo_array_clientes(SIZE);

	main_loop();
	
	return 0;
}
