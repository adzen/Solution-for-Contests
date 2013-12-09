/* 最大的 palindrome n = a*b，然後 a,b 都要是三位數數字... */
/* 列舉三位數數字 a,b (100~999)，再一一檢查是不是 palindrome 即可 */

#include <stdio.h>

/* 檢查是不是 palindrome */
int ispalin(int in){
   int t = in, rev = 0;
   while(t > 0){
      rev = rev * 10 + t % 10;
      t /= 10;
   }
   return (rev == in);
}

int main(){
   int a, b, max = 0;
   for(a = 100; a <= 999; a++){
   for(b = a; b <= 999; b++){     /* a*b 和 b*a 的結果是一樣的 */
      int product = a * b;
      if( ispalin(product) && product > max ) max = product;
   }}
   
   printf("%d\n", max);
   while(1);
   return 0;
}
