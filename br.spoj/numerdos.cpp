#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <limits.h>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define TAM 16
#define TAMNOME 3

class Grafo{
    private:
        vector < vector< int > > Graph;
        unsigned NumVertices;

    public:
        Grafo(){};

        Grafo(int NVertices)
        {
            Graph.resize(NVertices);
            NumVertices=0;
        }

        void Insere(int v1, int v2)
        {
            Graph[v1].push_back(v2);
            Graph[v2].push_back(v1);
        }

        bool ListaAdjVazia(int v)
        {
            if(Graph[v].size() == 0)
                return true;
            else return false;
        }

        int getNumVertices(){
            return NumVertices;
        }

        void setNumVertices(unsigned n)
        {
            NumVertices = n;
        }

        int ProxAdj(unsigned v, unsigned a)
        {
            if(v >= NumVertices || Graph[v].size()==0 || a >= Graph[v].size())
                return -1;
            else{
                return Graph[v][a];
            }
        }

        void Imprime()
        {
            printf("\n----------");
            for(unsigned i=0; i<NumVertices; i++){
                printf("\n%d - ", i);
                for(unsigned j=0; j<Graph[i].size(); j++){
                    printf("%d ", Graph[i][j]);
                }
            }
            printf("\n----------\n\n");
        }
};

class BuscaEmLargura{
    private:
        enum { BRANCO, CINZA, PRETO };
        vector <int> antecessor;
        vector <int> d;
        Grafo grafo;

        void visitaBfs(int u, vector <int> & cor)
        {
            cor[u] = CINZA;
            d[u] = 0;
            queue <int> fila;

            fila.push(u);

            while(!fila.empty()){
                u = fila.front();
                fila.pop();

                int a=0, v=grafo.ProxAdj(u, a++);
                while(v>=0)
                {
                    if(cor[v] == BRANCO){
                        cor[v] = CINZA;
                        d[v] = d[u]+1;
                        antecessor[v] = u;
                        fila.push(v);
                    }
                    v = grafo.ProxAdj(u, a++);
                }
                cor[u] = PRETO;
            }
        }

    public:
        BuscaEmLargura(Grafo g)
        {
            grafo = g;
            int n = grafo.getNumVertices();
            d.resize(n, INT_MAX);
            antecessor.resize(n, -1);
        }

        void buscaEmLargura(int u)
        {
            int n = grafo.getNumVertices();
            vector <int> cor(n, BRANCO);

            visitaBfs(u, cor);
        }

        void ImprimeCaminho(int origem, int v)
        {
            if(origem == v){
                printf("%d ", origem);
            }
            else if(antecessor[v] == -1)
                printf("\nNao existe caminho de %d ate %d ", origem, v);
            else{
                ImprimeCaminho(origem, antecessor[v]);
                printf("%d ", v);
            }
        }

        int getDistancia(int v)
        {
            return d[v];
        }

        int getAntecessor(int v)
        {
            return antecessor[v];
        }
};

//--------------------------------------------------------------
//--------------------------------------------------------------

int main()
{
    int A, autores[10], T=1, Erdos;
    char Nome[TAMNOME], Sobrenome[TAM], c;

    scanf("%d", &A);

    while(A>0)
    {
        Grafo grafo(100);
        map < pair<string, string>, int> Map;
        map<pair<string, string>, int>::iterator it;
        int v=0;

        for(int i=0; i<A; i++)
        {
            int j=0;
            do{
                scanf("%s %[^,.]%c", Nome, Sobrenome, &c);

                it = Map.find(make_pair(Sobrenome, Nome));
                if(it == Map.end()){
                    Map[make_pair(Sobrenome, Nome)] = v;
                    autores[j++] = v++;
                }
                else{
                    autores[j++] = it->second;
                }
            }while(c != '.');

            for(int w=1; w<j; w++){
                for(int x=w-1; x>=0; x--)
                    grafo.Insere(autores[w], autores[x]);
            }
        }

        grafo.setNumVertices(Map.size());
        //grafo.Imprime();

        it = Map.find(make_pair("Erdos", "P."));
        Erdos = it->second;

        BuscaEmLargura dfs(grafo);

        if(it != Map.end())
            dfs.buscaEmLargura(Erdos);

        printf("Teste %d\n", T++);

        for(it = Map.begin(); it != Map.end(); ++it){
            if(it->second != Erdos)
            {
                if(dfs.getAntecessor(it->second) == -1)
                    cout<<it->first.second<<" "<<it->first.first<<": infinito\n";
                else
                    cout<<it->first.second<<" "<<it->first.first<<": "<<dfs.getDistancia(it->second)<<"\n";
            }
        }
        printf("\n");
        scanf("%d", &A);
    }

    return 0;
}

/*
    for(map<pair<string, string>, int>::iterator it = Map.begin(); it != Map.end(); ++it){
        cout<<it->second<<" - "<<it->first.first<<" "<<it->first.second<<"\n";
    }
*/



