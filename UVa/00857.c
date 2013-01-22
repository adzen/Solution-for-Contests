/* 11163720 0.016 */
/* 把最後一個數字 Quantise 成 0, 60, 120, 180, 240, ..., 480 的值 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int p[6];
   char not;
} note;

note notes[3000];

int cmp(note *a, note *b){
   return (a->p[5] - b->p[5]);
} 

void quantisation(int n[]){
   int begin, half;
   for(begin = 0; begin < 480; begin += 60){
      half = begin + 30;
      if(n[4] >= begin && n[4] < half){
         n[4] = begin;
      }else if(n[4] >= half && n[4] < begin+60){
         n[4] = begin+60;
         if(n[4] == 480){   /* 處理進位 */
            n[4] = 0;
            n[3]++;
            if(n[3] == 5){  /* n[3] = {1,2,3,4} */
               n[3] = 1;
               n[2]++;
            }
         }
      }
   }
}

int main(){
   int num, i, j;
   
   while( scanf("%d", &num) && num >= 0 ){
      for(i = 0; i < num; ++i){
         scanf("%d%d%d%d%d", &(notes[i].p[0]), &(notes[i].p[1]), &(notes[i].p[2]),
                             &(notes[i].p[3]), &(notes[i].p[4]) );
         quantisation(notes[i].p);
         /* 計算時間軸 */
         notes[i].p[5] = notes[i].p[2]*100 + notes[i].p[3]*10 + notes[i].p[4]/60;
         notes[i].not = 0;   /* 假設每個都還在，沒被刪掉 */
      }
      
      qsort(notes, num, sizeof(note), cmp);  /* 按照時間排序 */
      
      int ans = num;   /* 剩下來的數目 */
      for(i = 0; i < num; ++i){
         for(j = i; notes[j].p[5] == notes[i].p[5]; j++){
            /* 尋找時間一樣的配對，並刪除 */
            if(notes[j].not == 0 && 
               notes[j].p[1] == notes[i].p[1] && notes[j].p[0] != notes[i].p[0]){
               notes[i].not = notes[j].not = 1;
               ans -= 2;
               break;
            }
         }
      }
      
      printf("%d\n", ans);
      for(i = 0; i < num; ++i){
         if(notes[i].not == 0){
            printf("%d", notes[i].p[0]);
            for(j = 1; j < 5; ++j) printf(" %d", notes[i].p[j]);
            puts("");
         }
      }    
   }
   puts("-1");

   return 0;
}
