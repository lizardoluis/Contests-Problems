/*
ID: lizardo1
PROG: pprime
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int mult[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
vector<int> palindromes, v;
int a, b;


int getLength(int n){
	int length=0;
	
	while(n>0){
		length++;
		n = n/10;
	}
	
	return length;
}

void palindromeGen(int len, int half_len, bool even){

	if(len == half_len) {

		int palindrome = 0;
		
		for(int i=0; i<half_len; i++){
			if(even)
				palindrome += v[i]*mult[9-half_len*2+i] + v[i]*mult[8-i];				
			else{
				if(i==half_len-1)
					palindrome += v[i]*mult[8-i];	
				else
					palindrome += v[i]*mult[9-(half_len*2-1)+i] + v[i]*mult[8-i];
						
			}
				
		}
		if(palindrome>=a && palindrome<=b){
			palindromes.push_back(palindrome);
		}

		return;
	}	
	
	// recurssion
	if(len==0)
		for(int i=1; i<=9; i+=2) {	
			if(i!=5){
				v[len] = i;
				palindromeGen(len+1, half_len, even);	
			}	
		}
	else	
		for(int i=0; i<=9; i++) {	
			v[len] = i;
			palindromeGen(len+1, half_len, even);		
		}
}

void palindromeGen(int length){
	
	 if(length==1){
	 	for(int i=5; i<=9; i+=2){
	 		if(i>=a && i<=b){
	 			palindromes.push_back(i);
	 		}
	 	}
	 }
	 else{	 		 
		 if(length%2 == 0){
		 	v.resize(length/2);
		 	palindromeGen(0, length/2, true);
		 }
		 else{
		 	v.resize(length/2+1);
		 	palindromeGen(0, length/2+1, false);
		 }		 	
	 }
}

void palindromeGen(int alen, int blen){
	for(int i=alen; i<=blen; i++)
		palindromeGen(i);
}


bool isPrime(int number){
	if (number <= 1) return false; // zero and one are not prime
    for (int i=2; i*i<=number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("pprime.in", "r");
    fout = fopen("pprime.out", "w");

	fscanf(fin, "%d %d\n", &a, &b);
	
	int alen = getLength(a);
	int blen = getLength(b);
	
	palindromeGen(alen, blen);
	
	for(int i=0; i<palindromes.size(); i++){
		if( isPrime(palindromes[i]) )
			fprintf(fout, "%d\n", palindromes[i]);
	}	
	
	fclose(fin);
	fclose(fout);

	return 0;
}




