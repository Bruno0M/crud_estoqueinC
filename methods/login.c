#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

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
