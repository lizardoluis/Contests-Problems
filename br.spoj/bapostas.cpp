#include <stdio.h>

using namespace std;

void kadane(int *v, int n, int & x, int &y , int & max_total){
	int max_atual;
	int xtemp;
	int i;
	max_atual = 0;
	max_total = -1;
	xtemp = 0;
	for(i=0;i<n;i++){
		max_atual = max_atual + v[i];
		if(max_atual < 0) {
			max_atual = 0;
			xtemp = i+1;
		}
		if(max_atual > max_total){
			max_total = max_atual;
			x = xtemp;
			y = i;
		}
	}
}

int main(){

	int n;

	while(scanf("%d", &n) && n > 0){

		int v[n];

		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}

		int x,y,max;
		kadane(v,n,x,y,max);

		if(max == 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", max);

	}

	return 0;
}


