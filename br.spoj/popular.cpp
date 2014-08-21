#include <stdio.h>

using namespace std;

int main(){

    int n, r;

    while(scanf("%d\n", &n) && n != 0){
    	int v[n];
    	int max = 0;
    	for(int i=0; i<n; i++) v[i] = 0;

    	for(int i=0; i<n; i++){
    		for(int j=0; j<n; j++){
    			scanf("%d", &r);
    			if(r == 1){
    				v[j]++;
    				if(v[j] > max)
    					max = v[j];
    			}
    		}
    	}
    	printf("%d\n", max);
    }

    return 0;
}


