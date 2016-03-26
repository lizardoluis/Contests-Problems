/*
ID: lizardo1
PROG: crypt1
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector <bool> map(10, false);

bool inc(vector<int> &v, int i, int n){
	
	if(v[0] == n-1 && v[1] == n-1 && v[2] == n-1 && v[3] == n-1 && v[4] == n-1)
		return false;
	
	v[i]++;
	
	if(v[i] > n-1){
		v[i]=0;
		inc(v, i+1, n);
	}
	
	return true;
} 

void print(vector<int> &v){
	for(int i=0; i<5; i++)
		printf("%d ", v[i]);
		
	printf("\n");
}

bool isValid(int num){
	
	while(num > 0){
		
		int r = num % 10;
		//printf("%d ", r);
		
		if(map[r] == false)
			return false;
			
		num /= 10;
		
		
	}	
			//printf("\n");
	
	return true;
}

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("crypt1.in", "r");
    fout = fopen("crypt1.out", "w");

	
	int n;
	fscanf(fin, "%d", &n);
	
	int digits[n];
	
	for(int i=0; i<n; i++){		
		fscanf(fin, "%d", &digits[i]); 
		map[digits[i]] = true;
	}
	
	vector<int> letters(5, 0);

	int count = 0;
						

	do {
		
		int a=digits[letters[0]];
		int b=digits[letters[1]]; 
		int c=digits[letters[2]];
		int d=digits[letters[3]];
		int e=digits[letters[4]];
		
		int p1 = e*(100*a + 10*b + c);
		int p2 = d*(100*a + 10*b + c);
		int sum = p1+10*p2;
		
		if(isValid(p1) && p1 > 100 && p1 < 1000 && isValid(p2) && p2 > 100 && p2 < 1000 && isValid(sum)){
			count++;
		}
		
	} while( inc(letters, 0, n) );
	
	fprintf(fout, "%d\n", count);
		
	fclose(fin);
	fclose(fout);

	return 0;
}




