#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1002

int Rumo9s(char *N);

int main()
{
    char Numero[TAM];
    int aux;

    scanf("%s", Numero);

    while(strcmp(Numero, "0") != 0){
        printf("%s", Numero);

        aux = Rumo9s(Numero);
        if(aux > 0)
            printf(" is a multiple of 9 and has 9-degree %d.\n", aux);
        else
            printf(" is not a multiple of 9.\n");

        scanf("%s", Numero);
    }

    return 0;
}

int Rumo9s(char *N)
{
    int Soma=0, i, aux;

    for(i=0; i<strlen(N); i++){
        Soma += (int)N[i]-48;
    }

    if(Soma == 9)
        return 1;
    else
    {
        if(Soma > 9)
        {
            sprintf(N, "%d", Soma);
            aux = Rumo9s(N);
            if(aux > 0)
                return 1 + aux;
        }
    }
    return -1;
}


