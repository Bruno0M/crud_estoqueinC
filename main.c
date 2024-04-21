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
#include "./methods/login.c"

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
typedef listaP* listaPont;




int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	char userNome[50];
	int opc, status;
	
	puts("========================================================================");
	puts("      BEM-VINDO AO SISTEMA DE CONTROLE DE ESTOQUE Almeida Storage!      ");
	puts("========================================================================");
	autenticacao(userNome);
	
	do{
		puts("============ CONTROLE DE ESTOQUE (menu) ============");
		puts("[1] - Adicionar produto");
		puts("[2] - Retirar produto");
		puts("[3] - Ver estoque atual");
		puts("[4] - Ver hist�rico de opera��es");
		puts("[5] - Excluir produto");
		puts("[6] - Alterar usu�rio");
		puts("[0] - Sair");
		puts("====================================================");
		printf("|| Escolha uma op��o: ");
		scanf("%d", &opc);
		
		system("pause");
		system("cls");
	} while(opc != 0);
	
	return 0;
}

