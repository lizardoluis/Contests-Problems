#include <stdio.h>

using namespace std;

int main()
{
    int n, m, r, maxH=0, maxV=0;
        
    scanf("%d %d", &n, &m);
    
    int vertical[n][m], horizontal[n][m];
    
    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		scanf("%d", &r);
    		if(i==0){
    			vertical[i][j] = r;
    		}
    		else{
    			vertical[i][j] = r + vertical[i-1][j];
    			if(i == n-1 && vertical[i][j] > maxV){
    				maxV = vertical[i][j];
    			}
    		}
    		
    		if(j==0){
    			horizontal[i][j] = r;
    		}
    		else{
    			horizontal[i][j] = r + horizontal[i][j-1];
    			if(j == m-1 && horizontal[i][j] > maxH){
    				maxH = horizontal[i][j];
    			}
    		}   		
    	}
    }
    
    if(maxV > maxH){
    	printf("%d\n", maxV);
    }
    else{
    	printf("%d\n", maxH);
    } 

    return 0;
}
