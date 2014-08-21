#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iostream>

#define TAM 35

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        vector <int> antecessor;
        enum { BRANCO, CINZA, PRETO };
        int visitaDfs(int u, int tempo, vector <int> & cor, int *cont);
        void visitaBfs(int u, vector <int> & cor, vector <int> & d);

    public:
        Grafo(int NVertices);
        void Insere(int v1, int v2);
        void Imprime();
        bool ListaAdjVazia(int v);
        void BuscaEmProfundidade();
        void BuscaEmLargura(unsigned origem);
        int ImprimeCaminho(int origem, int v);
        Grafo grafoTransposto();
};


int main()
{
    short C, R;
    char Creature1[TAM], Creature2[TAM];
    map <string, int> Map;

    scanf("%hd %hd", &C, &R);

    while(C>0 || R>0){
        Grafo grafo(C);

        for(int i=0; i<C; i++){
            scanf("%s", Creature1);
            Map.insert( pair<string,int>(Creature1, i) );
        }

        for(int i=0; i<R; i++){
            scanf("%s %s", Creature1, Creature2);
            grafo.Insere(Map.find(Creature2)->second, Map.find(Creature1)->second);
        }

        grafo.BuscaEmProfundidade();

        scanf("%hd %hd", &C, &R);
    }

    return 0;
}



Grafo::Grafo(int NVertices)
{
    Graph.resize(NVertices);
    antecessor.resize(NVertices, -1);
}

void Grafo::Insere(int v1, int v2)
{
    Graph[v1].push_back(v2);
    Graph[v2].push_back(v1);
}

void Grafo::Imprime()
{
    for(unsigned i=0; i<Graph.size(); i++){
        printf("\n%d - ", i);
        for(unsigned j=0; j<Graph[i].size(); j++){
            printf("%d ", Graph[i][j]);
        }
    }
}

bool Grafo::ListaAdjVazia(int v)
{
    if(Graph[v].size() == 0)
        return true;
    else return false;
}

void Grafo::BuscaEmProfundidade()
{
    int tempo=0;
    int cont, max=1;
    vector <int> cor(Graph.size(), BRANCO);
    //vector <int> d(Graph.size());
    //vector <int> t(Graph.size());

    for(unsigned i=0; i<Graph.size(); i++){
        if(cor[i] == BRANCO){
            cont = 0;
            tempo = visitaDfs(i, tempo, cor, &cont);
            if(cont>max)
                max=cont;
        }
    }

    printf("%d\n", max);
}

int Grafo::visitaDfs(int u, int tempo, vector <int> & cor, int *cont)
{
    cor[u] = CINZA;
    //d[u] = ++tempo;
    (*cont)++;

    if( !ListaAdjVazia(u) ){
        for(unsigned i=0; i<Graph[u].size(); i++)
        {
            int v = Graph[u][i];
            if(cor[v] == BRANCO){
                antecessor[v] = u;
                tempo = visitaDfs(v, tempo, cor, cont);
            }
        }
    }
    cor[u] = PRETO;
    //t[u] = ++tempo;
    return tempo;
}

void Grafo::BuscaEmLargura(unsigned origem)
{
    vector <int> cor(Graph.size(), BRANCO);
    vector <int> d(Graph.size(), INT_MAX);

    //Visita ponto de partida
    if(cor[origem] == BRANCO){
        visitaBfs(origem, cor, d);
    }

    /*for(unsigned i=0; i<Graph.size(); i++){
        if( i != origem && cor[i] == BRANCO ){
            visitaBfs(i, cor, d);
        }
    }*/
}

void Grafo::visitaBfs(int u, vector <int> & cor, vector <int> & d)
{
    cor[u] = CINZA;
    d[u] = 0;
    queue <int> fila;

    fila.push(u);

    while(!fila.empty()){
        u = fila.front();
        fila.pop();

        if( !ListaAdjVazia(u) ){
            for(unsigned i=0; i<Graph[u].size(); i++)
            {
                int v = Graph[u][i];
                if(cor[v] == BRANCO){
                    cor[v] = CINZA;
                    d[v] = d[u]+1;
                    antecessor[v] = u;
                    fila.push(v);
                }
            }
        }
        cor[u] = PRETO;
    }
}

/*int Grafo::ImprimeCaminho(int origem, int v)
{
    int hop=0;

    if(origem == v){
        //printf("%d ", origem);
        hop++;
    }
    else if(antecessor[v] == -1)
        return INT_MAX;
    else{
        hop += ImprimeCaminho(origem, antecessor[v]);
        //printf("%d ", v);
        hop++;
    }
    return hop;
}*/

int Grafo::ImprimeCaminho(int origem, int v){
    if(origem == v){
        printf("%d ", origem);
    }
    else if(antecessor[v] == -1)
        printf("\nNao existe caminhdo de %d ate %d ", origem, v);
    else{
        ImprimeCaminho(origem, antecessor[v]);
        printf("%d ", v);
    }
    return 1;
}

Grafo Grafo::grafoTransposto()
{
    Grafo grafoT( Graph.size() );

    for(unsigned v=0; v<Graph.size(); v++){
        if( !ListaAdjVazia(v) ){
            for(unsigned i=0; i<Graph[v].size(); i++)
                grafoT.Insere(Graph[v][i], v);
        }
    }

    return grafoT;
}




