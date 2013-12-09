/* 小於四百萬的偶數 fib 總和... */
/* 也算是秒殺題吧... */

#include <stdio.h>

int main(){
   int sum = 2;
   int cur = 3, a = 2, b = 1;    /* cur = a + b */
   while(cur <= 4000000){
      b = a;
      a = cur;
      cur = a + b;
      if(cur % 2 == 0) sum += cur;
   }
   
   printf("%d\n", sum);
   while(1);
   return 0;
}
