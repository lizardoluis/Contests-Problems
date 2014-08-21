#include <stdio.h>

using namespace std;

int main()
{
    int n, varetas;

    while( scanf("%d", &n) && n>0 )
    {
        int retangulos=0, meioret=0;

        for(int i=0; i<n; i++)
        {
            scanf("%*d %d", &varetas);
            retangulos += varetas/4;
            varetas %= 4;
            //printf("teste %d\n", varetas%4);
            meioret += varetas/2;
        }
        retangulos += meioret/2;
        printf("%d\n", retangulos);
    }

    return 0;
}


