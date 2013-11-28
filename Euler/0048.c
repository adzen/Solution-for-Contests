/* 真的要計算那麼大的數字嗎？不用！題目只要最後的 10 個數字... */

/* 請善用 % 的特性... */

#include <stdio.h>

#define MOD 100000000000LL

int main(){
   long long int ans = 0;
   
   long long int base, power, product;
   for(base = 1; base <= 1000; base++){
      product = 1;
      for(power = 1; power <= base; power++){
         product = product * base % MOD;
      }
      ans = (ans + product) % MOD;
   }
   
   printf("%lld\n", ans);
   while(1);
   return 0;
}
