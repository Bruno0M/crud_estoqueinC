/* A proposta � fazer um controle de estoque de um armaz�m que abriga produtos diversos
para revenda. At� o momento, pensamos em implementar as op��es:

		- Adicionar produto
		- Retirar produto
		- Modificar informa��o
		- Excluir produto
		- Hist�rico de a��es
		
Isso ser� feito utilizando-se da TAD lista din�mica encadeada.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

typedef struct pdt{
	char id[20];
	char nome[70];
	float pesoUni;
	int quantidade;
	float precoUni;
	float precoTotal;
} dadosProduto;
/* Cada n� da lista corresponder� a uma struct pdt e um ponteiro. */

typedef struct listaP{
	dadosProduto produto;
	struct listaP* proximo;
} listaP;

void autenticacao(char* nomeUser){
	char nome[50], password[20];
	int t = 3;
	
	printf("|| Informe o nome de usu�rio: ");
	gets(nome);
	do{
		printf("|| Informe a senha de acesso: ");
		gets(password);
		if(strcmp(password, "arm2024storage") != 0){
			t--;
			if(t == 0) break;
			printf("(!) Restam %d tentativas.\n", t);
		}
	} while(strcmp(password, "arm2024storage") != 0 && t!=0);
	
	if(t == 0){
		system("cls");
		puts("~ Voc� zerou o n�mero de tentativas. O programa ser� encerrado. ~");
		exit(1);
	}
	else{
		puts("-----------------------------------------------------");
		strcpy(nomeUser, nome);
	 	puts(">> Login realizado COM SUCESSO.");
	 	printf("- Usu�rio: %s\n", nomeUser);
	 	time_t t; time(&t);
		printf("- Dados de login: %s", ctime(&t));
		
	 	system("pause");
	 	system("cls");
	}
}


int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	char userNome[50];
	int status;
	
	puts("========================================================================");
	puts("      BEM-VINDO AO SISTEMA DE CONTROLE DE ESTOQUE Almeida Storage!      ");
	puts("========================================================================");
	autenticacao(userNome);
	
	return 0;
}

