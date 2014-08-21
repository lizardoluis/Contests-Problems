#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        vector <int> antecessor;
        vector <int> color;
        enum { BRANCO, CINZA, PRETO };
        bool visitaBfs(int u, vector <int> & cor, int color);

    public:
        Grafo(int NVertices);
        void Insere(int v1, int v2);
        bool ListaAdjVazia(int v);
        char *GRAPHtwocolor();
        char *BuscaEmLargura();
};

int main()
{
    int N, M, u, v, k=1, i;

    ios::sync_with_stdio(false);

    while(true)
    {
        cin >> N >> M;
		if(!cin)
            break;

        Grafo grafo(N);
        for(i=0; i<M; i++){
            cin >> u >> v;
            grafo.Insere(u-1, v-1);
        }
        cout << "Instancia " << k++ << "\n"<< grafo.BuscaEmLargura() <<"\n\n";
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

bool Grafo::ListaAdjVazia(int v)
{
    if(Graph[v].size() == 0)
        return true;
    else return false;
}

char* Grafo::BuscaEmLargura()
{
    vector <int> cor(Graph.size(), 0);

    for(unsigned i=0; i<Graph.size(); i++){
        if(cor[i] == 0 ){
            if(visitaBfs(i, cor, 1) == false)
                return "nao";
        }
    }
    return "sim";
}

bool Grafo::visitaBfs(int u, vector <int> & cor, int color)
{
    cor[u] = color;
    queue <int> fila;
    unsigned i;
    int v;

    fila.push(u);

    while(!fila.empty()){
        u = fila.front();
        fila.pop();

        for(i=0; i<Graph[u].size(); i++)
        {
            v = Graph[u][i];
            if(cor[v] == 0){
                cor[v] = cor[u]*(-1);
                fila.push(v);
            }
            else if(cor[v] == cor[u])
                return false;
        }
    }
    return true;
}




/*#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Grafo{
    private:
        vector < vector<int> > Graph;
        vector <int> antecessor;
        vector <int> color;
        enum { BRANCO, CINZA, PRETO };
        bool visitaBfs(int u, vector <int> & cor, int color);

    public:
        Grafo(int NVertices);
        void Insere(int v1, int v2);
        bool ListaAdjVazia(int v);
        char *GRAPHtwocolor();
        char *BuscaEmLargura();
};

int main()
{
    int N, M, u, v, k=1, i;

    ios::sync_with_stdio(false);

    while(true)
    {
        cin >> N >> M;
		if(!cin)
            break;

        Grafo grafo(N);
        for(i=0; i<M; i++){
            cin >> u >> v;
            grafo.Insere(u-1, v-1);
        }
        cout << "Instancia " << k++ << "\n"<< grafo.BuscaEmLargura() <<"\n\n";
        //printf("Instancia %d\n%s\n\n", k++, grafo.BuscaEmLargura());
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

bool Grafo::ListaAdjVazia(int v)
{
    if(Graph[v].size() == 0)
        return true;
    else return false;
}

char* Grafo::BuscaEmLargura()
{
    vector <int> cor(Graph.size());

    for(unsigned i=0; i<Graph.size(); i++){
        if(cor[i] == 1 || cor[i] == -1 ){
            if(visitaBfs(i, cor, 1) == false)
                return "nao";
        }
    }
    return "sim";
}

bool Grafo::visitaBfs(int u, vector <int> & cor, int color)
{
    cor[u] = color;
    queue <int> fila;
    unsigned i;
    int v;

    fila.push(u);

    while(!fila.empty()){
        u = fila.front();
        fila.pop();

        for(i=0; i<Graph[u].size(); i++)
        {
            v = Graph[u][i];
            if(cor[v] == 1 || cor[v] == -1){
                cor[v] = cor[u]*(-1);
                fila.push(v);
            }
            else if(cor[v] == cor[u])
                return false;
        }
    }
    return true;
}
*/



