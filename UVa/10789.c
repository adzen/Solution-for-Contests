/* 12201652 0.012 */

/* 給一串字母，問出現頻率是質數的字母有哪些。 */

/* 新手等級的題目吧...orz */

#include <stdio.h>
#include <ctype.h>

int main(){
   /* 建質數表 */
   int notPrime[3000] = {1,1}, i = 2, j;
   while(i < 3000){
      j = i * 2;
      while(j < 3000){
         notPrime[j] = 1;
         j += i;
      }
      i++;
      while(i < 3000 && notPrime[i]) i++;
   }

   int test, ti = 1;
   scanf("%d", &test);
   
   char input[3000];
   while( test-- && scanf("%s", input) ){
      /* 計算出現頻率 */
      int fre[256] = {0};
      for(i = 0; input[i]; ++i) fre[ input[i] ]++;
      
      printf("Case %d: ", ti++);
      int outputed = 0;
      for(i = 32; i < 256; i++){
         if( isalnum(i) && notPrime[ fre[i] ] == 0){
            putchar(i);
            outputed = 1;
         }
      }
      if(outputed == 0) puts("empty");
      else putchar('\n');
   }

   return 0;
}
