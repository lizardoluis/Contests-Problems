#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



typedef struct Dados{
        int jogos;
        int sets;
        int pontos;
}Dados;

bool mycmp (pair<string, Dados> A, pair<string, Dados> B);


int main()
{
    char tmp;
    int T, M, a, b;
    Dados Vazio = {0, 0, 0};

    while(scanf("%d%*c", &T) && T>0)
    {
        string timeA, timeB;

        map <string, Dados> mymap;
        map <string, Dados>::iterator it;


        for(int i=0; i<T; i++){
            char aux[21];
            scanf("%[^\n]%*c", aux);
            mymap[aux] = Vazio;
        }

        scanf("%d%*c", &M);

        for(int i=0; i<M; i++)
        {
            int vitoria =0;
            Dados A, B;

            getline(cin, timeA, '-');
            getline(cin, timeB, ':');

            map <string, Dados>::iterator itA;
            map <string, Dados>::iterator itB;

            itA = mymap.find(timeA);
            itB = mymap.find(timeB);

            A = (*itA).second;
            B = (*itB).second;

            while(scanf(" %d-%d%c", &a, &b, &tmp) ){
                if(a-b > 0){
                    A.sets++;
                    B.sets--;
                    vitoria++;
                }
                else{
                    B.sets++;
                    A.sets--;
                    vitoria--;
                }

                A.pontos += a;
                B.pontos += b;

                if(tmp == '\n')
                    break;

            }
            if(vitoria > 0)
                A.jogos++;
            else
                B.jogos++;

            mymap[timeA] = A;
            mymap[timeB] = B;
        }

        vector < pair<string, Dados> > vetor;

        for ( it=mymap.begin() ; it != mymap.end(); it++ ){
            vetor.push_back( make_pair( (*it).first, (*it).second ) );
        }

        sort(vetor.begin(), vetor.end(), mycmp);

        for ( int i=0; i<T; i++ ){
            printf("%-20s%5d%5d%10d\n", vetor[i].first.c_str(), vetor[i].second.jogos, vetor[i].second.sets, vetor[i].second.pontos);
        }
        printf("\n");
    }

    return 0;
}

bool mycmp (pair<string, Dados> A, pair<string, Dados> B)
{
    if(A.second.jogos != B.second.jogos)
        return (A.second.jogos > B.second.jogos);

    else if(A.second.sets != B.second.sets)
        return (A.second.sets > B.second.sets);

    else if(A.second.pontos != B.second.pontos)
        return (A.second.pontos > B.second.pontos);

    else
        return A.first < B.first;
}



