/* 12549853 0.015 */

/* 下一個是 palindromic 的時間是哪個？ */
/* 把時間編碼成整數，直接建表即可。 */
/* 注意 23:59 的答案是 00:00！ */

#include <stdio.h>

/* 檢查是否 palindromic */
int ispalin(int in){
   int rev = 0, t = in;
   while(t > 0){
      rev = rev * 10 + t % 10;
      t /= 10;
   }
   return (in == rev);
}

int main(){
   /* 先找出所有符合的時間們。這裡陣列故意開得比較大，讓最大的答案下一個剛好是 00:00 */
   int palins[100] = {0}, psize = 0;
   
   int hour, min;
   for(hour = 0; hour < 24; hour++){
   for(min = 0; min < 60; min++){
      int time = hour * 100 + min;
      if( ispalin(time) ) palins[psize++] = time;
   }}

   /* 為答案建表 */
   int ans[24][60], cur = 0;
   for(hour = 0; hour < 24; hour++){
   for(min = 0; min < 60; min++){
      int time = hour * 100 + min;
      if(time == palins[cur]) cur++;
      ans[hour][min] = palins[cur];
   }}
   
   /* 讀取輸入，直接查表印出答案 */
   scanf("%d", &psize);
   while(psize-- > 0){
      scanf("%d:%d", &hour, &min);
      printf("%02d:%02d\n", ans[hour][min] / 100, ans[hour][min] % 100);
   }

   return 0;
}
