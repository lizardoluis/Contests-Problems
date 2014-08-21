#include <stdio.h>
#include <stdlib.h>

#define SEARCH_NUMBER 42

int main(int argc, char *argv[])
{
    int Number;

    while( scanf("%d", &Number) )
    {
        if(Number == SEARCH_NUMBER)
            break;
        printf("%d\n", Number);
    }

    return 0;
}


