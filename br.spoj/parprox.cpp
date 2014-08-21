#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <limits.h>

typedef struct Ponto{
    int x, y;
} Ponto;

double calcdistancia(Ponto a, Ponto b);

using namespace std;

int main()
{
    int n;
    double menor=INT_MAX, dist;

    scanf("%d", &n);

    Ponto ponto[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &ponto[i].x, &ponto[i].y);

        for(int j=i-1; j>=0; j--){
            dist = calcdistancia(ponto[i], ponto[j]);
            if( dist < menor )
                menor = dist;
        }
    }

    printf("%.3f\n", menor);

    return 0;
}

double calcdistancia(Ponto a, Ponto b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}


