/* 11100574 0.008 */
/* 給一堆計算題目的作答情形。請計算總共答對幾題。 */
/* 很簡單的 string parsing...XD */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
   char text[100];
   int count = 0;  /* 答對題數 */
   
   while( scanf("%s", text) != EOF ){
      if( strchr(text, '?') == NULL ){  /* 如果沒有 '?' */
         int a = atoi(text), b, c;  /* a */
         
         char *p = strchr(text, '+');
         if(p != NULL) b = atoi(p+1);  /* b: 加號當然取後面的 */
         p = strchr(text, '-');
         if(p != NULL) b = atoi(p);  /* b: 減號直接取負值XD */
         
         p = strchr(text, '=');
         c = atoi(p+1);   /* c */
         
         /* 直接把兩種問題（加和減）化成同一種（加）XD */
         if(a+b == c) count++;
      }
   }
   
   printf("%d\n", count);
   return 0;
}
