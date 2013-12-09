/* 求這 1000 位數字最大連續五個數字的乘積... */
/* 還是秒殺題吧... */

#include <stdio.h>
#include <string.h>

int main(){
   /* 有20行，每行50個數字 */
   char input[2000] = {0}, tok[100];
   int i;
   for(i = 0; i < 20; ++i){
      scanf("%s", tok);
      strcat(input, tok);
   }
   
   int max = 0;
   for(i = 0; i < 1000-5; ++i){
      int product = 1, j;
      for(j = i; j < i+5; j++) product *= input[j]-'0';
      if(product > max) max = product;
   }
   
   printf("%d\n", max);
   while(1);
   return 0;
}
