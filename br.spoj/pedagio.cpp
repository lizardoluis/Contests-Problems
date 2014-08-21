#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

class Grafo{
private:
	vector < vector<int> > Graph;
	vector <int> antecessor;
	vector <int> color;
	enum { BRANCO, CINZA, PRETO };


public:
	void visitaBfs(int u, int p, vector <int> & cidades, vector <int> & cor);
	Grafo(int NVertices);
	void Insere(int v1, int v2);
	bool ListaAdjVazia(int v);
	char *GRAPHtwocolor();
	int BuscaEmLargura(unsigned origem, int p);
	void pedagio(int u, vector <int> & cidades, int p);
};

int main()
{
	int n, m, v, w, l, p;

	int t=1;

	while(scanf("%d %d %d %d\n", &n, &m, &l, &p) && n >0 && m>0 && l >0 && p>0){

		Grafo grafo(n);

		vector <int> cidades(n);
		vector <int> cor(n, 0);

		cidades.clear();
		cor.clear();

		for(int i=0; i<m; i++){
			scanf("%d %d", &v, &w);

			grafo.Insere(v-1, w-1);
		}

		grafo.visitaBfs(l-1, p, cidades, cor);

		sort(cidades.begin(), cidades.end());

		printf("Teste %d\n", t++);

		bool ok = true;

		for(int i=0; i<cidades.size(); i++){
			if(cidades[i] != l-1){
				if(ok){
					printf("%d", cidades[i]+1);
					ok = false;
				}
				else
					printf(" %d", cidades[i]+1);
			}
		}
		printf("\n\n");
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


void Grafo::visitaBfs(int u, int p, vector <int> & cidades, vector <int> & cor)
{
	cor[u] = CINZA;
	queue < pair< int, int > > fila;

	fila.push( make_pair( u, p-- ) );

	while(!fila.empty()){

		pair< int, int > mypair = fila.front();
		fila.pop();

//		printf("-%d\n", mypair.second);

		if(mypair.second < 0)
			continue;

		cidades.push_back(mypair.first);

		if( !ListaAdjVazia(u) ){
			for(unsigned i=0; i<Graph[mypair.first].size(); i++)
			{
				int v = Graph[mypair.first][i];
				if(cor[v] == BRANCO){
					cor[v] = CINZA;
					fila.push(make_pair( v, mypair.second-1 ));
				}
			}
		}
		cor[u] = PRETO;
	}
}


