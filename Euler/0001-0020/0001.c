/* 小於 1000 且是 三的倍數 或 五的倍數 自然數總和... */
/* 可以算是秒殺題吧... */

#include <stdio.h>

int main(){
   int sum = 0, i;
   for(i = 1; i < 1000; i++) if(i % 3 == 0 || i % 5 == 0) sum += i;
   printf("%d\n", sum);
   while(1);
   return 0;
}
