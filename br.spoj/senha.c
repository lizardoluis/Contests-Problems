#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_A 10
#define TAM_S 6
#define UNDEFINED -1

void LeEntrada(int N, short int Associacao[][TAM_A], char Codigo[][TAM_S]);
void getDigits(char Letra, short int *Digit1, short int *Digit2, short int *Associacao);
int Compare(int A, int B, int C, int D);
int SearchDigit(short int Pos, short int Associacao[][TAM_A], char Codigo[][TAM_S]);

int main()
{
    short int N, i, Test=1;
    scanf("%hd", &N);

    printf("Teste %hd\n", Test++);

    while(N != 0)
    {
        short int Associacao[N][TAM_A];
        char Codigo[N][TAM_S];

        LeEntrada(N, Associacao, Codigo);

        for(i=0; i<TAM_S; i++)
            printf("%hd ", SearchDigit(i, Associacao, Codigo));

        scanf("%hd", &N);
        if(N!=0)
            printf("\n\nTeste %hd\n", Test++);
    }
    printf("\n");

    return 0;
}

int SearchDigit(short int Pos, short int Associacao[][TAM_A], char Codigo[][TAM_S])
{
    short int D1, D2, D3, D4, R, i=0;

    do{
        getDigits(Codigo[i][Pos], &D1, &D2, Associacao[i]);
        getDigits(Codigo[i+1][Pos], &D3, &D4, Associacao[i+1]);
        i++;
        R = Compare(D1, D2, D3, D4);
    }while( R == UNDEFINED );

    return R;
}

/** Return -1, if it's impossible to decide **/
int Compare(int A, int B, int C, int D)
{
    if( (A==C && B==D) || (A==D && B==C)  ) return UNDEFINED;
    else if( A==C || A==D ) return A;
    else return B;
}

void getDigits(char Letra, short int *Digit1, short int *Digit2, short int *Associacao)
{
    switch(Letra)
    {
        case 'A':
            *Digit1 = Associacao[0];
            *Digit2 = Associacao[1];
            break;
        case 'B':
            *Digit1 = Associacao[2];
            *Digit2 = Associacao[3];
            break;
        case 'C':
            *Digit1 = Associacao[4];
            *Digit2 = Associacao[5];
            break;
        case 'D':
            *Digit1 = Associacao[6];
            *Digit2 = Associacao[7];
            break;
        case 'E':
            *Digit1 = Associacao[8];
            *Digit2 = Associacao[9];
            break;
    }
}

void LeEntrada(int N, short int Associacao[][TAM_A], char Codigo[][TAM_S])
{
    int i, j;

    for(i=0; i<N; i++){
        for(j=0; j<TAM_A; j++){
            scanf("%hd", &Associacao[i][j]);
        }
        for(j=0; j<TAM_S; j++){
            scanf("%*c%c", &Codigo[i][j]);
        }
    }
}



