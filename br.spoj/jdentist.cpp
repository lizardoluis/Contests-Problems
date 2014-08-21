#include <stdio.h>

using namespace std;

void Inserction(int n, int s[], int vetor[]){
   int j,i,key, key2;
   for(j = 1; j < n; j++){
      key = vetor[j];
      key2 = s[j];
      i = j - 1;
      while(i >= 0 && vetor[i] > key){
         vetor[i + 1] = vetor[i];
         s[i+1] = s[i];
         i = i - 1;
      }
      vetor[i + 1] = key;
      s[i+1] = key2;
   }
}

int greedy(int *s, int n, int *f){
	int a=1;
	int j = 0;
	for (int i = 1; i < n; ++i) {
		if (s[i] >= f[j]) {
			j = i;
			a++;
		}
	}
	return a;
}

int main(){

	int n;

	scanf("%d", &n);

	int s[n], f[n];

	for (int i = 0; i < n; ++i) {
		scanf("%d %d\n", &s[i], &f[i]);
	}

	Inserction(n, s, f);

	printf("%d\n", greedy(s, n, f));

	return 0;
}


