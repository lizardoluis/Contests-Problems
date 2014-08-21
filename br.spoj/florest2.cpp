#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    int count=0;

    scanf("%d", &n);

    vector <bool> sieve(n+1);

    for(b=2; b<=sqrt(n); b++){
        if(sieve[b] == false){
            a = (n+b-1)/(2*b-1);
            if( (a*b + (a-1)*(b-1)) == n ){
                sieve[a] = true;
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}


