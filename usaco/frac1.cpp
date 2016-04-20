/*
ID: lizardo1
PROG: frac1
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct classcomp {
	
	bool operator() (const double& lhs, const double& rhs) const
	{
		return rhs - lhs > 0.0000001;
	}
};

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("frac1.in", "r");
    fout = fopen("frac1.out", "w");

	int N;
	
	fscanf(fin, "%d", &N);
	
	//0/1 1/1 1/2 2/2 1/3 2/3 3/3 1/4 2/4 3/4 1/5 2/5 3/5 4/5 
	
	map<double, pair<int, int>, classcomp > fracs;
	
	for(int d=1; d<=N; d++){	
		for(int n=0; n<=d; n++){		
			double f = n/(double)d;			
			fracs.insert( pair<double, pair<int, int> >(f, make_pair(n, d) ) );
		}	
	}
	
	for (map<double, pair<int, int>, classcomp >::iterator it=fracs.begin(); it!=fracs.end(); ++it)
	{	
		fprintf(fout, "%d/%d\n", it->second.first, it->second.second);    	
    }
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




