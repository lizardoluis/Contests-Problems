/*
ID: lizardo1
PROG: palsquare
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
	fin = fopen("palsquare.in", "r");
    fout = fopen("palsquare.out", "w");

	int base;
	fscanf(fin, "%d", &base);	

	for(int i=1; i<=300; i++){
		
		int p = i*i;

		string pow_base = toBase(p, base);

		if(isPalindrome(pow_base)){

			string n = toBase(i, base);

			fprintf(fout, "%s %s\n", n.c_str(), pow_base.c_str());

		}
	}
	
	return 0;
}




