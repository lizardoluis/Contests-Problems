/*
ID: lizardo1
PROG: hamming
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


int N,B,D;

int hammingDist(unsigned a, unsigned b){

	int dist=0;
	unsigned xorn = a^b;
	
	for(int i=0; i<B; i++){
		dist += xorn & 1;
		xorn >>= 1;
	}
	
	return dist;
}

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("hamming.in", "r");
    fout = fopen("hamming.out", "w");
	
	fscanf(fin, "%d %d %d", &N, &B, &D);
	
	vector<int> codewords;
	
	codewords.push_back(0);
	
	int max = pow(2, B);
	for(int i=1; i<max && codewords.size() < N; i++){
	
		bool ok = true;
		for(int j=0; j<codewords.size(); j++){
			if(hammingDist(codewords[j], i) < D){
				ok = false;
				break;	
			}
		}	
		
		if(ok)
			codewords.push_back(i);
	}
	
	for(int i=0; i<codewords.size(); i++){
	
		fprintf(fout, "%d", codewords[i]);
		
		if( (i+1) % 10 == 0 || i == codewords.size()-1 )
			fprintf(fout, "\n");
		else fprintf(fout, " ");
	}
	
	fclose(fin);
	fclose(fout);

	return 0;
}
