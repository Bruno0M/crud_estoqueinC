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

