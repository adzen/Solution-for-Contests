/* 一個質數可以用比它小、連續的若干個質數相加而成... */
/* 小於 1 000 000 的質數中，哪個質數可以用最多連續的質數相加呢？ */

/* 先篩法找出質數們，然後一一列舉連續的質數和 */

#include <stdio.h>

#define MAXTRY 1000000

char notprime[MAXTRY];
int primes[100000], primen;

int main(){
   /* 還是篩法...老樣子... */
   int i = 2, j;
   while(i < MAXTRY){
      primes[primen++] = i;
      j = i * 2;
      while(j < MAXTRY){
         notprime[j] = 1;
         j += i;
      }
      i++;
      while(i < MAXTRY && notprime[i]) i++;
   }
   
   int maxNum = 0, ans;
   for(i = 0; i < primen; i++){
      int sum = 0, j = i;
      do{
         sum += primes[j];
         if(sum >= MAXTRY) break;   /* 總和超過上限時，就不再列舉了 */
         if(!notprime[sum] && j-i+1 > maxNum){   /* 總和是質數，且質數個數越多的會更新 */
            maxNum = j-i+1;
            ans = sum;
         }
         j++;
      }while(j < primen);
   }

   printf("%d terms, sum = %d\n", maxNum, ans);   /* 注意題目要的是那個質數，不是那一串的質數個數 */
   while(1);
   return 0;
}
