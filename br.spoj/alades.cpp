#include <stdio.h>

using namespace std;

int main()
{
    int H1, M1, H2, M2;
    int T1, T2;

    while( scanf("%d %d %d %d", &H1, &M1, &H2, &M2) )
    {
        if(H1==0 && M1==0 && H2==0 && M2==0)
            break;

        T2 = H2*60 + M2;
        T1 = H1*60 + M1;

        if(T2 < T1) T2 += 24*60;

        printf("%d\n", T2-T1);
    }

    return 0;
}


