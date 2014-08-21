#include <stdio.h>

using namespace std;

int main(){

	int n, m, d, l=0;
	bool ok = true;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &d);
		if(i==0){ continue; }

		if(d-l > m){
			ok = false;
			break;
		}

		l = d;
	}

	if(42195-l > m){
		ok = false;
	}

	if(ok)
		printf("S\n");
	else
		printf("N\n");

	return 0;
}


