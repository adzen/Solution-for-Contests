/* 12206084 0.015 */

/* 為空格填上字母，使和其相鄰的四格不一樣。 */

/* 看起來很難，其實只要照 row major 順序填就好（題目的第 2. 點）
   不需要嘗試錯誤。 */

#include <stdio.h>

/* 檢查相鄰四格已經填了哪些字母 */
void check(char used[], char map[][20], int size, int i, int j){
   if(i-1 >= 0 && map[i-1][j] != '.') used[ map[i-1][j]-'A' ] = 1;
   if(i+1 < size && map[i+1][j] != '.') used[ map[i+1][j]-'A' ] = 1;
   if(j-1 >= 0 && map[i][j-1] != '.') used[ map[i][j-1]-'A' ] = 1;
   if(j+1 < size && map[i][j+1] != '.') used[ map[i][j+1]-'A' ] = 1;
}

int main(){
   int test, size, ti = 1;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &size) ){
      printf("Case %d:\n", ti++);    
          
      char map[20][20] = {0};
      int i;
      for(i = 0; i < size; ++i) scanf("%s", map+i);
      
      int j;
      for(i = 0; i < size; ++i){
      for(j = 0; j < size; ++j){
         if(map[i][j] != '.') continue;
         
         /* 檢查相鄰四格 */
         char isUsed[26] = {0};
         check(isUsed, map, size, i, j);
         
         /* 從中挑選最小又沒用過的字母填上即可 */
         int k;
         for(k = 0; k < 26; ++k){
            if(isUsed[k] == 0){
               map[i][j] = 'A' + k;
               break;
            }
         }
      }}
      
      for(i = 0; i < size; ++i) puts(map+i);
   }

   return 0;
}
