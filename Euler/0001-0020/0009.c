/* a+b+c = 1000, a<b<c, a^2 + b^2 = c^2, abc = ? */

/* 列舉 a,b 然後用 c 檢查剩下的條件 */

#include <stdio.h>

int sq[1000];   /* 0~999的平方數 */

int main(){
   int i;
   for(i = 0; i < 1000; i++) sq[i] = i*i;   /* 0~999的平方數 */
   
   int j, find = 0, findi, findj, findk;
   for(i = 1; i < 1000 && !find; i++){
   for(j = i+1; j < 1000; j++){
      int k = 1000 - i - j;    /* 算出 k */
      if(k > j && k*k == sq[i] + sq[j]){
         findi = i;
         findj = j;
         findk = k;
         find = 1;
         break;
      }
   }}
   
   printf("%d %d %d = %d\n", findi, findj, findk, findi*findj*findk);
   while(1);
   return 0;
}
