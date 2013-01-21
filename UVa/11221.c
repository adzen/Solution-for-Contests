/* 11163549 0.008 */
/* �N�ˬd�|�Ӥ�V��Ū�k�A���S����쥻�@�˧Y�i */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

char line[20000];
char alpha[20000];
char matrix[150][150];

int ismagic(int dim){
   /* �ˬd�q�k�쥪�O���O */
   int i, j, al = 0;
   for(i = dim-1; i >= 0; --i){
   for(j = dim-1; j >= 0; --j){
      if(matrix[i][j] != alpha[al++]) return 0;
   }}
   
   /* �ˬd�q�W��U�O���O */
   al = 0;
   for(j = 0; j < dim; ++j){
   for(i = 0; i < dim; ++i){
      if(matrix[i][j] != alpha[al++]) return 0;
   }}
   
   /* �ˬd�q�U��W�O���O */
   al = 0;
   for(j = dim-1; j >= 0; --j){
   for(i = dim-1; i >= 0; --i){
      if(matrix[i][j] != alpha[al++]) return 0;
   }}
   
   return 1;
}

int main(){
   int test, ti = 1;
   gets(line);
   sscanf(line, "%d", &test);
   
   while( test-- && gets(line) ){
      printf("Case #%d:\n", ti++);
      
      /* ����^��r����X�� */
      int i, j;
      for(i = j = 0; line[i]; ++i){
         if( isalpha(line[i]) ) alpha[j++] = line[i];
      }
      alpha[j] = 0;
      
      /* �ݪ��ץi���i�H�ꦨ����� */
      int dim = sqrt(j);
      if(dim * dim != j){
         puts("No magic :(");
      }else{
         /* ��^��@��@���i��}�� */
         int al = 0;
         for(i = 0; i < dim; ++i){
         for(j = 0; j < dim; ++j){
            matrix[i][j] = alpha[al++];
         }}
         
         /* �A�ݬO���O magic */
         if( ismagic(dim) ) printf("%d\n", dim);
         else puts("No magic :(");
      }
   }

   return 0;
}
