
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

bool myfunction (int i,int j) { return (i > j); }

int main(){

   int T;
   scanf("%d", &T);

   for(int t=1; t<=T; t++){

      int N;
      scanf("%d", &N);
      vector<int> items(N);

      for(int n=0; n<N; n++){
         cin >> items[n];
      }

      sort(items.begin(), items.end(), myfunction);

      int trips = 0;

      for(int i=0; i<N; i++){

         if(items[i] >= 50){
            trips ++;
         }
         else{

            int minLoad = 50 / items[i];
            if( items[i] * minLoad < 50 ){
               minLoad ++;
            }

            if( N - i >= minLoad ){
               trips ++;
               N -= (minLoad - 1);
            }
            else{
               break;
            }
         }
      }

      printf("Case #%d: %d\n", t, trips);
   }

   return 0;
}
