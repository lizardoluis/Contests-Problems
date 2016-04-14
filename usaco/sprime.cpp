/*
ID: lizardo1
PROG: sprime
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int first_primes[] = {2, 3, 5, 7};
int nums[] = {1, 3, 7, 9};
FILE *fin, *fout;

bool isPrime(int number){
	if (number <= 1) return false; // zero and one are not prime
    for (int i=2; i*i<=number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}


void num_gen(int n, int num, int size){
	
	if(size == n){
		fprintf(fout, "%d\n", num);
		return;
	}

	for(int i=0; i<4; i++){
		int new_num = num*10 + nums[i];
		if(isPrime(new_num))
			num_gen(n, new_num, size+1);
	}
} 


int main(int argc, char **argv){

	fin = fopen("sprime.in", "r");
    fout = fopen("sprime.out", "w");

	int n;
	fscanf(fin, "%d", &n);

	
	for(int i=0; i<4; i++)
		num_gen(n, first_primes[i], 1);		
	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




