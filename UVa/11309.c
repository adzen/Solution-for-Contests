#include <stdio.h>

int ispalin(int in){
   int rev = 0, t = in;
   while(t > 0){
      rev = rev * 10 + t % 10;
      t /= 10;
   }
   return (in == rev);
}

int main(){
   int palins[100] = {0}, psize = 0;
   
   int hour, min;
   for(hour = 0; hour < 24; hour++){
   for(min = 0; min < 60; min++){
      int time = hour * 100 + min;
      if( ispalin(time) ) palins[psize++] = time;
   }}

   int ans[24][60], cur = 0;
   for(hour = 0; hour < 24; hour++){
   for(min = 0; min < 60; min++){
      int time = hour * 100 + min;
      if(time == palins[cur]) cur++;
      ans[hour][min] = palins[cur];
   }}
   
   scanf("%d", &psize);
   while(psize-- > 0){
      scanf("%d:%d", &hour, &min);
      printf("%02d:%02d\n", ans[hour][min] / 100, ans[hour][min] % 100);
   }

   return 0;
}
