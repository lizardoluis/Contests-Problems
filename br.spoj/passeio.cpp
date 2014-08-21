#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Grafo{
    private:
        vector < vector< int > > Graph;

    public:
        Grafo(){};

        Grafo(int NVertices)
        {
            Graph.resize(NVertices);
        }

        void Insere(int v1, int v2)
        {
            Graph[v1].push_back(v2);
        }

        bool ListaAdjVazia(int v)
        {
            if(Graph[v].size() == 0)
                return true;
            else return false;
        }

        int NumVertices()
        {
            return Graph.size();
        }

        int ProxAdj(unsigned v, unsigned a)
        {
            if(v >= Graph.size() || Graph[v].size()==0 || a >= Graph[v].size())
                return -1;
            else{
                return Graph[v][a];
            }
        }

        void Imprime()
        {
            printf("\n----------");
            for(unsigned i=0; i<Graph.size(); i++){
                printf("\n%d - ", i+1);
                for(unsigned j=0; j<Graph[i].size(); j++){
                    printf("%d ", Graph[i][j]+1);
                }
            }
            printf("\n----------\n\n");
        }
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------

class BuscaEmProfundidade{
    private:
        enum { BRANCO, CINZA, PRETO };
        vector <int> d;
        Grafo grafo;

        int visitaDfs(int u, vector <int> & cor)
        {
            int t=0;
            cor[u] = CINZA;

            //printf("%d ", u);

            int a=0, v=grafo.ProxAdj(u, a++);
            while(v>=0){
                if(cor[v] == BRANCO){
                    t = visitaDfs(v, cor);
                    if(t>d[u])
                        d[u]=t;
                }
                else{
                    if(d[v]+1>d[u])
                        d[u]=d[v]+1;
                }

                v = grafo.ProxAdj(u, a++);
            }

            cor[u] = PRETO;

            return d[u]+1;
        }

    public:
        BuscaEmProfundidade(Grafo g)
        {
            grafo = g;
        }

        void buscaEmProfundidade(int w)
        {
            int dist;
            unsigned n = grafo.NumVertices();
            d.resize(n,0);
            vector <int> cor(n, BRANCO);

            int a=0, v=grafo.ProxAdj(w, a++);
            while(v>=0){
                if(cor[v] == BRANCO){
                    dist = visitaDfs(v, cor);
                    if(dist > d[w])
                        d[w] = dist;
                }
                else{
                    if(d[v]+1>d[w])
                        d[w]=d[v]+1;
                }
                v = grafo.ProxAdj(w, a++);
            }
        }

        int getPontosTuristicos(int v)
        {
            return d[v];
        }
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------

int main()
{
    int P, L, I, v1, v2, T=1;

    scanf("%d %d %d", &P, &L, &I);
    while(P!=0){
        int altitude[P];
        Grafo grafo(P);

        for(int i=0; i<P; i++)
            scanf("%d ", &altitude[i]);

        for(int i=0; i<L; i++){
            scanf("%d %d", &v1, &v2);

            if(altitude[v1-1] <= altitude[I-1] && altitude[v2-1] <= altitude[I-1]){
                if(altitude[v1-1] > altitude[v2-1])
                    grafo.Insere(v1-1, v2-1);
            }
        }
        //grafo.Imprime();
        BuscaEmProfundidade dfs(grafo);
        dfs.buscaEmProfundidade(I-1);
        printf("Teste %d\n%d\n\n", T++, dfs.getPontosTuristicos(I-1) );

        scanf("%d %d %d", &P, &L, &I);
    }

    return 0;
}



