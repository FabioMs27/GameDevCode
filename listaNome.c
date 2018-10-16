#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int main(){
	
	char nome[MAX][MAX],resp;
	FILE *fp;
	FILE *fp2;
	int i = 0,sair = 0;
	
	for(;;){
		system("cls");
		printf("1-incluir\n2-alterar\n3-excluir\n4-listar\n5-ordenar\n6-sair\n");
		resp = getch();
		
		switch(resp){
			case '1': //INCLUIR 
				system("cls");
				fp = fopen("nomes", "ab+");
				if(fp == NULL){
					printf("deu ruim!");
					exit(1);
				}
				
				printf("Digite seu nome: ");
				scanf(" %s", nome);
				
				fprintf(fp ,"%s\n", nome);
				fclose(fp);
			break;
			
			case '2': //ALTERAR *
				system("cls");
				
				char nomeAlt[MAX],pesquisa[MAX],copiar[1000];
				int achou = 0,j=0;
				
				printf("Digite o nome que deseja alterar: ");
				scanf(" %s", pesquisa);
				printf("Digite o novo nome: ");
				scanf(" %s", nomeAlt);
				
				fp = fopen("nomes", "rb");
				if(fp==NULL){
					printf("Arquivo nao existe!");
					exit(1);
				}
				i=0;
				
				while(!feof(fp)){
					fscanf(fp, "%s", nome[i]);
					i++;
				}
				
				fclose(fp);
				
				fp2 = fopen("nomes2", "ab+");
				if(fp2==NULL){
					printf("Deu ruim");
					exit(1);
				}
				for(j=0;j<i-1;j++){
					if(!strcmp(nome[j],pesquisa)){
						fprintf(fp2,"%s\n", nomeAlt);
						achou = 1;
					}
					else{
						fprintf(fp, "%s\n", nome[j]);
					}
				}
				
				if(achou == 0){
					printf("nao achou!");
					getch();
				}
				fclose(fp2);
				
				fp2 = fopen("nomes2","rb");
				fp = fopen("nomes", "wb");
				
				if(fp == NULL || fp2 == NULL){
					printf("deu ruim");
					exit(1);
				}
				
				while(fgets(copiar, 1000, fp2)!=NULL)
					fputs(copiar,fp);
				
				fclose(fp);
				fclose(fp2);
				remove("nomes2");
				if(achou == 1){
					system("cls");
					printf("Alterado com sucesso!");
					getch();
				}
				
			break;
			
			case '3':
				system("cls");
				achou = 0;
				
				printf("Digite o nome que deseja excluir: ");
				scanf(" %s", pesquisa);
				
				fp = fopen("nomes", "rb");
				if(fp==NULL){
					printf("Arquivo nao existe!");
					exit(1);
				}
				i=0;
				
				while(!feof(fp)){
					fscanf(fp, "%s", nome[i]);
					i++;
				}
				
				fclose(fp);
				
				fp2 = fopen("nomes2", "ab+");
				if(fp2==NULL){
					printf("Deu ruim");
					exit(1);
				}
				for(j=0;j<i-1;j++){
					if(strcmp(nome[j],pesquisa)){
						fprintf(fp2,"%s\n", nome[j]);
					}
					else{
						achou = 1;
					}
				}
				
				if(achou == 0){
					printf("nao achou!");
					getch();
				}
				fclose(fp2);
				
				fp2 = fopen("nomes2","rb");
				fp = fopen("nomes", "wb");
				
				if(fp == NULL || fp2 == NULL){
					printf("deu ruim");
					exit(1);
				}
				
				while(fgets(copiar, 1000, fp2)!=NULL)
					fputs(copiar,fp);
				
				fclose(fp);
				fclose(fp2);
				remove("nomes2");
				if(achou == 1){
					system("cls");
					printf("Excluido com sucesso!");
					getch();
				}
				
			break;
			
			case '4':
				system("cls");
				
				fp = fopen("nomes", "rb");
				if(fp==NULL){
					printf("Arquivo nao existe!");
					exit(1);
				}
				i=0;
				
				while(!feof(fp)){
					fscanf(fp, "%s", nome[i]);
					i++;
				}
				
				fclose(fp);
				
				for(j=0;j<i-1;j++){
					printf("%d- %s\n",j+1, nome[j]);
				}
				getch();
			break;
			
			case '5':
				system("cls");
				int aux=0;
				
				fp = fopen("nomes", "rb");
				if(fp==NULL){
					printf("Arquivo nao existe!");
					exit(1);
				}
				i=0;
				
				while(!feof(fp)){
					fscanf(fp, "%s", nome[i]);
					i++;
				}
				
				fclose(fp);
				
				for(aux=0;aux<i-1;aux++){
					for(j=0;j<(i-1)-aux-1;j++){
						if(strcmp(nome[j],nome[j+1])>0){
							strcpy(pesquisa,nome[j]);
							strcpy(nome[j],nome[j+1]);
							strcpy(nome[j+1],pesquisa);
						}
					}
				}
				
				fp = fopen("nomes", "wb");
				if(fp==NULL){
					printf("Deu ruim");
					exit(1);
				}
				for(j=0;j<i-1;j++){
					fprintf(fp,"%s\n", nome[j]);
				}
				
				printf("Ordenado com sucesso!");
				fclose(fp);
				getch();
				
			break;
			
			case '6':
				sair = 1;
			break;
			
			default:
			break;
		}
		if(sair == 1){
			break;
		}
	}
	
	
	return 0;
}
