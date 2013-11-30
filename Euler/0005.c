/* 求可以被 1~20 皆整除的最小正整數... */
/* 相當於求 1~20 的 LCM... */

/* 就對 1~20 做質因數分解，求最高次方，最後乘起來就好了 */

#include <stdio.h>

int primes[8] = {2,3,5,7,11,13,17,19};

int main(){
   int max[8] = {0};   /* 最高次方 */
   
   int i, j;
   for(i = 2; i <= 20; ++i){
      int power[8] = {0}, temp = i;
      for(j = 0; j < 8; j++){
         while(temp > 1 && temp % primes[j] == 0){
            temp /= primes[j];
            power[j]++;
            if(power[j] > max[j]) max[j] = power[j];   /* 有更高的次方，就更新 */
         }
      }
   }
   
   /* 乘起來即可 */    
   long long ans = 1;
   for(i = 0; i < 8; i++){
      while(max[i]){
         ans *= primes[i];
         max[i]--;
      }
   }
   
   printf("%lld\n", ans);
   while(1);
   return 0;
}
