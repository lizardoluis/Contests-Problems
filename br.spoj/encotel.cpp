#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCARACTERES 30

char LetraParaNumero(char ch);

int main()
{
    unsigned short i;
    char Expressao[NUMCARACTERES];

    while(scanf("%s", Expressao) > 0)
    {
        for(i=0; i<strlen(Expressao); i++){
            if(Expressao[i] != '0' || Expressao[i] != '1' || Expressao[i] != '-')
                printf("%c", LetraParaNumero(Expressao[i]));
        }
        printf("\n");
    }

    return 0;
}

char LetraParaNumero(char ch)
{
    switch(ch)
    {
        case 'A': return '2';
        case 'B': return '2';
        case 'C': return '2';

        case 'D': return '3';
        case 'E': return '3';
        case 'F': return '3';

        case 'G': return '4';
        case 'H': return '4';
        case 'I': return '4';

        case 'J': return '5';
        case 'K': return '5';
        case 'L': return '5';

        case 'M': return '6';
        case 'N': return '6';
        case 'O': return '6';

        case 'P': return '7';
        case 'Q': return '7';
        case 'R': return '7';
        case 'S': return '7';

        case 'T': return '8';
        case 'U': return '8';
        case 'V': return '8';

        case 'W': return '9';
        case 'X': return '9';
        case 'Y': return '9';
        case 'Z': return '9';

        default: return ch;
    }
}


