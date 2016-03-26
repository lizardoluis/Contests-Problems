/*
ID: lizardo1
PROG: skidesign
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
	fin = fopen("skidesign.in", "r");
    fout = fopen("skidesign.out", "w");

	int n;
	fscanf(fin, "%d", &n);
	
	int v[n];
	int min_input=101, max_input=0;
	
	for(int i=0; i<n; i++){
		fscanf(fin, "%d", &v[i]);
		
		min_input = min(min_input, v[i]);
		max_input = max(max_input, v[i]);
	}
	
	int min_tax = 999999999;
	for(int i=min_input, j=i+17; j<=max_input; i++, j++){
		
		int sum=0;
		for(int k=0; k<n; k++){
			
			if( v[k] < i )
				sum += (i-v[k])*(i-v[k]);
			else if( v[k] > j)
				sum += (v[k]-j)*(v[k]-j);
			
		}
		
		min_tax = min(min_tax, sum);		
	}
	
	fprintf(fout, "%d\n", min_tax);
	
	fclose(fin);
	fclose(fout);

	return 0;
}




