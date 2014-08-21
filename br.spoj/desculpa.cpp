#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <queue>

#define ENTRADA 3
#define CRISTAL 2
#define NORMAL 1
#define SAIDA 0

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        vector <int> antecessor;
        enum { BRANCO, CINZA, PRETO };
        int visitaDfs(int u, int tempo, vector <int> & cor);
        void visitaBfs(int u, vector <int> & cor, vector <int> & d);

    public:
        Grafo(int NVertices);
        void Insere(int v1, int v2);
        void Imprime();
        bool ListaAdjVazia(int v);
        void BuscaEmProfundidade();
        void BuscaEmLargura(unsigned origem);
        int ImprimeCaminho(int origem, int v);
};


int main()
{
    short N, M;
    unsigned v=0, P0, MHop=INT_MAX;
    vector <int> PF;

    scanf("%hd %hd", &N, &M);

    Grafo grafo(M*N);
    short Matriz[N][M];

    /**Le a Matriz**/
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%hd", &Matriz[i][j]);
        }
    }

    /**Insere no Grafo**/
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){

            if(Matriz[i][j] != CRISTAL){

                if(Matriz[i][j] == ENTRADA)
                    P0 = v;
                else if(Matriz[i][j] == SAIDA)
                    PF.push_back(v);

                if( j<M-1 && Matriz[i][j+1] != CRISTAL ){
                    grafo.Insere(v, v+1);
                }

                if( i<N-1 && Matriz[i+1][j] != CRISTAL ){
                    grafo.Insere(v, v+M);
                }
            }
            v++;
        }
    }

    grafo.BuscaEmLargura(P0);

    for(unsigned i=0; i<PF.size(); i++){
        unsigned aux = grafo.ImprimeCaminho(P0, PF[i]);
        //printf("\n");
        if(aux < MHop)
            MHop = aux;
    }

    printf("%d\n", MHop-1);

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
    vector <int> cor(Graph.size(), BRANCO);
    //vector <int> d(Graph.size());
    //vector <int> t(Graph.size());

    for(unsigned i=0; i<Graph.size(); i++){
        if(cor[i] == BRANCO){
            tempo = visitaDfs(i, tempo, cor);
        }
    }
}

int Grafo::visitaDfs(int u, int tempo, vector <int> & cor)
{
    cor[u] = CINZA;
    //d[u] = ++tempo;

    if( !ListaAdjVazia(u) ){
        for(unsigned i=0; i<Graph[u].size(); i++)
        {
            int v = Graph[u][i];
            if(cor[v] == BRANCO){
                antecessor[v] = u;
                tempo = visitaDfs(v, tempo, cor);
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

/*int Grafo::ImprimeCaminho(int origem, int v){
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
}*/



