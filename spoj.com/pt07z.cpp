#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

#define TAM 35

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        vector <int> antecessor;
        vector <int> d;
        vector <int> t;
        int vlast;
        int distMax;
        enum { BRANCO, CINZA, PRETO };
        int visitaDfs(int u, int tempo, vector <int> & cor, int Dist);

    public:
        Grafo(int NVertices);
        int getVLast(){return vlast;};
        void Insere(int v1, int v2);
        void Imprime();
        bool ListaAdjVazia(int v);
        int ImprimeCaminho(int origem, int v);
        void BuscaEmProfundidade(unsigned v);
};


int main()
{
    short N, u, v;
    int Origem;

    scanf("%hd", &N);
    Grafo grafo(N);

    for(short i=0; i<N-1; i++){
        scanf("%hd %hd", &u, &v);
        grafo.Insere(u-1, v-1);
    }

    //grafo.Imprime();
    grafo.BuscaEmProfundidade(0);
    //printf("\nVLast: %d", grafo.getVLast()+1);
    Origem = grafo.getVLast();

    grafo.BuscaEmProfundidade(grafo.getVLast());
    //printf("\nVLast: %d", grafo.getVLast()+1);

    printf("%d", grafo.ImprimeCaminho(Origem, grafo.getVLast())-1);


    return 0;
}

Grafo::Grafo(int NVertices)
{
    Graph.resize(NVertices);
}

void Grafo::Insere(int v1, int v2)
{
    Graph[v1].push_back(v2);
    Graph[v2].push_back(v1);
}

void Grafo::Imprime()
{
    for(unsigned i=0; i<Graph.size(); i++){
        printf("\n%d - ", i+1);
        for(unsigned j=0; j<Graph[i].size(); j++){
            printf("%d ", Graph[i][j]+1);
        }
    }
}

bool Grafo::ListaAdjVazia(int v)
{
    if(Graph[v].size() == 0)
        return true;
    else return false;
}


int Grafo::ImprimeCaminho(int origem, int v)
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
}

void Grafo::BuscaEmProfundidade(unsigned v)
{
    int tempo=0;
    vector <int> cor(Graph.size(), BRANCO);
    antecessor.resize(Graph.size(), -1);
    d.resize(Graph.size(), -1);
    t.resize(Graph.size(), -1);
    vlast = -1;
    distMax=0;

    if(cor[v] == BRANCO)
            tempo = visitaDfs(v, tempo, cor, 1);

    for(unsigned u=0; u<Graph.size(); u++)
        if(cor[u] == BRANCO && u!=v)
            tempo = visitaDfs(u, tempo, cor, 1);
}

int Grafo::visitaDfs(int u, int tempo, vector <int> & cor, int dist)
{
    cor[u] = CINZA;
    d[u] = ++tempo;

    if( !ListaAdjVazia(u) ){
        for(unsigned i=0; i<Graph[u].size(); i++)
        {
            int v = Graph[u][i];
            if(cor[v] == BRANCO){
                antecessor[v] = u;
                tempo = visitaDfs(v, tempo, cor, dist+1);
            }
        }
    }

    if(dist >= distMax){
        distMax = dist;
        vlast = u;
    }

    cor[u] = PRETO;
    t[u] = ++tempo;
    return tempo;
}


