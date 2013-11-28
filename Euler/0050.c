#include <stdio.h>

#define MAXTRY 1000000

char notprime[MAXTRY];
int primes[100000], primen;

int main(){
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
         if(sum >= MAXTRY) break;
         if(!notprime[sum] && j-i+1 > maxNum){
            maxNum = j-i+1;
            ans = sum;
         }
         j++;
      }while(j < primen);
   }

   printf("%d terms, sum = %d\n", maxNum, ans);
   while(1);
   return 0;
}
