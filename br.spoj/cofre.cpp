#include <stdio.h>

using namespace std;

int main(){

    int n, j, z, t=1;

    while(scanf("%d\n", &n) && n != 0){
    	int diff = 0;
    	printf("Teste %d\n", t++);

    	for(int i=0; i<n; i++){
    		scanf("%d %d\n", &j, &z);
    		diff += j - z;
    		printf("%d\n", diff);
    	}

    }

    return 0;
}


