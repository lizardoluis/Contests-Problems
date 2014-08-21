#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>

using namespace std;

class Grafo{
private:
	vector < vector<int> > Graph;
	vector <int> antecessor;
	vector <int> color;
	enum { BRANCO, CINZA, PRETO };
	void visitaBfs(int u, vector <int> & cor, vector <int> & d);

public:
	Grafo(int NVertices);
	void Insere(int v1, int v2);
	bool ListaAdjVazia(int v);
	char *GRAPHtwocolor();
	int BuscaEmLargura(unsigned origem);
};

int main()
{
	int n, m, v, w;

	int t=1;


	while(scanf("%d %d\n", &n, &m) && n >0 && m>0){

		int res = 1;

		Grafo grafo(n);

		for(int i=0; i<m; i++){
			scanf("%d %d", &v, &w);

			grafo.Insere(v-1, w-1);
		}

		if(grafo.BuscaEmLargura(0) == 1)
			printf("Teste %d\nnormal\n\n", t++);
		else
			printf("Teste %d\nfalha\n\n", t++);
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

int Grafo::BuscaEmLargura(unsigned origem)
{
	vector <int> cor(Graph.size(), BRANCO);
	vector <int> d(Graph.size(), INT_MAX);

	//Visita ponto de partida
	if(cor[origem] == BRANCO){
		visitaBfs(origem, cor, d);
	}

	for(unsigned i=0; i<Graph.size(); i++){
		if(cor[i] == BRANCO)
			return 0;
	}

	return 1;
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
					//                    d[v] = d[u]+1;
					//                    antecessor[v] = u;
					fila.push(v);
				}
			}
		}
		cor[u] = PRETO;
	}
}


