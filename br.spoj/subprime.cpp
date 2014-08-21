#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int B, N, D, C, V;

    while( scanf("%d %d", &B, &N) && B>0 && N>0)
    {
        vector <int> reservas(B);
        int neg=0;

        for(int i=0; i<B; i++){
            scanf("%d ", &reservas[i]);
        }

        for(int i=0; i<N; i++){
            scanf("%d %d %d", &D, &C, &V);
            reservas[D-1] -= V;
            reservas[C-1] += V;

            if(reservas[D-1] + V >= 0 && reservas[D-1] < 0)
                neg--;
            if(reservas[C-1] - V < 0 && reservas[C-1] >= 0)
                neg++;
        }

        if(neg<0) printf("N\n");
        else printf("S\n");
    }

    return 0;
}


