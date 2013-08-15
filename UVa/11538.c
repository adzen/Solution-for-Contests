/* 12203996 0.032 */

/* 給長方形的棋盤，問兩隻皇后可以互相攻擊的擺法有幾種？ */

/* 橫的、直的較簡單，斜線則需要考慮棋盤大小。
   另外別忘了兩隻皇后顏色不一樣，所以可以互換。 */
   
/* 起初算斜線時，純粹用迴圈加總。時間 1.928 意外採線成功（時限 2 秒）。
   後來建 table 後，時間壓到 0.032。 */

#include <stdio.h>

long long int table[1000001];

long long int dp(){
   long long int i;
   for(i = 2; i <= 1000000; i++) table[i] = i*(i-1)*2*2 + table[i-1];
   /* 長度為 i 的格子挑兩格：i*(i-1)/2 → 顏色互換再乘二 → 斜線有兩條 → 斜線有兩個走向 */
}

int main(){
   dp();
    
   long long int m, n;
   
   while( scanf("%lld%lld", &m, &n) && m ){
      if(m == 1 && n == 1) puts("0");
      else{
         long long int ans = 0;
         
         ans += m*n*(n-1);  /* 橫的擺法 */
         ans += n*m*(m-1);  /* 直的擺法 */
         
         if(m > n){
            ans += (m-n+1)*n*(n-1)*2;   /* 中間最長的斜線 */
            ans += table[n-1];          /* 兩旁次短的斜線 */
         }else if(m < n){
            ans += (n-m+1)*m*(m-1)*2;   /* 中間最長的斜線 */
            ans += table[m-1];          /* 兩旁次短的斜線 */
         }else{
            ans += (n-m+1)*m*(m-1)*2;   /* 中間最長的斜線 */
            ans += table[n-1];          /* 兩旁次短的斜線 */
         }
         
         printf("%lld\n", ans);
      }
   }

   return 0;
}
