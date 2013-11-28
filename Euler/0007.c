#include <stdio.h>

#define MAXTRY 120000

char notprime[MAXTRY];
int primes[15001], primen;

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
   
   printf("%d\n", primes[10000]);
   while(1);
   return 0;
}
