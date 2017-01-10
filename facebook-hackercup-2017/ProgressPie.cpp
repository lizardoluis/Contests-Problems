
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

# define PI 3.14159265358979323846

using namespace std;

float calcDistance(int x, int y){
   return sqrt( (x-50)*(x-50) + (y-50)*(y-50) );
}

int main(){

   int T;

   scanf("%d", &T);

   for(int t=1; t<=T; t++){
      int P, X, Y;
      bool black = true;

      scanf("%d %d %d", &P, &X, &Y);

      if(calcDistance(X,Y) > 50){
         black = false;
      }
      else if(P == 0){
         black = false;
      }
      else{
         // Angulo do circulo
         float beta = P/100.0 * 360.0;

         int x1 = 0, y1 = 50;
         int x2 = X-50, y2 = Y-50;

         float cosAlfa = (x1*x2 + y1*y2)/(sqrt(x1*x1 + y1*y1)*sqrt(x2*x2 + y2*y2));

         float alfa = 0;
         if(X >= 50){
            alfa = acos(cosAlfa) * 180.0 / PI;
         }
         else{
            alfa = 360 - acos(cosAlfa) * 180.0 / PI;
         }

         // printf("Beta: %f - CosAlfa: %f - Alfa: %f\n", beta, cosAlfa, alfa);

         if(alfa > beta + 0.000001)
            black = false;
      }

      if(black){
         printf("Case #%d: black\n", t);
      }
      else{
         printf("Case #%d: white\n", t);
      }

   }

   return 0;
}
