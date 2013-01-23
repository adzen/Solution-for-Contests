/* 11176463 0.000 */
/* 檢查兩個集合...算還好吧 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(int *a, int *b){
   if(*a > *b) return 1;
   if(*a < *b) return -1;
   return 0;
}

int equal(int a[], int an, int b[], int bn){
   if(an != bn) return 0;
   int i;
   for(i = 0; i < an; ++i) if(a[i] != b[i]) return 0;
   return 1;
}

int main(){
   char line[10000];
   int a[1000], b[1000], an, bn;
   
   while( gets(line) != NULL ){
      /* 讀取集合 A */
      char *ptr = strtok(line, " ");
      an = 0;
      while(ptr != NULL){
         a[an++] = atoi(ptr);
         ptr = strtok(NULL, " ");
      }
      
      /* 讀取集合 B */
      gets(line);
      ptr = strtok(line, " ");
      bn = 0;
      while(ptr != NULL){
         b[bn++] = atoi(ptr);
         ptr = strtok(NULL, " ");
      }
      
      /* 兩集合皆從小排到大 */
      qsort(a, an, sizeof(int), cmp);
      qsort(b, bn, sizeof(int), cmp);
      
      /* 先針對空集合的特例做處理 */
      if(an == 0 && bn == 0){
         puts("A equals B");
      }else if(an == 0){
         puts("A is a proper subset of B");
      }else if(bn == 0){
         puts("B is a proper subset of A");
      }else{
         if( equal(a, an, b, bn) ) puts("A equals B");  /* 兩集合一樣 */
         else{
            /* 紀錄 NOT A 和 NOT B */
            int nota[1000], notan = 0;
            int notb[1000], notbn = 0;
            
            int i = 0, j = 0;
            while(i < an && j < bn){
               if(a[i] == b[j]){    /* 號碼一樣大，代表兩邊皆有，無視 */
                  i++;
                  j++;
               }else if(a[i] > b[j]){    /* 代表 b[j] 為 NOT A */
                  nota[notan++] = b[j];
                  j++; 
               }else{
                  notb[notbn++] = a[i];    /* 代表 a[i] 為 NOT B */
                  i++; 
               }
            }
            while(i < an){   /* A 多出來的，一定是 NOT B */
               notb[notbn++] = a[i];
               i++;
            }
            while(j < bn){   /* B 多出來的，一定是 NOT A */
               nota[notan++] = b[j];
               j++;
            }
            
            /* 最後依照 notan 和 notbn 做出判斷 */
            if(notan == 0) puts("B is a proper subset of A");
            else if(notbn == 0) puts("A is a proper subset of B");
            else if(notan == bn && notbn == an) puts("A and B are disjoint");
            else puts("I'm confused!");
         }
      }
   }

   return 0;
}
