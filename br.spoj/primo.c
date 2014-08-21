#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int ePrimo(unsigned long n);

int main()
{
    unsigned long N;

    scanf("%ld", &N);

    if(ePrimo(abs(N)))
        printf("sim");
    else
        printf("nao");

    return 0;
}

int ePrimo(unsigned long n)
{
    int i;

    if(n == 2)
        return TRUE;
    else{
        if(n==1 || n%2 == 0)
            return FALSE;
        else{
            for(i=3; i<=sqrt(n); i+=2){
                if(n%i == 0)
                    return FALSE;
            }
        }
    }
    return TRUE;
}





