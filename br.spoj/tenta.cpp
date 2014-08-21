#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned short n, i;
    vector <int> v(8);

    ios::sync_with_stdio(false);

    cin>>n;
    while(n > 0)
    {
        for(i=0; i<n; i++){
            cin>>v[i];
        }

        sort( v.begin(), v.begin()+n );

        do{
            for (i=0; i<n; i++)
                cout << v[i] << " ";
            cout<<"\n";
        }while ( next_permutation(v.begin(), v.begin()+n) );

        cout<<"\n";
        cin>>n;
    }

    return 0;
}


