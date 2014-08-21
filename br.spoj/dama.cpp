#include <stdio.h>
#include <set>

typedef struct Ponto{
    int x, y;
} Ponto;

using namespace std;

int main()
{
    Ponto A, B;

    while( scanf("%d %d %d %d", &A.x, &A.y, &B.x, &B.y) && A.x > 0 )
    {
        if( A.x == B.x && A.y == B.y )
            printf("%d\n", 0);
        else if( A.x-B.x == A.y-B.y || A.x-B.x == B.y-A.y || A.x == B.x || A.y == B.y )
            printf("%d\n", 1);
        else
            printf("%d\n", 2);
    }

    return 0;
}



