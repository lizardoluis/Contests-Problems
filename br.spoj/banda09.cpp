#include <stdio.h>

using namespace std;

int main(){

    int N, M, x,y, z;
    int max = -1;
    int m1=0, m2=0, m3=0;

    scanf("%d %d", &N, &M);

    if(N == 3 || M == 0){
    	printf("1 2 3\n");
    	return 0;
    }

    int matriz[N+1][N+1];

    for (int i = 0; i <= N; ++i)
        	for (int j = 0; j <= N; ++j)
        		matriz[i][j] = 0;

    for (int i = 0; i < M; ++i) {
		scanf("%d %d %d", &x, &y, &z);
		matriz[x][y] = z;
		matriz[y][x] = z;
	}

    for (int i = 1; i <= N; ++i) {
    	for (int j = i+1; j <= N; ++j) {

    		if (max - matriz[i][j] > 200) continue;

    		for (int k = j+1; k <= N; ++k) {
//    			printf("Teste %d\n", matriz[i][j]+matriz[i][k]+matriz[j][k]);
    			if(matriz[i][j]+matriz[i][k]+matriz[j][k] > max){
    				max = matriz[i][j]+matriz[i][k]+matriz[j][k];
    				m1 = i;
    				m2 = j;
    				m3 = k;
    			}
    		}
    	}
    }

    printf("%d %d %d\n", m1, m2, m3);


    return 0;
}


