/* 12198018  0.025 */

/* 給兩個不知基底為何的整數 */
/* 求最小的基底組合，使兩整數的大小一樣 */

/* 就把兩整數使用基底 [2, 36] 各別列出，再暴搜其解即可 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* 把 number 轉換成基底為 base 的整數 */
int baseNum(char *number, int base){
   int dig[100], len = 0, max = 0;
   while(number[len]){
      if( isdigit(number[len]) ){
         dig[len] = number[len]-'0';
      }else{
         dig[len] = number[len]-'A'+10;
      }
      
      if(dig[len] > max) max = dig[len];
      len++;
   }
   
   if(base <= max) return -1;   /* 檢測不合法的轉換 */
   
   int ans = 0, power = 1;
   while(--len >= 0){
      int pos = power * dig[len];
      if(pos < 0) return -1;   /* 檢測溢位 */
      ans += pos;
      if(ans < 0) return -1;   /* 檢測溢位 */
      power *= base;
      if(power < 0) return -1;  /* 檢測溢位 */
   }
   return ans;
}

int main(){
   char numA[100], numB[100];
   int numAinBase[36+1] = {0}, numBinBase[36+1] = {0};
   
   while( scanf("%s%s", numA, numB) != EOF ){
      /* 產生出 numA 和 numB 基底為 base 的整數們 */
      int base;
      for(base = 2; base <= 36; base++){
         numAinBase[base] = baseNum(numA, base);
         numBinBase[base] = baseNum(numB, base);
      }
      
      /* 搜尋答案 */
      int baseA, baseB;
      for(baseA = 2; baseA <= 36; baseA++){
         for(baseB = 2; baseB <= 36; baseB++){
            if(numAinBase[baseA] == numBinBase[baseB] &&
               numAinBase[baseA] != -1 &&
               numBinBase[baseB] != -1){
               printf("%s (base %d) = %s (base %d)\n", numA, baseA, numB, baseB);   
               goto END;
            }
         }
      }
      END:
          
      if(baseA > 36){
         printf("%s is not equal to %s in any base 2..36\n", numA, numB);
      }
   }

   return 0;
}
