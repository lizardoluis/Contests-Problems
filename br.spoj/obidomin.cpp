#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <vector>

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
        int visitaDfs(int u, int tempo, vector <int> & cor);

    public:
        Grafo(int NVertices);
        int getVLast(){return vlast;};
        void Insere(int v1, int v2);
        void Imprime();
        bool ListaAdjVazia(int v);
        int ImprimeCaminho(int origem, int v);
        bool BuscaEmProfundidade();
};


int main()
{
    int NPecas, P1, P2, teste=1;

    scanf("%d", &NPecas);

    while(NPecas > 0)
    {
        int Impares=0, Bu=0;
        vector <int> Pecas(7, 0);
        vector <int> Buchas(7, 0);
        Grafo grafo(7);

        for(int i=0; i<NPecas; i++){
            scanf("%d %d", &P1, &P2);
            grafo.Insere(P1, P2);

            if(P1 != P2){
                Pecas[P1]++;
                Pecas[P2]++;
            }
        }

        for(int i=0; i<=6; i++){
            if(Pecas[i]%2 != 0){
                Impares++;
            }
        }

        if(teste>1)
            printf("\n");

        if( (Impares == 2 || Impares == 0) && Bu==0 && grafo.BuscaEmProfundidade())
            printf("Teste %d\nsim\n", teste++);
        else
            printf("Teste %d\nnao\n", teste++);

        scanf("%d", &NPecas);
    }


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

bool Grafo::BuscaEmProfundidade()
{
    int tempo=0;
    vector <int> cor(Graph.size(), BRANCO);
    antecessor.resize(Graph.size(), -1);
    d.resize(Graph.size(), -1);
    t.resize(Graph.size(), -1);

    unsigned i;
    for(i=0; i<Graph.size(); i++)
        if(Graph[i].size() > 0)
            break;

    if(cor[i] == BRANCO)
        tempo = visitaDfs(i, tempo, cor);

    for(unsigned i=0; i<Graph.size(); i++){
        if(Graph[i].size() > 0 && cor[i] == BRANCO)
            return false;
    }

    return true;
}

int Grafo::visitaDfs(int u, int tempo, vector <int> & cor)
{
    cor[u] = CINZA;
    d[u] = ++tempo;

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
    t[u] = ++tempo;
    return tempo;
}



