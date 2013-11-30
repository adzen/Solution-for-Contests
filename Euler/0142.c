/* 找最小的三個整數和 x+y+z，x>y>z>0 使得 x+y, x−y, x+z, x−z, y+z, y−z 都是平方數 */

/* 先列舉出一些平方數。 */

#include <stdio.h>

int sq[1000];   /* 0~999的平方 */
char isq[1000000];   /* 是不是平方數？ */

int main(){
   /* 列舉 0~999 的平方 */
   int i;
   for(i = 0; i < 1000; i++){
      sq[i] = i*i;
      isq[ sq[i] ] = 1;
   }
   
   /* 列舉 a=x+y, b=x+z, c=y+z 並且 x+y > x+z > y+z */
   int a, b, c, min = 0x7fffffff;
   for(a = 3; a < 1000; a++){
   for(b = 2; b < a; b++){
   for(c = 1; c < b; c++){
      int sum = sq[a] + sq[b] + sq[c];   /* 算出 2*(x+y+z) */
      if(sum % 2 || sum >= min) continue;
      sum /= 2;   /* 算出 x+y+z */
      
      /* 算出 x, y, z */
      int x = sum-sq[c];
      int y = sum-sq[b];
      int z = sum-sq[a];
      
      /* 檢查有沒有符合題目條件 */
      if(x > y && y > z && z > 0 && isq[x-y] && isq[x-z] && isq[y-z]){
         printf("(%d,%d,%d)", x,y,z);
         min = sum;
      }
   }}}
   
   printf("%d\n", min);
   while(1);   
}
