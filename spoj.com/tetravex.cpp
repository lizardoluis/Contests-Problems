#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define TAM 9

using namespace std;

class Tile{
    private:
        int A, B, C, D, I;

    public:

        int getI(){ return I; }

        void setTile(int a, int b, int c, int d, int i)
        {
            A = a; B = b; C = c; D = d, I = i;
        }

        bool verifyRight(Tile t) { return (B == t.D); }
        bool verifyBottom(Tile t) { return (C == t.A); }

        void print(){ printf("%d %d %d %d\n", A, B, C, D); };
};

bool validaTetravex(vector <Tile> &tiles);
bool cmp(Tile A, Tile B);

int main()
{
    int T, a, b, c, d;
    vector <Tile> tiles(TAM);

    scanf("%d", &T);

    for(int t=1; t<=T; t++)
    {
        bool valid=false;

        for(int i=0; i<TAM; i++){
                scanf("%d %d %d %d", &a, &b, &c, &d);
                tiles[i].setTile(a, b, c, d, i);
        }

        for(int i=0; i<362880; i++){
            if(validaTetravex(tiles)){
                valid = true;
                break;
            }
            next_permutation(tiles.begin(), tiles.end(), cmp);
        }

        if(valid)
            printf("Case %d: YES\n\n", t);
        else
            printf("Case %d: NO\n\n", t);
    }

    return 0;
}

bool validaTetravex(vector <Tile> &tiles)
{
    if(tiles[0].verifyRight(tiles[1]) == false) return false;
    if(tiles[0].verifyBottom(tiles[3]) == false) return false;
    if(tiles[1].verifyRight(tiles[2]) == false) return false;
    if(tiles[1].verifyBottom(tiles[4]) == false) return false;
    if(tiles[2].verifyBottom(tiles[5]) == false) return false;
    if(tiles[3].verifyRight(tiles[4]) == false) return false;
    if(tiles[3].verifyBottom(tiles[6]) == false) return false;
    if(tiles[4].verifyRight(tiles[5]) == false) return false;
    if(tiles[4].verifyBottom(tiles[7]) == false) return false;
    if(tiles[5].verifyBottom(tiles[8]) == false) return false;
    if(tiles[6].verifyRight(tiles[7]) == false) return false;
    if(tiles[7].verifyRight(tiles[8]) == false) return false;

    return true;
}

bool cmp(Tile A, Tile B){
    return A.getI() < B.getI();
}


