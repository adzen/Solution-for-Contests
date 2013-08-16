/* 12208554 0.112 */

/* 直觀法做會 WA。要用 DP。 */

/* 大塊 = min( 列舉產生兩小塊的切法 + 1 ) */

#include <stdio.h>

int table[301][301];

void dp(){
   table[1][1] = 0;
   
   int i, j;
   for(i = 1; i <= 300; i++){
   for(j = 1; j <= 300; j++){
      if(i == 1 && j == 1) continue;
      
      int k, min = 0x7fffffff;
      for(k = 1; k < i; k++){   /* 橫的切 */
         if(table[k][j] + table[i-k][j] + 1 < min) min = table[k][j] + table[i-k][j] + 1;
      }
      for(k = 1; k < j; k++){   /* 直的切 */
         if(table[i][k] + table[i][j-k] + 1 < min) min = table[i][k] + table[i][j-k] + 1;
      }
      table[i][j] = min;
   }}
}

int main(){
   dp();
   
   int a, b;
   
   while( scanf("%d%d", &a, &b) != EOF ){
      printf("%d\n", table[a][b]);
   }

   return 0;
}
