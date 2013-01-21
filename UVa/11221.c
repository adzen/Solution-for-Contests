/* 11163549 0.008 */
/* 就檢查四個方向的讀法，有沒有跟原本一樣即可 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

char line[20000];
char alpha[20000];
char matrix[150][150];

int ismagic(int dim){
   /* 檢查從右到左是不是 */
   int i, j, al = 0;
   for(i = dim-1; i >= 0; --i){
   for(j = dim-1; j >= 0; --j){
      if(matrix[i][j] != alpha[al++]) return 0;
   }}
   
   /* 檢查從上到下是不是 */
   al = 0;
   for(j = 0; j < dim; ++j){
   for(i = 0; i < dim; ++i){
      if(matrix[i][j] != alpha[al++]) return 0;
   }}
   
   /* 檢查從下到上是不是 */
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
      
      /* 先把英文字母抽出來 */
      int i, j;
      for(i = j = 0; line[i]; ++i){
         if( isalpha(line[i]) ) alpha[j++] = line[i];
      }
      alpha[j] = 0;
      
      /* 看長度可不可以湊成平方數 */
      int dim = sqrt(j);
      if(dim * dim != j){
         puts("No magic :(");
      }else{
         /* 把英文一行一行塞進方陣裡 */
         int al = 0;
         for(i = 0; i < dim; ++i){
         for(j = 0; j < dim; ++j){
            matrix[i][j] = alpha[al++];
         }}
         
         /* 再看是不是 magic */
         if( ismagic(dim) ) printf("%d\n", dim);
         else puts("No magic :(");
      }
   }

   return 0;
}
