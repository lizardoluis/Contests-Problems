#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUMLETRAS 20
#define MAIORPALAVRA 1040

int main()
{
    char Palavra[NUMLETRAS];
    int Soma, i, Crivo[MAIORPALAVRA];
    int p=3, t;

    for(i=0; i<(MAIORPALAVRA-1)/2+1; i++)
      Crivo[i] = 1;

    while (p*p <= MAIORPALAVRA)
    {
        if( Crivo[ (p-1)/2 ] == 1 )
        {
            t = p*p;
            while( t <= MAIORPALAVRA )
            {
                Crivo[ (t-1)/2 ] = 0;
                t += 2*p;
            }
        }
        p += 2;
    }

    while(scanf("%s", Palavra) > 0){
        Soma = 0;
        for(i=0; i<strlen(Palavra); i++){
            if(Palavra[i] >= 97)
                Soma += (int)Palavra[i]-96;
            else
                Soma += (int)Palavra[i]-38;
        }
        if(Soma == 1 || Soma == 2 || (Soma%2 != 0 && Crivo[(Soma-1)/2] == 1))
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}






