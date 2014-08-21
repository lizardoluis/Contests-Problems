#include <stdlib.h>
#include <stdio.h>

#define MAX 1000

void leMatriz(int Matriz[MAX][MAX], int M, int N);
void leDesloc(int *X, int *Y);
void Deslocar(int Matriz[MAX][MAX], int M, int N, int X, int Y);

int main()
{
    int M, N, Test=1;
    int Matriz[MAX][MAX];

    scanf("%d %d", &M, &N);

    while(M>0 || N>0)
    {
        int X=0, Y=0;

        if(Test==1)
            printf("Teste %d\n",Test++);
        else
            printf("\nTeste %d\n",Test++);

        leMatriz(Matriz, M, N);
        leDesloc(&X, &Y);
        Deslocar(Matriz, M, N, X, Y);

        scanf("%d %d", &M, &N);
    }

    return 0;
}

void Deslocar(int Matriz[MAX][MAX], int M, int N, int X, int Y)
{
    int i, j;

    X*=-1;

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%d ", Matriz[(i+(M+(Y%M))%M)%M][(j+(N+(X%N))%N)%N]);
        }
        printf("\n");
    }
}

void leDesloc(int *X, int *Y)
{
    int x, y;
    do{
        scanf("%d %d", &x, &y);
        *X += x;
        *Y += y;
    } while (x != 0 || y != 0);
}

void leMatriz(int Matriz[MAX][MAX], int M, int N)
{
    int i,j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d", &Matriz[i][j]);
        }
    }
}


