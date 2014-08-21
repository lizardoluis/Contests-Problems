#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 9
#define TAM_Q 3
#define TRUE 1
#define FALSE 0

void LeMatriz(short int Matriz[TAM][TAM]);
short int VerificaLinhas(short int Matriz[TAM][TAM]);
short int VerificaColunas(short int Matriz[TAM][TAM]);
short int VerificaQuadrados(short int Matriz[TAM][TAM]);

int main()
{
    int N, i, Soma;
    short int Matriz[TAM][TAM];

    scanf("%d", &N);

    for(i=1; i<=N; i++)
    {
        printf("Instancia %d\n", i);

        LeMatriz(Matriz);

        Soma = VerificaLinhas(Matriz);
        Soma += VerificaColunas(Matriz);
        Soma += VerificaQuadrados(Matriz);

        if(Soma == 3)
            printf("SIM\n");
        else
            printf("NAO\n");

        if(i!=N)
            printf("\n");
    }

    return 0;
}

short int VerificaQuadrados(short int Matriz[TAM][TAM])
{
    short int i, j, q, QL, QC;
    char CheckList[TAM];

    for(q=0; q<TAM; q++){
        for(i=0; i<TAM; i++)
            CheckList[i] = '0';

        QL = (q%3)*3;
        QC = floor(q/3)*3;

        for(i=0; i<TAM_Q; i++)
        {
            for(j=0; j<TAM_Q; j++){
                if(CheckList[Matriz[QL+i][QC+j]-1] == '1') return FALSE;
                else CheckList[Matriz[QL+i][QC+j]-1] = '1';
            }
        }
    }

    return TRUE;
}

short int VerificaLinhas(short int Matriz[TAM][TAM])
{
    short int i, Linha;
    char CheckList[TAM];

    for(Linha=0; Linha<TAM; Linha++)
    {
        for(i=0; i<TAM; i++)
            CheckList[i] = '0';

        for(i=0; i<TAM; i++){
            if(CheckList[Matriz[Linha][i]-1] == '1') return FALSE;
            else CheckList[Matriz[Linha][i]-1] = '1';
        }
    }

    return TRUE;
}

short int VerificaColunas(short int Matriz[TAM][TAM])
{
    short int i, Coluna;
    char CheckList[TAM];

    for(Coluna=0; Coluna<TAM; Coluna++)
    {
        for(i=0; i<TAM; i++)
            CheckList[i] = '0';

        for(i=0; i<TAM; i++){
            if(CheckList[Matriz[i][Coluna]-1] == '1') return FALSE;
            else CheckList[Matriz[i][Coluna]-1] = '1';
        }
    }

    return TRUE;
}

void LeMatriz(short int Matriz[TAM][TAM])
{
    short int i, j;

    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            scanf("%hd", &Matriz[i][j]);
        }
    }
}



