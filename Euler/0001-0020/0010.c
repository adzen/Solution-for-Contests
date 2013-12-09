/* 小於 2 000 000 所有的質數和... */
/* 還是篩法萬能！ */

/* 小心用 int 會溢位！ */

#include <stdio.h>

#define MAXTRY 2000000

char notprime[MAXTRY];

int main(){
   long long int ans = 0;
   int i = 2, j;
   while(i < MAXTRY){
      ans += i;
      j = i * 2;
      while(j < MAXTRY){
         notprime[j] = 1;
         j += i;
      }
      i++;
      while(i < MAXTRY && notprime[i]) i++;
   } 
   
   printf("%lld\n", ans);
   while(1);
   return 0;
}
