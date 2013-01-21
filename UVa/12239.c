/* 11163370 0.052 */
/* 問有號碼 0~N，部分的球，刪去兩次抽球的差，可不可能刪完？ */
/* 就雙層迴圈列舉 + 建表即可...很簡單 */

#include <stdio.h>

int main(){
   int number, balln, list[100], i, j;
   
   while( scanf("%d%d", &number, &balln) && number+balln ){
      for(i = 0; i < balln; ++i) scanf("%d", &list[i]);
      
      char used[100] = {0};   /* 0 代表號碼還在，1 代表被刪了 */
      for(i = 0; i < balln; ++i){
      for(j = i; j < balln; ++j){
         int p = list[i] - list[j];
         if(p < 0) p *= -1;
         used[p] = 1;
      }}
      
      char yes = 1;
      for(i = 0; i <= number; ++i){
         if(used[i] == 0){
            yes = 0;
            break;
         }
      }
      
      puts( yes ? "Y" : "N" );
   }

   return 0;
}
