#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f91(int n);

int main()
{
    int N;

    scanf("%d", &N);
    while(N>0){
        printf("f91(%d) = %d\n", N, f91(N));
        scanf("%d", &N);
    }
    return 0;
}

int f91(int n)
{
    if ( n<=100 ) return f91(f91(n+11));
    else return n - 10;
}


