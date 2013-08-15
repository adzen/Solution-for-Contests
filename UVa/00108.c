/* 12199628 0.069 */

/* 2D Maximum Sum 的題目... */

/* 因為測資很小，直接暴搜即可。 */

/* WA: 計算兩矩形的差時不小心算錯orz */

#include <stdio.h>

int size, map[101][101], sum[101][101];

int main(){
   scanf("%d", &size); 
   
   int i, j;
   for(i = 1; i <= size; ++i){
   for(j = 1; j <= size; ++j){
      scanf("%d", &map[i][j]);
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + map[i][j];   /* 計算總和 */
   }}
   
   int k, l, ans = -2147483647;
   for(i = 1; i <= size; ++i){
   for(j = 1; j <= size; ++j){
   for(k = 0; k <= i; ++k){
   for(l = 0; l <= j; ++l){
      if(k == i && l == j) continue;
      int sub = sum[i][j] - sum[i][l] - sum[k][j] + sum[k][l];   /* 算出小長方形的總和 */
      if(sub > ans) ans = sub;
   }}}}
   
   printf("%d\n", ans);
   return 0;
}
