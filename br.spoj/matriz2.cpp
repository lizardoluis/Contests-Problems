#include <stdio.h>

using namespace std;

int main()
{
    int D, P, Q, R, S, X, Y, I, J;
    long long result=0;

    scanf("%d %d %d %d %d %d %d %d %d", &D, &P, &Q, &R, &S, &X, &Y, &I, &J);

    for(int k=1; k<=D; k++){
        result += ((P*I + Q*k)%X) * ((R*k + S*J)%Y);
    }

    printf("%lld\n", result);

    return 0;
}


