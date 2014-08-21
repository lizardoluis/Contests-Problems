#include <stdio.h>

using namespace std;

int main()
{
    int valor, t=1;

    while( scanf("%d", &valor) && valor>0)
    {
        int B50=0, B10=0, B05=0, B01=0;

        if( valor/50 > 0 ){
            B50 += valor/50;
            valor %= 50;
        }

        if( valor/10 > 0 ){
            B10 += valor/10;
            valor %= 10;
        }

        if( valor/05 > 0 ){
            B05 += valor/05;
            valor %= 05;
        }

        B01 += valor;

        printf("Teste %d\n%d %d %d %d\n\n", t++, B50, B10, B05, B01);
    }


    return 0;
}



