#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <math.h>

#define TAM 7

using namespace std;

void leMatriz(vector < vector <int> > & Matriz, int n);
void imprimeMatriz(vector < vector <int> > & Matriz, vector <int> & Shift, int n);
void imprimeShift(vector <int> & Shift, int n);
int maiorColuna(vector < vector <int> > & Matriz, vector <int> & Shift, int n);
void toShift(vector <int> & Shift, int n);

int main()
{
    int n;
    vector < vector <int> > Matriz (TAM, vector<int>(TAM));
    vector <int> Shift(TAM);

    scanf("%d", &n);
    while(n != -1)
    {
        int menor=INT_MAX;
        int soma;

        leMatriz(Matriz, n);
        Shift.assign(TAM, 0);

        for(int i=1; i<=pow(n, n-1); i++){
            soma = maiorColuna(Matriz, Shift, n);

            if(soma < menor)
                menor = soma;

            toShift(Shift, n);
        }

        printf("%d\n", menor);

        //imprimeMatriz(Matriz, Shift, n);
        //imprimeShift(Shift, n);
        //printf("Maior: %d", maiorColuna(Matriz, Shift, n));

        scanf("%d", &n);
    }

    return 0;
}

void leMatriz(vector < vector <int> > & Matriz, int n)
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            scanf("%d", &Matriz[i][j]);
    }
}

void imprimeMatriz(vector < vector <int> > & Matriz, vector <int> & Shift, int n)
{
    printf("\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ", Matriz[i][ (j+Shift[i])%n ]);
        printf("\n");
    }
    printf("\n");
}

void imprimeShift(vector <int> & Shift, int n)
{
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d ", Shift[i]);
    }
    printf("\n");
}

int maiorColuna(vector < vector <int> > & Matriz, vector <int> & Shift, int n)
{
    int maior=0, soma=0;

    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++){
            soma += Matriz[i][ (j+Shift[i])%n ];
        }
        if(soma > maior) maior = soma;
        soma=0;
    }
    return maior;
}

void toShift(vector <int> & Shift, int n)
{
    for(int i=n-1; i>0; i--)
    {
        if(i == n-1){
            Shift[i]++;
        }
        else if(Shift[i+1] == n){
            Shift[i+1] = 0;
            Shift[i]++;
        }
    }
    if(Shift[1] == n)
        Shift[1] = 0;
}


