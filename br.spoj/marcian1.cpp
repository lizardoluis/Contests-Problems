#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int L, A, P, R;
    double dbase, dbox;

    scanf("%d %d %d %d", &L, &A, &P, &R);

    dbase = sqrt(L*L/4 + A*A/4);
    dbox = sqrt(dbase*dbase + P*P/4);

    if(dbox<=R)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}



