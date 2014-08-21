#include <stdio.h>
#include <math.h>
#include <limits.h>

using namespace std;

typedef struct Ponto{
    int x, y;
} Ponto;

double distance(Ponto a, Ponto b);

int main()
{
    int n, k=1;
    double dist;

    while(scanf("%d", &n) && n>0)
    {
        Ponto ponto[n];
        double menor=INT_MAX/2;

        for(int i=0; i<n; i++){
            scanf("%d %d", &ponto[i].x, &ponto[i].y);
        }

        for(int i=0; i<n; i++)
        {
            double maior=0;

            for(int j=0; j<n; j++){
                dist = distance(ponto[i], ponto[j]);
                if(dist > maior) maior = dist;
            }
            //printf("Teste %f\n", maior);
            if(maior < menor) menor = maior;
        }

        printf("Teste %d\n%d\n\n", k++, (int)ceil(menor*2+5));
    }

    return 0;
}

double distance(Ponto a, Ponto b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}



