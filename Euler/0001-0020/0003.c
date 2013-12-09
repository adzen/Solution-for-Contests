/* 求 600851475143 的最大質因數... */
/* 先篩法，再質因數分解 */

#include <stdio.h>

/* sqrt(600851475143) 約等於 775146.1 */
#define TOP 775200

char notprime[TOP];
int primes[63000], primen;

int main(){
   /* 老樣子的篩法... */
   int i = 2, j;
   while(i < TOP){
      primes[primen++] = i;
      j = i * 2;
      while(j < TOP){
         notprime[j] = 1;
         j += i;
      }
      i++;
      while(i < TOP && notprime[i]) i++;
   }
   
   /* 質因數分解 */
   long long input = 600851475143LL, max = 0;
   for(i = 0; i < primen && input > 1; ++i){
      if(input % primes[i] == 0){
         max = primes[i];
         do{
            input /= primes[i];
         }while(input % primes[i] == 0);
      }
   }
   if(input > 1) max = input;
   
   printf("%lld\n", max);
   while(1);
   return 0;
}
