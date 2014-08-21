#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;


int main()
{
	int vertices, u, v, t=1;

	while( scanf("%d", &vertices) && vertices>0 )
	{
		vector<vector<int> > a(vertices, vector<int>(vertices,999999999));

		// initialize diagonal
		for(int i=0; i < vertices; i++)
			a[i][i] = 0;

		for(int i=0; i<vertices-1; i++){
			scanf("%d %d", &u, &v);
			a[u-1][v-1] = 1;
			a[v-1][u-1] = 1;
		}


		for(int k = 0; k < vertices; k++)
			for(int i = 0; i < vertices; i++)
				for(int j = 0; j < vertices; j++)
					if(a[i][j]>a[i][k]+a[k][j])
						a[i][j] = a[i][k] + a[k][j];


		printf("Teste %d\n", t++);

		int min = INT_MAX;
		int minIndex = 0;

		// Print out final distance matrix
		for(int i = 0; i < vertices; i++){
			int max = 0;
			for(int j = 0; j < vertices; j++){
//				cout << a[i][j] << " ";
				if(a[i][j] > max)
					max = a[i][j];
			}

			if(max < min) {
				min = max;
				minIndex = i;
			}

//			cout << endl;
		}

		printf("%d\n\n", minIndex+1);

	}


	return 0;
}



