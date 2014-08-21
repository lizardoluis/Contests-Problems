#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stack>

#define TAM 10
#define OUT -1
#define IN 0
#define VISITED 2

using namespace std;

int initBoard(vector < vector<int> > & Board, int n);
void printBoard(vector < vector<int> > & Board, int n);
int initPosition(vector < vector<int> > & Board, int n);
bool ValidaMovimento(int x, int y, vector < vector<int> > & Board, int n);
void Tenta(int x, int y, vector < vector<int> > & Board, int n, int Squares, int &Maior);

int main()
{
    int n, y, k=1;
    vector < vector<int> > Board (TAM, vector<int>(TAM));

    scanf("%d", &n);
    while(n > 0)
    {
        int numSquares = initBoard(Board, n);
        int Maior=0;
        y = initPosition(Board, n);

        Tenta(0, y, Board, n, 1, Maior);

        if(numSquares - Maior != 1)
            printf("Case %d, %d squares can not be reached.\n", k++, numSquares-Maior);
        else
            printf("Case %d, %d square can not be reached.\n", k++, numSquares-Maior);

        scanf("%d", &n);
    }

    return 0;
}

int initBoard(vector < vector<int> > & Board, int n)
{
    int skipped, size, numSquares=0;

    for(int i=0; i<n; i++){
        scanf("%d %d", &skipped, &size);
        numSquares += size;
        for(int j=0; j<TAM; j++){
            if(j>=skipped && j<skipped+size)
                Board[i][j] = IN;
            else
                Board[i][j] = OUT;
        }
    }
    return numSquares;
}

void printBoard(vector < vector<int> > & Board, int n)
{
    for(int i=0; i<n; i++){
        for(unsigned j=0; j<Board[i].size(); j++){
            printf("%2d ", Board[i][j]);
        }
        printf("\n");
    }
}

int initPosition(vector < vector<int> > & Board, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if(Board[0][i] == 0){
            break;
        }
    }

    return i;
}

void Tenta(int x, int y, vector < vector<int> > & Board, int n, int Squares, int &Maior)
{
    if(Squares > Maior)
        Maior = Squares;

    Board[x][y] = VISITED;

    if( ValidaMovimento(x-2, y-1, Board, n) )
        Tenta(x-2, y-1, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x-2, y+1, Board, n) )
        Tenta(x-2, y+1, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x-1, y-2, Board, n) )
        Tenta(x-1, y-2, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x-1, y+2, Board, n) )
        Tenta(x-1, y+2, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x+1, y-2, Board, n) )
        Tenta(x+1, y-2, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x+1, y+2, Board, n) )
        Tenta(x+1, y+2, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x+2, y-1, Board, n) )
        Tenta(x+2, y-1, Board, n, Squares+1, Maior);

    if( ValidaMovimento(x+2, y+1, Board, n) )
        Tenta(x+2, y+1, Board, n, Squares+1, Maior);

    Board[x][y] = IN;

}

bool ValidaMovimento(int x, int y, vector < vector<int> > & Board, int n)
{
    if(x<0 || y<0 || x >= n || y>=TAM)
        return false;
    else if(Board[x][y] != IN)
        return false;
    else
        return true;
}


