#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTRY 1000000

char notprime[MAXTRY];
int primes[80000], primen;

int shift(int in, int len){
   char str[100] = {0};
   sprintf(str, "%0*d", len, in);
   str[len] = str[0];
   str[0] = 0;
   return atoi(str+1);
}

int main(){
   notprime[0] = notprime[1] = 1;
   
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
   
   int count = 0;
   for(i = 0; i < primen; ++i){
      char str[100] = {0};
      sprintf(str, "%d", primes[i]);
      int len = strlen(str);
      int rot = shift(primes[i], len);
      do{
         if(notprime[rot]) break; 
         rot = shift(rot, len);
      }while(rot != primes[i]);
      
      if(rot == primes[i]) count++;
   }
   
   printf("%d\n", count);
   while(1);
   return 0;
}
