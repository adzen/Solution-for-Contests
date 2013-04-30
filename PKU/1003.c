/* 11532090 396K 0MS */
/* 就只是一直累加，直到抵達目標長度或超過為止 */

#include <stdio.h>

int main(){
   double f;
   
   while( scanf("%lf", &f) && f >= 0.005 ){
      int ans = 0;
      double sum = 0.0;
      
      while( sum < f ){
         sum += 1.0 / (ans+2);
         ans++;
      }
      
      printf("%d card(s)\n", ans);
   }

   return 0;
}
