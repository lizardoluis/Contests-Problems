#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define PI 3.14159265358979323846264338327950

bool Pedacos(double Area, int F, vector<double> & Tortas);

int main()
{
    int T, N, F;
    scanf("%d", &T);

    for(int k=0; k<T; k++)
    {
        int R;
        double Soma = 0;

        scanf("%d %d", &N, &F);
        F += 1;

        vector<double> Tortas(N);

        for(int j=0; j<N; j++)
        {
            scanf("%d", &R);
            Tortas[j] = PI*R*R;
            Soma += PI*R*R;
        }

        double esq = 0;
        double dir = Soma/F;
        double valor;

        do{
            valor = (esq+dir)/2;
            if(Pedacos(valor, F, Tortas))
                esq = (esq+dir)/2+0.00001;
            else
                dir = (esq+dir)/2-0.00001;
        }while(dir-esq >= 0.00001);

        printf("%.4f\n", valor);
    }

    return 0;
}

bool Pedacos(double Area, int F, vector<double> & Tortas)
{
    int NPedacos=0;

    for(unsigned i=0; i<Tortas.size(); i++){
        NPedacos += floor(Tortas[i]/Area);
    }

    if(NPedacos < F) return false;
    else return true;
}


