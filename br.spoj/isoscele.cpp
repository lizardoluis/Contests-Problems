#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

typedef struct Ponto{
    int x, y;
} Ponto;

double calcdistancia(Ponto a, Ponto b);

using namespace std;

int main()
{
    int n;

    while( scanf("%d", &n) && n>0 )
    {
        int cont=0;
        Ponto ponto[n];
        vector <double> distancias(n-1);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &ponto[i].x, &ponto[i].y);
        }

        for(int i=0; i<n; i++)
        {
            int k=0;
            for(int j=0; j<n; j++){
                if(i!=j) distancias[k++] = calcdistancia(ponto[i], ponto[j]);
            }

            sort( distancias.begin(), distancias.begin()+(n-1) );

            /*for(int j=0; j<n-1; j++){
                printf("%.2f ", distancias[j]);
            }
            printf("\n");*/

            int c=1;
            for(int j=1; j<n-1; j++){
                if( distancias[j] == distancias[j-1] )
                    c++;
                else{
                    cont += c*(c-1)/2;
                    c=1;
                }
            }
            cont += c*(c-1)/2;
        }

        printf("%d\n", cont);
    }

    return 0;
}

double calcdistancia(Ponto a, Ponto b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}


