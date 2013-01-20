/* 11192468 396K 0MS */
/* Josephus problem in n = 2 */
/* wiki: �� n = 2�A��̰��줸����̥k��Y�i�C */

#include <stdio.h>

int main(){  
   double p;
   while( scanf("%lf", &p) && p > 0.0 ){
      int pi = p;
      pi = ((pi << 1) | 0x1);
      int one = 31;
      while( (pi >> one) % 2 == 0 ) one--;
      pi -= (0x1 << one);
      printf("%d\n", pi);      
   }
   
   return 0;
}
