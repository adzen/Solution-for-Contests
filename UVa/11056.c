/* 12205268 0.016 */

/* 排序的問題，很簡單。 */

/* 先按時間排序。時間一樣的按照名字排序（小心是 case-insensitive）。
   最後在倆倆輸出即可。 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   char name[25];
   int time;
} car;

car pilots[100];

int cmp(const car *a, const car *b){
   if(a->time < b->time) return -1;
   if(a->time > b->time) return 1;
   
   /* 名字不分大小寫的比較 */
   char renameA[25], renameB[25];
   strcpy(renameA, a->name);
   strcpy(renameB, b->name);
   int i;
   for(i = 0; renameA[i]; i++) renameA[i] = tolower( renameA[i] );
   for(i = 0; renameB[i]; i++) renameB[i] = tolower( renameB[i] );
   return strcmp(renameA, renameB);
}

int main(){
   int num;
   while( scanf("%d", &num) != EOF ){
      int i;
      for(i = 0; i < num; ++i){
         int min, sec, ms;
         scanf("%s : %d min %d sec %d ms", &pilots[i].name, &min, &sec, &ms);
         pilots[i].time = min * 60*1000 + sec * 1000 + ms;    /* 把時間的三個欄位計算成一個 */
      }
      
      qsort(pilots, num, sizeof(car), cmp);
      
      /* 倆倆輸出 */
      int row = 1;
      for(i = 0; i < num; ++i){
         if(i % 2 == 0){
            printf("Row %d\n", row++);
         }
         printf("%s\n", &pilots[i].name);
      }
      puts("");   /* 記得要空白行 */
   }

   return 0;
}
