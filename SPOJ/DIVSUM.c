/* 9309018  Divisor Summation  0.64 2.3M */

/* 求 "proper" divisor 的和 */
/* http://en.wikipedia.org/wiki/Divisor_function */

/* 
TLE 的點：
前面算質數 500000 → 250000
做質因數分解需要 sqrt(in) 的 bound（不須把整個質數表看完）

要小心當輸入 = 1，答案是 0。
*/

#include <stdio.h>
#include <math.h>

int prime[42000], primen;
char notprime[500001];

int main(){
   /* 建立質數表 */
   int i = 2, j;
   while(i <= 250000){
      prime[primen++] = i;
      j = i * 2;
      while(j <= 500000){
         notprime[j] = 1;
         j += i;
      }
      i++;
      while(i <= 250000 && notprime[i]) ++i;
   }

   
   int test, in;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &in) ){
      int ans = 1;
      int temp = in;
      int top = sqrt(in) + 1;    /* bound */
      for(i = 0; i < primen && prime[i] <= top && temp > 1; ++i){
         int mul = 1, sum = 1;
         int count = 0;
         while(temp % prime[i] == 0){   /* 計算次方數 */
            temp /= prime[i];
            count++;
            mul *= prime[i];
            sum += mul;
         }
         ans *= sum;
      }
      if(temp > 1) ans *= (temp+1);   /* 過了 bound，一定是質數 */
      printf("%d\n", ans-in);   /* 記得是 "proper" divisor */
   }

   return 0;
}
