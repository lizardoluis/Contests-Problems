#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long T, N;
    char c;

    scanf("%lld", &T);

    for(int t=0; t<T; t++)
    {
        long long K=0, fat=1;

        scanf("%lld", &N);

        while(scanf("%c", &c) && c=='!'){
            K++;
        }

        int i=0;
        while(N-i*K >= 1){
            fat *= N-i*K;
            i++;
        }

        printf("%lld\n", fat);

    }


    return 0;
}



