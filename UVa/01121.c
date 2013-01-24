/* 11174630 0.036 */
/* ��X���׳̵u�A�S�`�M�i�H >= thres �� substring... */
/* WA ���I�G�O�� substring�A���O subsequence�A�ҥH�n��s�� */
/* TLE ���I�GO(n^2) �| TLE�A�������n O(n) �~�|�L */

#include <stdio.h>
#include <limits.h>

int list[100000];

int main(){
   int num, thres;
   
   while( scanf("%d%d", &num, &thres) != EOF ){
      /* Ū����J�A�ùw���p���`�X */
      int total = 0, i;
      for(i = 0; i < num; ++i){
         scanf("%d", &list[i]);
         total += list[i];
      }
      
      if(total < thres){   /* �`�M < thres�A�ҥH���i�঳���� */
         puts("0");
      }else if(total == thres){  /* �`�M == thres�A�ҥH���״N�O��J������ */
         printf("%d\n", num);
      }else{
         int minlen = INT_MAX, start = 0, end = 0, total = 0;
         /* ���q�Y��A�̵u�S�i�H�ŦX���� */
         for(; total < thres; end++) total += list[end];
         end--;
         int len = end - start;
         if(len < minlen) minlen = len;
         
         while(end < num){
            /* �v�@�������ڪ��Ʀr�A�M��t�@�q��u�S�ŦX���� */
            while(total >= thres) total -= list[start++];
            len = end - (start-1) + 1;
            if(len < minlen) minlen = len;
            
            /* �v�@���k�䩵���A�M��t�@�q��u�S�ŦX���� */
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
