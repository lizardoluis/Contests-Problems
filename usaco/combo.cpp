/*
ID: lizardo1
PROG: combo
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool map[100][100][100];
int sum = 0;

void generate(int x, int y, int z, int n){
	
	for(int i=x-2; i<=x+2; i++){
		for(int j=y-2; j<=y+2; j++){
			for(int k=z-2; k<=z+2; k++){

//				printf("%d %d %d\n",i%n, j%n, k%n); 
				
				int ii = i%n < 0 ? i%n + n : i%n;
				int jj = j%n < 0 ? j%n + n : j%n;
				int kk = k%n < 0 ? k%n + n : k%n;
				
				if( map[ii][jj][kk] ) continue;
				
				map[ii][jj][kk]  = true;
				sum++;
			}
		}
	}
	
}

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("combo.in", "r");
    fout = fopen("combo.out", "w");

	int n;
	
	fscanf(fin, "%d", &n);
	
	int f1, f2, f3, m1, m2, m3;
	
	fscanf(fin, "%d %d %d %d %d %d", &f1, &f2, &f3, &m1, &m2, &m3);	
	
	generate(f1, f2, f3, n);
	generate(m1, m2, m3, n);
	
	fprintf(fout, "%d\n", sum);
	printf("%d\n", sum);
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




