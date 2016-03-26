/*
ID: lizardo1
PROG: wormhole
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> X;
vector<int> Y;
vector<int> partner;
vector<int> nextRight;

void calcNextRight(){
	
	for(int i=0; i<n; i++){
		
		for(int j=0; j<n; j++){
		
			if(Y[i] == Y[j] && X[j] > X[i]){
				
				if( nextRight[i] == -1 || X[j]-X[i] < X[nextRight[i]]-X[i] )
					nextRight[i] = j;
			}				
		}		
	}		
	
	/*for(int i=0;i<n;i++)
		printf("%d -> %d\n", i, nextRight[i]);
		
		
	printf("\n");*/
}


bool isTrap(){
	
	for(int i=0; i<n; i++){
	
		int pos=i;
		
		int j;
		for(j=0; j<n; j++) {
			pos = nextRight[partner[pos]];
			if(pos == -1)
				break;
		}	
		if(j==n)
			return true;
	}	
	return false;
}


int solve(){

	int i, total=0;
	for(i=0; i<n; i++)
		if(partner[i]==-1)
			break;
			
	if(i==n) {
		if(isTrap())
			return 1;
		else
			return 0;		
	}
	

	for(int j=i+1; j<n; j++){
	
		if(partner[j]==-1){
			partner[i]=j;
			partner[j]=i;
			
			total += solve();
			
			partner[i] = -1;
			partner[j] = -1;
		}	
	}
	
	return total;
}


int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("wormhole.in", "r");
    fout = fopen("wormhole.out", "w");

	fscanf(fin, "%d", &n);

	X.resize(n);
	Y.resize(n);
	partner.resize(n, -1);
	nextRight.resize(n, -1);
	
	int x, y;
	for(int i=0; i<n; i++){
		fscanf(fin, "%d %d", &x, &y);
		X[i] = x;
		Y[i] = y;
	}
	
	calcNextRight();
	fprintf(fout, "%d\n", solve());
		
	
	fclose(fin);
	fclose(fout);

	return 0;
}




