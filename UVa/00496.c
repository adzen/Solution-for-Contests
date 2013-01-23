/* 11176463 0.000 */
/* �ˬd��Ӷ��X...���٦n�a */

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
      /* Ū�����X A */
      char *ptr = strtok(line, " ");
      an = 0;
      while(ptr != NULL){
         a[an++] = atoi(ptr);
         ptr = strtok(NULL, " ");
      }
      
      /* Ū�����X B */
      gets(line);
      ptr = strtok(line, " ");
      bn = 0;
      while(ptr != NULL){
         b[bn++] = atoi(ptr);
         ptr = strtok(NULL, " ");
      }
      
      /* �ⶰ�X�ұq�p�ƨ�j */
      qsort(a, an, sizeof(int), cmp);
      qsort(b, bn, sizeof(int), cmp);
      
      /* ���w��Ŷ��X���S�Ұ��B�z */
      if(an == 0 && bn == 0){
         puts("A equals B");
      }else if(an == 0){
         puts("A is a proper subset of B");
      }else if(bn == 0){
         puts("B is a proper subset of A");
      }else{
         if( equal(a, an, b, bn) ) puts("A equals B");  /* �ⶰ�X�@�� */
         else{
            /* ���� NOT A �M NOT B */
            int nota[1000], notan = 0;
            int notb[1000], notbn = 0;
            
            int i = 0, j = 0;
            while(i < an && j < bn){
               if(a[i] == b[j]){    /* ���X�@�ˤj�A�N�����Ҧ��A�L�� */
                  i++;
                  j++;
               }else if(a[i] > b[j]){    /* �N�� b[j] �� NOT A */
                  nota[notan++] = b[j];
                  j++; 
               }else{
                  notb[notbn++] = a[i];    /* �N�� a[i] �� NOT B */
                  i++; 
               }
            }
            while(i < an){   /* A �h�X�Ӫ��A�@�w�O NOT B */
               notb[notbn++] = a[i];
               i++;
            }
            while(j < bn){   /* B �h�X�Ӫ��A�@�w�O NOT A */
               nota[notan++] = b[j];
               j++;
            }
            
            /* �̫�̷� notan �M notbn ���X�P�_ */
            if(notan == 0) puts("B is a proper subset of A");
            else if(notbn == 0) puts("A is a proper subset of B");
            else if(notan == bn && notbn == an) puts("A and B are disjoint");
            else puts("I'm confused!");
         }
      }
   }

   return 0;
}
