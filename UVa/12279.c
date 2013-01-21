/* 11163510 0.008 */
/* 秒殺題。正值的個數 減去 零的個數 即可XD */

#include <stdio.h>

int main(){
   int n, ti = 1;
   
   while( scanf("%d", &n) && n ){
      int zero = 0, pos = 0, i, temp;
      for(i = 0; i < n; ++i){
         scanf("%d", &temp);
         if(temp == 0) zero++;
         else pos++;
      }
      
      printf("Case %d: %d\n", ti++, pos-zero);
   } 

   return 0;
}
