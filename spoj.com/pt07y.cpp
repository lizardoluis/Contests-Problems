#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        enum { BRANCO, CINZA, PRETO };
        int visitaDfs(int u, int tempo, vector <int> & cor, vector <int> & antecessor);

    public:
        Grafo(int NVertices);
        void Insere(int v1, int v2);
        void Imprime();
        bool ListaAdjVazia(int v);
        bool BuscaEmProfundidade();
};

int main()
{
    int V, A, v1, v2;
    scanf("%d %d", &V, &A);

    Grafo grafo(V);

    for(int i=0; i<A; i++){
        scanf("%d %d", &v1, &v2);
        grafo.Insere(v1, v2);
    }

    //grafo.Imprime();
    if(grafo.BuscaEmProfundidade())
        printf("NO");
    else
        printf("YES");

    return 0;
}

Grafo::Grafo(int NVertices)
{
    Graph.resize(NVertices);
}

void Grafo::Insere(int v1, int v2)
{
    Graph[v1-1].push_back(v2-1);
    //Graph[v2-1].push_back(v1-1);
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

bool Grafo::BuscaEmProfundidade()
{
    int tempo=0;
    vector <int> cor(Graph.size(), BRANCO);
    vector <int> antecessor(Graph.size(), -1);

    for(unsigned i=0; i<Graph.size(); i++){
        if(cor[i] == BRANCO){
            tempo = visitaDfs(i, tempo, cor, antecessor);
            if(tempo == -1)
                    return true;
        }
    }

    return false;
}

int Grafo::visitaDfs(int u, int tempo, vector <int> & cor, vector <int> & antecessor)
{
    cor[u] = CINZA;
    //d[u] = ++tempo;

    if( !ListaAdjVazia(u) ){
        for(unsigned i=0; i<Graph[u].size(); i++)
        {
            int v = Graph[u][i];
            if( (cor[v] == CINZA || cor[v] == PRETO) && v){
                return -1;
            }
            else if(cor[v] == BRANCO){
                antecessor[v] = u;
                tempo = visitaDfs(v, tempo, cor, antecessor);
                if(tempo == -1)
                    return -1;
            }
        }
    }
    cor[u] = PRETO;
    //t[u] = ++tempo;
    return tempo;
}


