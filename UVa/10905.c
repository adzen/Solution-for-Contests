/* 12210579 0.098 */

/* 問要怎麼串才會數字最大？ */

/* 起初用字元比較方式 → WA
   後來想到就兩兩串起來比較大小即可 → 但仍是 WA 
   才發現陣列開不夠大 */

#include <stdio.h>
#include <stdlib.h>

int cmp(const char *a, const char *b){
   char t1[500];  /* 先 A 再 B */
   strcpy(t1, a);
   strcat(t1, b);
   
   char t2[500];  /* 先 B 再 A */
   strcpy(t2, b);
   strcat(t2, a);
   
   return strcmp(t2, t1);
}

int main(){
   int num;
   char list[500][500];
   
   while( scanf("%d", &num) && num ){
      int i;
      for(i = 0; i < num; ++i) scanf("%s", list+i);
      qsort(list, num, sizeof(char[500]), cmp);
      for(i = 0; i < num; ++i) printf("%s", list+i);
      putchar('\n');
   }

   return 0;
}
