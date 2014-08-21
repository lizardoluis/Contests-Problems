#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define CRIVO_MAX 1000000

void InicializaCrivo(char *Crivo);
void GeraCrivo(char *Crivo);

int main()
{
    int Num, Cont, j=0;
    char Crivo[CRIVO_MAX];
    int Primos[CRIVO_MAX/4];

    InicializaCrivo(Crivo);
    GeraCrivo(Crivo);

    for(int i=0; i<CRIVO_MAX; i++){
        if(Crivo[i] == '1'){
            Primos[j++] = i*2+1;
        }
    }
    Primos[0] = 2;

    /*for(int i=0; i<CRIVO_MAX/4; i++){
        printf("%d ", Primos[i]);
    }*/

    scanf("%d", &Num);

    while(Num>0)
    {
        Cont = 0;
        j=0;
        while(Primos[j]<=Num)
        {
            if( Num%Primos[j++] == 0 ){
                //printf("Fator: %d\n", Primos[j-1]);
                Cont++;
            }
        }

        printf("%d : %d\n", Num, Cont);

        scanf("%d", &Num);
    }

    return 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------


void InicializaCrivo(char *Crivo)
{
    int i;
    for(i=0; i<(CRIVO_MAX-1)/2+1; i++)
        Crivo[i] = '1';
}

void GeraCrivo(char *Crivo)
{
    int p=3, t;

    while (p*p <= CRIVO_MAX)
    {
        if( Crivo[ (p-1)/2 ] == '1' )
        {
            t = p*p;
            while( t <= CRIVO_MAX )
            {
                Crivo[ (t-1)/2 ] = '0';
                t += 2*p;
            }
        }
        p += 2;
    }
}


