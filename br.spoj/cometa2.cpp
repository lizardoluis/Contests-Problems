#include <stdio.h>

using namespace std;

int main()
{
    int ano;

    scanf("%d", &ano);

    printf("%d", (1986 + ((ano-1986)/76+1)*76));

    return 0;
}


