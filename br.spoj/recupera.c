#include <stdio.h>
#include <stdlib.h>

int main() {
	int counter=1;
	int n;
	while(fscanf(stdin, "%d", &n)>0) {
		fprintf(stdout, "Instancia %d\n", counter++);
		int i, soma=0, flag=0;
		for(i=0; i<n; i++) {
			int num;
			fscanf(stdin, "%d", &num);
			if (num==soma && flag==0) {
				fprintf(stdout, "%d\n\n", soma); 
				flag=1;
			}
			else {
				soma+=num;
			}
			if (i==n-1 && flag==0) fprintf(stdout, "nao achei\n\n"); 
		}
	}
	return(0);
}


