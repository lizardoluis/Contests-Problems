#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define MAX_CRIVO 10000001
//#define MAX_CRIVO 100
#define MAX (int)(MAX_CRIVO-3)/2


void GeraCrivo(vector< int > & Crivo);
int BuscaBinaria(vector< int > & Crivo, int Num);

int main()
{
    int T, N, U, L;
    vector<int> Crivo(MAX_CRIVO);
    GeraCrivo(Crivo);
    scanf("%d", &T);

    /*for(unsigned i=0; i<Crivo.size(); i++)
        cout<<Crivo[i]<<"-"<<i<<"  ";
    cout<<"\n\n";*/

    for(int i=0; i<T; i++){
        scanf("%d", &N);
        U = BuscaBinaria(Crivo, N);
        L = BuscaBinaria(Crivo, N/2);
        //printf("U: %d ", U);
        //printf("L: %d\n", L);
        printf("%d\n", U-L);
    }


    return 0;
}

void GeraCrivo(vector< int > & Crivo)
{
    bitset<MAX+1> bset;
    int i,j;

    for(i=0;i*i<=MAX_CRIVO;i++)                                           //we only have to get primes up to sqrt(SIZE)
        if(!bset.test(i))
            for(j=i+1;(2*j+1)*(2*i+3)<=MAX_CRIVO;j++)
                bset.set(((2*j+1)*(2*i+3)-3)/2);
                                  //setting all non-primes
    Crivo[0]=2;                                                     //store the first prime (that is 2)
    for(i=1,j=0;j<MAX+1;j++)
       if(!bset.test(j))
            Crivo[i++]=2*j+3;

    Crivo.resize(i);
}

int BuscaBinaria(vector< int > & Crivo, int Num)
{
    if(Num == 0) return 0;
    int esq = 0, dir = Crivo.size(), i;
    do{
        i = (esq+dir)/2;
        if(Num > Crivo[i]) esq = i+1;
        else dir = i-1;
    }while(Crivo[i]!=Num && esq<=dir);

    if(Crivo[i] > Num) return --i;
    else return i;
}


