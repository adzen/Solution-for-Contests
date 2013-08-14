/* 12199106 0.009 */

/* 找最長的字...很簡單(?) */

/* WA: 其他的字元會被當作空白無視。所以 ASDF123ASDFJKL 是兩個字，不是一個字orz */
/* WA: 不能單純 printf("%s") 而已，要換行orz */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
   char longest[1000] = {0}, current[1000] = {0};
   int max = 0;
   
   while( scanf("%s", current) && strcmp(current, "E-N-D") ){
      int cur = 0, len = 0;
      while(current[cur]){
         if( isalpha(current[cur]) || current[cur] == '-' ){
            len++;
         }else{
            /* 小心是 > 不是 >= */
            if(len > max){
               strncpy(longest, current+cur-len, len);
               max = len;
            }
            len = 0;
         }
         cur++;
      }
      
      /* 收尾也要檢查一下 */
      if(len > max){
         strncpy(longest, current+cur-len, len);
         max = len;
      }
   }
   
   longest[max] = 0;
   while(--max >= 0) longest[max] = tolower(longest[max]);   /* 記得大寫變小寫 */
   puts(longest);   /* 要記得換行 */
   
   return 0;
}
