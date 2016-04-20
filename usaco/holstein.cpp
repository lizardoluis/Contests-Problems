/*
ID: lizardo1
PROG: holstein
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int min_feedtypes=0;

bool isValid(set<int> &bag, vector<int> &vitamins, vector< vector<int> > &scoops, set<int> &min_bag){	
	
	int N = vitamins.size();
	int feedtypes = 0;
	
	vector<int> sum(N, 0);
	
	for (set<int>::iterator it=bag.begin(); it!=bag.end(); ++it){
    	for(int i=0; i<N; i++){    	
    		sum[i] += scoops[*it][i];  
    		feedtypes += i;  	
    	}    	
	}
	
	for(int i=0; i<N; i++){    	
		if(sum[i] < vitamins[i]) 
			return false;    	
	} 
	
	if(min_feedtypes == 0 || feedtypes < min_feedtypes){
		min_feedtypes = feedtypes;
		min_bag = bag;
	}
	
	return true;
}

void findScoops(set<int> &bag, int lastAdded, vector<int> &vitamins, vector< vector<int> > &scoops, set<int> &min_bag){
	
	int G = scoops.size();	
	
	if(isValid(bag, vitamins, scoops, min_bag))
		return;
		
	for(int i=lastAdded+1; i<G; i++){	
		bag.insert(i);		
		findScoops(bag, i, vitamins, scoops, min_bag);
		bag.erase(i);				
	}
}


int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("holstein.in", "r");
    fout = fopen("holstein.out", "w");

	int V, G, x;
	
	fscanf(fin, "%d", &V);
	
	vector<int> vitamins(V);
	
	for(int v=0; v<V; v++){
		fscanf(fin, "%d", &x);
		vitamins[v] = x;
	}
	
	fscanf(fin, "%d", &G);
	
	vector< vector<int> > scoops(G, vector<int> (V));
	
	for(int g=0; g<G; g++){
		for(int v=0; v<V; v++){		
			fscanf(fin, "%d", &x);
			scoops[g][v] = x;
		}
	}
	
	set<int> bag;
	set<int> min_bag;
	
	for(int i=0; i<G; i++){		
		bag.insert(i);		
		findScoops(bag, i, vitamins, scoops, min_bag);
		bag.erase(i);	
	}
	
	fprintf(fout, "%ld", min_bag.size()); 
	for (set<int>::iterator it=min_bag.begin(); it!=min_bag.end(); ++it){
		fprintf(fout, " %d", *it+1);
	}
	fprintf(fout, "\n");
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




