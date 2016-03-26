/*
ID: lizardo1
PROG: dualpal
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>

using namespace std;


bool isPalindrome(string s){
	
	int j = s.size()-1;
	int i =0;

	while(i<j){

		if(s.at(i)!=s.at(j))		
			return false;
		i++;
		j--;
	}	
	
	return true;
}

string toBase(int num, int base){
	
	string s;

	while(num > 0){
	
		int rest = num%base;
		
		
		char c;
		if(rest > 9){
			c = 'A'- 10 + rest;
		}
		else
			c = '0' + rest;
		
		s.push_back(c);
		num /= base;
	}
	
	reverse(s.begin(), s.end());

	return s;

}

int main(int argc, char **argv){

	FILE *fin, *fout;
	fin = fopen("dualpal.in", "r");
    fout = fopen("dualpal.out", "w");

	int n, s;
	fscanf(fin, "%d %d", &n, &s);
	
	int count_n=0;	

	for(int i=s+1; ;i++){
		
		int count_b=0;
		for(int b=2; b<=10; b++){
		
			string str = toBase(i, b);
		
			if(isPalindrome(str))
				count_b++;
		
			if(count_b==2){
				count_n++;
				fprintf(fout, "%d\n", i);
				break;
			}				
		}
		

		if(count_n == n){

			break;

		}
		
		
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}




