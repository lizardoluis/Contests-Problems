//Resolvido mas copiado, to

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

#include <stdio.h>

int main(){
   int N,L, *i, *j, *_L, nMax;
   int livres[100000];

   while(1){
      scanf("%i %i", &N, &L);

      if(!(L || N))
         return 0;

      i = livres;

      for(nMax = 0; nMax < L;++nMax){
         scanf("%i", i); ++i;
      }
      nMax = 0;
      _L = livres + L;
      j = livres;

      for(i = livres; i < _L; ++i){

         while(*(j+1) < *i+N){
            if(++j >= _L){ i = _L; break;
         }

         if(j - i > nMax){
            nMax = j - i;

            if(nMax == N){
               i = _L; break;
            }
         }

         if(j >= _L){
            // para sair do for
            i = _L; break;
         }
      }
   }
   printf("%i\n",N - nMax - 1);
}
}

// if (lab.empty() or lab.top() != prog_it)
//   lab.push(prog_it);
//if (*mem_it == 0){
//   lab.pop();
//int k = 1;
//while(k != 0) {
//   ++prog_it;
//   if ((*prog_it) == ']') k--;
//   else if ((*prog_it) == '[') k++;
//}



