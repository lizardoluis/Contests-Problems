#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;

#define TAM 16
#define TAMNOME 3
#define MAX 100001

class Grafo{
    private:
        vector < vector< pair<int,int> > > Graph;
        enum { BRANCO, CINZA, PRETO };

    public:
        Grafo(){};

        Grafo(int NVertices)
        {
            Graph.resize(NVertices);
        }

        void Insere(int v1, int v2, int peso)
        {
            Graph[v1].push_back(make_pair(v2, peso));
        }

        bool ListaAdjVazia(int v)
        {
            if(Graph[v].size() == 0)
                return true;
            else return false;
        }

        int NumVertices(){
            return Graph.size();
        }

        int ProxAdj(unsigned v, unsigned a, int *peso){

            if(v >= Graph.size() || Graph[v].size()==0 || a >= Graph[v].size())
                return -1;
            else{
                *peso = Graph[v][a].second;
                return Graph[v][a].first;
            }
        }

        void Imprime(){
            for(unsigned i=0; i<Graph.size(); i++){
                printf("\n%d - ", i+1);
                for(unsigned j=0; j<Graph[i].size(); j++){
                    printf("%d ", Graph[i][j].first+1);
                }
            }
            printf("\n\n");
        }

        int getPeso(int u, int v){
            for(unsigned i=0; i<Graph[u].size(); i++){
                if(Graph[u][i].first == v)
                    return Graph[u][i].second;
            }
            return -1;
        }
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------

class FPHeapMinIndireto{
    private:
        int n;
        vector < int > pos;
        vector < int > fp;
        vector < int > p;

    public:
        FPHeapMinIndireto (vector < int > & P, vector < int > & V){
            p = P;
            fp = V;
            n = fp.size()-1;
            pos.resize(n);

            for(int u=0; u<n; u++)
                pos[u] = u+1;
        }

        void refaz(int esq, int dir){
            int j=esq*2;
            int x=fp[esq];
            while(j<=dir){
                if( j<dir && ( p[fp[j]] > p[fp[j+1]] ) )
                    j++;
                if( p[x] <= p[fp[j]])
                    break;
                fp[esq] = fp[j];
                pos[fp[j]] = esq;
                esq = j;
                j=esq*2;
            }
            fp[esq] = x;
            pos[x] = esq;
        }

        void constroi(){
            int esq = n/2 + 1;
            while (esq > 1){
                esq--;
                refaz(esq, n);
            }
        }

        int retiraMin(){
            int minimo;
            if(n<1)
                printf("Heap Vazio!\n");
            else{
                minimo = fp[1];
                fp[1] = fp[n];
                pos[fp[n--]]=1;
                refaz(1, n);
            }
            return minimo;
        }

        void diminuiChave(int i, int chaveNova, vector <int> & peso){
            i = pos[i];
            int x = fp[i];
            if(chaveNova < 0)
                printf("Chave nova com valor incorreto!\n");

            p[x] = chaveNova;

            while((i>1) && (p[x] <= p[fp[i/2]])){
                fp[i] = fp[i/2];
                pos[fp[i/2]] = i;
                i/=2;
            }
            fp[i] = x;
            pos[x] = i;
            peso = p;
        }

        bool vazio(){
            return n==0;
        }
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------

class Dijkstra{
    private:
        vector < int > antecessor;
        vector < int > p;
        Grafo grafo;

    public:
        Dijkstra(Grafo &grafo)
        {
            this->grafo = grafo;
        }

        void obterArvoreCMC(int raiz)
        {
            int n = grafo.NumVertices();
            vector < int > vs(n+1);
            p.resize(n);
            antecessor.resize(n);

            for(int u=0; u<n; u++){
                antecessor[u] = -1;
                p[u] = MAX;
                vs[u+1] = u;
            }
            p[raiz] = 0;
            FPHeapMinIndireto heap(p, vs);
            heap.constroi();

            while(!heap.vazio()){
                int u = heap.retiraMin();
                int peso, a=0;
                int v = grafo.ProxAdj(u, a++, &peso);
                while(v>=0){
                    if( p[v] > (p[u] + peso) ){
                        antecessor[v] = u;
                        heap.diminuiChave(v, p[u]+peso, p);
                    }
                    v = grafo.ProxAdj(u, a++, &peso);
                }
            }
        }

        int tamanhoCaminho(int v)
        {
            if(p[v] == MAX)
                return -1;
            else
                return p[v];
        }
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------

int main()
{
    int N, M, s, d;
    int v1, v2, p;

    ios::sync_with_stdio(false);

    scanf("%d %d", &N, &M);
    while(N!=0 || M!=0)
    {
        Grafo grafo(N);

        for(int i=0; i<M; i++){
            scanf("%d %d %d", &v1, &v2, &p);
            grafo.Insere(v1-1, v2-1, p);
        }
        scanf("%d %d", &s, &d);

        Dijkstra dij(grafo);
        dij.obterArvoreCMC(s-1);
        printf("%d\n", dij.tamanhoCaminho(d-1));

        scanf("%d %d", &N, &M);
    }

    return 0;
}



