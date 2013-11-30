/* 求 (1加到100)^2 - 1~100的平方數總和... */
/* 算秒殺題吧... */

#include <stdio.h>

int main(){
   int sum1 = 0, i;
   for(i = 1; i <= 100; ++i) sum1 += i*i;   /* 1~100的平方數總和 */
   
   int sum2 = (100+1)*100/2;   /* 1加到100 */
   sum2 *= sum2;           /* (1加到100)^2 */
   
   printf("%d\n", sum2-sum1);
   while(1);
   return 0;
}
