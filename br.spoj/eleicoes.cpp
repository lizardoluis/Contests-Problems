#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n, x1, maior=0, votos, pref, eleito;

    scanf("%d", &n);
    map <int, int> urna;
    map <int, int>::iterator it;

    for(int i=0; i<n; i++)
    {
        scanf("%d", &x1);
        urna[x1] = urna[x1]+1;
    }

//    map <int,int>::iterator it2 = urna.end();
//    it2--;
//    int elemento = it2->first;
//    cout<<"\nteste "<< elemento;

    for ( it=urna.begin() ; it != urna.end(); it++ ){
        votos = (*it).second;
        pref = (*it).first;
        if(votos > maior){
            maior = votos;
            eleito = pref;
        }

    }

    printf("%d\n", eleito);

    return 0;
}



