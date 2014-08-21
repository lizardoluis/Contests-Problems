#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long b2d(string binary){
	long long sum=0;
	int exp = binary.length()-1;

	for(int i=0; i < binary.length(); i++){
		if(binary[i] == '1'){
			sum += pow(2, exp);
		}
		exp--;
	}

	return sum;
}

int main()
{
	int t=1;
	string palavra = "";

	while( cin >> palavra ){

		string binary(palavra.length(), '0');

		for(int i=0; i < palavra.length(); i++){
			if(palavra[i] == 'b'){
				binary[i] = '1';
			}
		}

		printf("Palavra %d\n%lld\n\n", t++, b2d(binary));
	}

    return 0;
}



