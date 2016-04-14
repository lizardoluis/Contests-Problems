/*
ID: lizardo1
PROG: ariprog
LANG: C++11
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("ariprog.in", "r");
    fout = fopen("ariprog.out", "w");

	int n, m;
	set< pair<int, int> > seqs;

	bool done[125001] = {false};
	
	
	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);
	
	vector<int> bisquares(m*m*2);
	
	int k=0;
	for(int p=0; p<=m; p++){
		for(int q=p; q<=m; q++){
			int num = p*p + q*q;
			bisquares[k++]=num;
			done[num] = true;
		}
	}		
	
	for (int i=0; i<k; i++){
    	
    	for (int  j=i+1; j<k; j++){
    		
    		if(bisquares[i] != bisquares[j]){
    		
				int sm = min(bisquares[i], bisquares[j]);
				int bg = bisquares[i] + bisquares[j] - sm;
				
				int diff = bg - sm;
			    			
				int count=2;
			
				if(sm + (n-1)*diff <= 125001 && done[ sm + (n-1)*diff ]){
			
					while( sm + count*diff <= 125001 && done[ sm + count*diff ] ) {    				
						count++;
						if(count >= n){
							seqs.insert( make_pair(diff, sm + (count-n)*diff) );
						}       				
					} 
					
				}
			}
    	}
	}

	if(seqs.empty())
		fprintf(fout, "NONE\n");
	else {
		for ( auto it = seqs.begin(); it != seqs.end(); ++it ){
			fprintf(fout, "%d %d\n", (*it).second, (*it).first);
		}
	}
	
	fclose(fin);
	fclose(fout);

	return 0;
}




