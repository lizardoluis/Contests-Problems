/*
ID: lizardo1
PROG: numtri
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("numtri.in", "r");
    fout = fopen("numtri.out", "w");

	int R, n;

	fscanf(fin, "%d", &R);
	
	vector< vector<int> > acc(R, vector<int>(R,0) );
	
	for(int l=0; l<R; l++){
		for(int i=0; i<=l; i++){
			fscanf(fin, "%d", &n);
			
			if(l==0){
				acc[l][0] = n;
			}
			else{
				if(i == 0){
					acc[l][i] = acc[l-1][i] + n;  
				} 
				else{
					acc[l][i] = max(acc[l-1][i], acc[l-1][i-1]) + n;
				}
			}	
			//printf("%d ", acc[l][i]);		
		}	
		//printf("\n");
	}
	
	int max_sum=0;
	for(int i=0; i<R; i++){
		max_sum = max(max_sum, acc[R-1][i]);
	}
	
	fprintf(fout, "%d\n", max_sum);
	
	fclose(fin);
	fclose(fout);

	return 0;
}




