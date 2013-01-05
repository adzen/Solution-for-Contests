/* 11100463 0.008 */
/* 按照題目敘述加解密（使用 ascii code） */
/* RE 的點：題目的規模寫錯，陣列要開大很多才會 AC... OTZ */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* 反轉整個字串 */
void rev(char *in){
   int end = strlen(in)-1, start = 0;
   while(start < end){
      char t = in[end];
      in[end] = in[start];
      in[start] = t;
      start++;
      end--;
   }
}

int main(){
   char text[10000];

   while( gets(text) != NULL ){
      if( isdigit(text[0]) ){
         /* 要解碼... */
         rev(text);
         char ans[30000] = {0};
         int ansi = 0, texti = 0;
         while(text[texti]){
            char tok[10] = {0};
            switch(text[texti]){
               case '1':  /* 解三位數字 */
                  strncpy(tok, text+texti, 3);
                  ans[ansi++] = atoi(tok);
                  texti += 3;
                  break;
               default:  /* 解兩位數字 */
                  strncpy(tok, text+texti, 2);
                  ans[ansi++] = atoi(tok);
                  texti += 2;
                  break;
            }
         }
         puts(ans);
      }else{
         /* 要加密... */
         int i;
         char ans[30000] = {0}, tok[10];
         for(i = 0; text[i]; ++i){
            sprintf(tok, "%d", text[i]);  /* 印出 ascii code */
            strcat(ans, tok);
         }
         rev(ans);
         puts(ans);
      }
   }

   return 0;
}
