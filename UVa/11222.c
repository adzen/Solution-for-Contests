/* 11146447 0.008 */
/* 給三個同學答對的題目，問解出最多「其他兩人解不出來的題目」的人是？ */
/* 1. 開 problem 陣列 → 把三個人的題目掃一遍，用位元運算紀錄 */
/* 2. 統計 problem 陣列：找出最多的(max)，並且紀錄要印那些題號 */
/* 3. 直接依序看數目，跟 max 一樣的印出即可。 */

#include <stdio.h>

int main(){
   int test, ti;
   scanf("%d", &test);
   
   for(ti = 1; ti <= test; ti++){
      printf("Case #%d:\n", ti);
      
      char problem[10001] = {0};
      
      /* 1. 把三人的作答情況掃一遍 */
      int man, num, temp;
      for(man = 1; man <= 3; ++man){
         scanf("%d", &num);
         for(; num > 0; num--){
            scanf("%d", &temp);
            problem[temp] |= (0x1 << man);  /* (A, B, C) 依序代表是 (0x2, 0x4, 0x8) */
         }
      }
      
      /* 2. 統計 problem 陣列 */
      int only[3][10001] = {0}, max = 0;  /* only[x][0] 代表個數 */
      for(num = 1; num <= 10000; num++){
         if(problem[num] == 0x2){
            only[0][0]++;
            if(only[0][0] > max) max = only[0][0];
            only[0][ only[0][0] ] = num;
         }else if(problem[num] == 0x4){
            only[1][0]++;
            if(only[1][0] > max) max = only[1][0];
            only[1][ only[1][0] ] = num;
         }else if(problem[num] == 0x8){
            only[2][0]++;
            if(only[2][0] > max) max = only[2][0];
            only[2][ only[2][0] ] = num;
         }
      }
      
      /* 3. 找跟 max 一樣的印出即可 */
      for(man = 1; man <= 3; ++man){
         if(only[man-1][0] == max){
            printf("%d %d", man, only[man-1][0]);  /* 先印 編號 跟 題數 */
            for(num = 1; num <= only[man-1][0]; num++) printf(" %d", only[man-1][num]);
            putchar('\n');
         }
      }
   }

   return 0;
}
