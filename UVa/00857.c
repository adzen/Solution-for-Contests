/* 11163720 0.016 */
/* ��̫�@�ӼƦr Quantise �� 0, 60, 120, 180, 240, ..., 480 ���� */

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
         if(n[4] == 480){   /* �B�z�i�� */
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
         /* �p��ɶ��b */
         notes[i].p[5] = notes[i].p[2]*100 + notes[i].p[3]*10 + notes[i].p[4]/60;
         notes[i].not = 0;   /* ���]�C�ӳ��٦b�A�S�Q�R�� */
      }
      
      qsort(notes, num, sizeof(note), cmp);  /* ���Ӯɶ��Ƨ� */
      
      int ans = num;   /* �ѤU�Ӫ��ƥ� */
      for(i = 0; i < num; ++i){
         for(j = i; notes[j].p[5] == notes[i].p[5]; j++){
            /* �M��ɶ��@�˪��t��A�çR�� */
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
