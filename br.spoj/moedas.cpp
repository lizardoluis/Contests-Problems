#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int knapsack_unbounded(vector <int> & weights, int N, int W);
bool cmp(int a, int b);

int main()
{
    int m, n, moedas;

    scanf("%d %d", &m, &n);

    while(m > 0)
    {
        vector <int> weight(n+1);

        for(int i=n; i>0; i--){
            scanf("%d ", &weight[i]);
        }

        moedas = knapsack_unbounded(weight, n, m);
        if(moedas != INT_MAX/2)
            printf("%d\n", moedas);
        else
            printf("Impossivel\n");

        scanf("%d %d", &m, &n);
    }

    return 0;
}

int knapsack_unbounded(vector <int> & weights, int N, int W)
{
    vector <int> opt(W+1);
    opt[0] = 0;

    for (int P = 1; P<=W; P++) {
        int minres = INT_MAX/2;
        for (int i = 1; i<=N; i++){
            if (weights[i] <= P) {
                int tres = opt[P - weights[i]] + 1;
                if (minres > tres)
                    minres = tres;
            }
        }
        opt[P] = minres;
    }
    return opt[W];
}


/*
int subset_sum(vector <int> & weight, int N, int W)
{
    int s;
    vector < vector <int> > opt (N+1, vector<int>(W+1));

    for (int i = 0; i <= N; i++)
        opt[i][0] = 1;

    for (int j = 1; j <= W; j++){
        opt[0][j] = 0;

        for(int i=1; i <= N; i++)
        {
            s = opt[i-1][j];

            if(s==0 && weight[i] <= j)
                s = opt[i-1][j-weight[i]];
            opt[i][j] = s;
        }
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            printf("%d ", opt[i][j]);
        }
        printf("\n");
    }

    return opt[N][W];
}
*/




