#include "stdio.h"
#include "stdlib.h"

long long cont = 0;

typedef struct No{
    int numero;
    struct No *esquerda;
    long long numDireita;
    struct No *direita;
}No;

void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

void inserir(No **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
	(*pRaiz)->numDireita = 0;
    }else{
        if(numero < (*pRaiz)->numero){
		cont+= (*pRaiz)->numDireita + 1;          
		//printf("numero %d\n", numero);
		inserir(&(*pRaiz)->esquerda, numero);	
	}
        if(numero > (*pRaiz)->numero){
	    (*pRaiz)->numDireita++;
            inserir(&(*pRaiz)->direita, numero);
	}
    }
}

int main(){
	int t, n, num;


	scanf("%d%*c%*c", &t);
	for(int i=0; i<t; i++){
		cont = 0;
		No *arvore;
		criarArvore(&arvore);		

		scanf("%d%*c", &n);
		for(int j=0; j<n; j++){
			scanf("%d%*c", &num);
			inserir(&arvore, num);
		}
		scanf("%*c");
		printf("%lld\n", cont);
	}

	return 0;
}




