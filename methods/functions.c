#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

/* Defini��o da lista */
typedef struct pdt{
	char id[20];
	char nome[70];
	float pesoUni;
	int quantidade;
	float precoUni;
} dadosProduto;
/* Cada n� da lista corresponder� a uma struct pdt e um ponteiro. */

typedef struct listaP{
	dadosProduto produto;
	struct listaP* proximo;
} listaP;
typedef listaP* listaPont;


/* Fun��o de login */
void autenticacao(char* nomeUser){
	setlocale(LC_ALL, "Portuguese");
	
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

/* Fun��o adicionar produtos */
int adicionar(listaPont* P, char id[], char nome[], float pesoUni, int quantidade, float precoUni) {
	listaPont novo;
    
    novo = (listaPont)malloc(sizeof(listaP));
    if (novo == NULL) return 0; // Erro de aloca��o de mem�ria.

    strcpy(novo->produto.id, id);
    strcpy(novo->produto.nome, nome);
    novo->produto.pesoUni = pesoUni;
    novo->produto.quantidade = quantidade;
    novo->produto.precoUni = precoUni;
    novo->proximo = NULL;
    
    if(*P == NULL){
        *P = novo;
        return 1;
    }
    
    listaPont copia, auxiliar;
    copia = *P;
    while (copia != NULL){
        auxiliar = copia;
        copia = copia->proximo;
    }
    auxiliar->proximo = novo;
    return 1;
}
