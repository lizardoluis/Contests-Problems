#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int Colhedeira(vector < vector <int> > & Campo, int lin, int col);
void ColheDeOeste(int linha, int col, vector <int> & Oeste, vector < vector <int> > & Maquina, vector < vector <int> > & Campo);
void ColheDeLeste(int linha, int col, vector <int> & Leste, vector < vector <int> > & Maquina, vector < vector <int> > & Campo);

int main()
{
    int N, M, t=1;;

    scanf("%d %d", &N, &M);

    while(N > 0 && M > 0)
    {
        vector < vector <int> > Campo(N, vector<int>(M));
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++)
                scanf("%d ", &Campo[i][j]);
        }

        printf("Teste %d\n%d\n\n", t++, Colhedeira(Campo, N, M) );

        scanf("%d %d", &N, &M);
    }

    return 0;
}

int Colhedeira(vector < vector <int> > & Campo, int lin, int col)
{
    vector < vector <int> > Maquina(lin, vector<int>(col));
    vector <int> Leste(col);
    vector <int> Oeste(col);

    Maquina[0][0] = Campo[0][0];

    for(int i=1; i<col; i++)
        Maquina[0][i] = Campo[0][i] + Maquina[0][i-1];

    if(lin>1){
        for(int l=1; l<lin-1; l++){
            ColheDeOeste(l, col, Oeste, Maquina, Campo);
            ColheDeLeste(l, col, Leste, Maquina, Campo);
            for(int c=0; c<col; c++)
                if(Oeste[c]>Leste[c])
                    Maquina[l][c] = Oeste[c];
                else
                    Maquina[l][c] = Leste[c];
        }
        ColheDeOeste(lin-1, col, Oeste, Maquina, Campo);
        for(int i=0; i<col; i++)
            Maquina[lin-1][i] = Oeste[i];
    }

    return Maquina[lin-1][col-1];
}

void ColheDeOeste(int linha, int col, vector <int> & Oeste, vector < vector <int> > & Maquina, vector < vector <int> > & Campo)
{
    Oeste[0] = Maquina[linha-1][0] + Campo[linha][0];

    for(int i=1 ; i<col ; i++){
        if(Maquina[linha-1][i] > Oeste[i-1])
            Oeste[i] = Maquina[linha-1][i] + Campo[linha][i];
        else
            Oeste[i] = Oeste[i-1] + Campo[linha][i];
    }
}

void ColheDeLeste(int linha, int col, vector <int> & Leste, vector < vector <int> > & Maquina, vector < vector <int> > & Campo)
{
    Leste[col-1] = Maquina[linha-1][col-1] + Campo[linha][col-1];

    for(int i=col-2 ; i>=0 ; i--){
        if(Maquina[linha-1][i] > Leste[i+1])
            Leste[i] = Maquina[linha-1][i] + Campo[linha][i];
        else
            Leste[i] = Leste[i+1] + Campo[linha][i];
    }
}


