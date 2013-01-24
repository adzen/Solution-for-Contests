/* 11174630 0.036 */
/* 找出長度最短，又總和可以 >= thres 的 substring... */
/* WA 的點：是找 substring，不是 subsequence，所以要找連續的 */
/* TLE 的點：O(n^2) 會 TLE，網路說要 O(n) 才會過 */

#include <stdio.h>
#include <limits.h>

int list[100000];

int main(){
   int num, thres;
   
   while( scanf("%d%d", &num, &thres) != EOF ){
      /* 讀取輸入，並預先計算總合 */
      int total = 0, i;
      for(i = 0; i < num; ++i){
         scanf("%d", &list[i]);
         total += list[i];
      }
      
      if(total < thres){   /* 總和 < thres，所以不可能有答案 */
         puts("0");
      }else if(total == thres){  /* 總和 == thres，所以答案就是輸入的長度 */
         printf("%d\n", num);
      }else{
         int minlen = INT_MAX, start = 0, end = 0, total = 0;
         /* 先從頭找，最短又可以符合條件的 */
         for(; total < thres; end++) total += list[end];
         end--;
         int len = end - start;
         if(len < minlen) minlen = len;
         
         while(end < num){
            /* 逐一拿掉尾巴的數字，尋找另一段更短又符合條件的 */
            while(total >= thres) total -= list[start++];
            len = end - (start-1) + 1;
            if(len < minlen) minlen = len;
            
            /* 逐一往右邊延伸，尋找另一段更短又符合條件的 */
            while(total < thres && end < num) total += list[++end];
            if(total >= thres){
               len = end - start + 1;
               if(len < minlen) minlen = len;
            }
         }
         printf("%d\n", minlen);  
      }
   }

   return 0;
}
