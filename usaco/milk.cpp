/*
ID: lizardo1
PROG: milk
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <utility>  

using namespace std;



int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");

	int n, m;
	
	fscanf(fin, "%d %d", &n, &m);
	
	vector<pair<int, int> > vp(m);
	int p, a;

	for(int i=0; i<m; i++){
		fscanf(fin, "%d %d", &p, &a);
		vp[i] = make_pair(p, a);
	}
	
	sort(vp.begin(), vp.end());
		
	int price=0;
	for(int i=0; i<m && n>0; i++){
		if(n - vp[i].second >= 0){
			n -= vp[i].second;
			price += vp[i].first*vp[i].second;
		}
		else{
			price += n*vp[i].first;
			n = 0; 
		}
	}
	
	fprintf(fout, "%d\n", price);
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}




