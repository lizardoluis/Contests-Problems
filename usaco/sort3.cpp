/*
ID: lizardo1
PROG: sort3
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
	fin = fopen("sort3.in", "r");
    fout = fopen("sort3.out", "w");

	int n;
	
	fscanf(fin, "%d", &n);
	
	int v[n];
	int nums[3] = {0,0,0};
	
	for(int i=0; i<n; i++){
		fscanf(fin, "%d", &v[i]);
		nums[v[i]-1] ++;
	}
	
	//printf("%d %d %d\n", nums[0], nums[1], nums[2]);

	//selection
	int count = 0;
	for(int i=0; i<n-nums[2]; i++){				
		
		if( i < nums[0] ){
			
			if(v[i] == 2){
				for(int j=nums[0]; j<n; j++){
					if(v[j] == 1){								
						v[i] = 1;
						v[j] = 2;
						count++;	
						break;					
					}
				}
			}
			else if(v[i] == 3){
				for(int j=n-1; j>i; j--){
					if(v[j] == 1){
						v[i] = 1;
						v[j] = 3;
						count++;
						break;
					}
				}
			}
			
		}
		else{
			
			if(v[i] == 3){
				for(int j=n-1; j>i; j--){
					if(v[j] == 2){
						v[i] = 2;
						v[j] = 3;
						count++;
						break;
					}
				}
			}
		}	
	}

	/*for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
*/
	
	fprintf(fout, "%d\n", count);
	
	fclose(fin);
	fclose(fout);

	return 0;
}




