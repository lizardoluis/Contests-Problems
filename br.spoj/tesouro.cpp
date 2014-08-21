#include <stdio.h>

int v[101];
char m[101][10001];

int main (void)
{
    int x, y, n;
    int i, j, max, b;
    int iCaso = 1;
    int result;

    for (;;)
    {
        scanf ("%d %d %d\n", &x, &y, &n);
        if ((x == 0) && (y == 0) && (n == 0))
            break;
        max = 0;
        for (i = 1; i <= n; i++)
        {
            scanf ("%d\n", &v[i]);
            max += v[i];
        }
        if (x > y)
          b = max + y - x;
        else
          b = max + x - y;
        if ((b < 0) || ((b & 1) != 0))
          result = 0;
        else if (b == 0)
          result = 1;
        else
        {
            b = b/2;
            for (i = 1; i <= b; i++)
                m[1][i] = 0;
            m[1][v[1]] = 1;
            for (i = 2; i <= n; i++)
            {
                for (j = 1; j <= b; j++)
                {
                    if (j == v[i])
                        m[i][j] = 1;
                    else if (j < v[i])
                        m[i][j] = m[i-1][j];
                    else if (m[i-1][j] || m[i-1][j - v[i]])
                        m[i][j] = 1;
                    else
                        m[i][j] = 0;
                }
            }
            result = m[n][b];
        }
        printf ("Teste %d\n%c\n\n", iCaso, result ? 'S' : 'N');
        iCaso++;
    }

    return 0;
}

/*#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>

using namespace std;

int subset_sum(vector <int> & weight, int N, int W);

int main()
{
    int joao, jose, n, t=1, part;
    ios::sync_with_stdio(false);

    //scanf("%d %d %d", &joao, &jose, &n);
    cin>>joao>>jose>>n;

    while(joao>0 && jose>0 && n>0)
    {
        int sum=0;
        vector <int> v(n+1);
        vector <int> p(n+1);

        for(int i=1; i<=n; i++){
            //scanf("%d", &v[i]);
            cin>>v[i];
            p[i] = v[i];
            sum += v[i];
        }

        part = (jose-joao+sum)/2;

        if((jose-joao+sum)%2==0 && sum >= abs(joao-jose) && subset_sum(v, n, part) == part )
            //printf("Teste %d\nS\n\n", t++);
            cout<<"Teste "<<t++<<"\nS\n\n";
        else
            //printf("Teste %d\nN\n\n", t++);
            cout<<"Teste "<<t++<<"\nN\n\n";

        //scanf("%d %d %d", &joao, &jose, &n);
        cin>>joao>>jose>>n;
    }

    return 0;
}

int subset_sum(vector <int> & weight, int N, int W)
{
    vector < vector <bool> > opt (N+1, vector<bool>(W+1));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=W; j++){
            if( weight[i] < W )
                opt[i][j] = true;
        }
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=W; j++){
            cout<<opt[i][j]<<" ";
        }
        cout<<"\n";
    }

    return opt[N][W];
}
*/



