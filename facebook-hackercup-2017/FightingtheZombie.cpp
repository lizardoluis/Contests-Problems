
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


double calcProbability(int x, int y, int z, int h){

   double f[x+1][h-z+1];

   for(int d=1; d <= x; d++){
      for(int k=1; k <= h-z; k++){

         double sum = 0.0;

         // printf("%d - %d\n", d, k);

         for(int i=1; i<=y; i++){
            // printf("%d - %d\n", d-1, i);
            if(k-i <= 0){
               sum += 1.0;
            }
            else if(d-1 <= 0){
               sum += 0.0;
            }
            else{
               sum += f[d-1][k-i];
            }
         }

         f[d][k] = sum / y;
      }
   }
   return f[x][h-z];
}


int main(){

   int T;
   scanf("%d", &T);

   for(int t=1; t<=T; t++){

      int H, S;

      scanf("%d %d", &H, &S);

      double maxProbability = 0.0;

      for(int s=0; s<S; s++){
         string str;
         cin >> str;

         int d = str.find_first_of("d");
         int signal = str.find_first_of("-+");

         int x, y, z;
         char sig = str[str.find_first_of("-+")];

         x = atoi( str.substr(0, d).c_str() );

         if(signal != string::npos){
            y = atoi( str.substr(d+1, signal-(d+1)).c_str() );
            z = atoi( str.substr(signal+1, str.size()-1 - (signal)).c_str() );
         }
         else{
            y = atoi( str.substr(d+1, str.size() - (d+1)).c_str() );
            z = 0;
         }
         if(sig == '-')
            z *= -1;

         double prob = calcProbability(x, y, z, H);
         // printf("%f ", prob);
         maxProbability = max(maxProbability, prob);
      }
      printf("Case #%d: %.6f\n", t, maxProbability);
   }

   return 0;
}
