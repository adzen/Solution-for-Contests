/* 12555206 0.102 */
/* 統計最近鄰居的距離 */

#include <stdio.h>
#include <math.h>

/* 兩棵樹之間的距離^2 */
int distance(int t1[], int t2[]){
   int sum = 0, i;
   for(i = 0; i < 3; ++i) sum += (t1[i]-t2[i]) * (t1[i]-t2[i]);
   return sum;
}

int main(){
   /* 讀取樹的三維座標們 */
   int trees[5001][3], num = 0, i;
   while(1){
      int sum = 0;
      for(i = 0; i < 3; ++i){
         scanf("%d", &trees[num][i]);
         sum += trees[num][i];
      }
      if(sum == 0) break;
      else num++;
   }
   
   /* 算出最近的鄰居距離 */
   int j, nearest[5000];
   char hasNearest[5000] = {0};
   for(i = 0; i < num; ++i){
   for(j = i+1; j < num; ++j){
      int dis2 = distance(trees[i], trees[j]);
      
      if(hasNearest[i] == 0){
         nearest[i] = dis2;
         hasNearest[i] = 1;
      }else if(dis2 < nearest[i]){
         nearest[i] = dis2;
      }
      
      if(hasNearest[j] == 0){
         nearest[j] = dis2;
         hasNearest[j] = 1;
      }else if(dis2 < nearest[j]){
         nearest[j] = dis2;
      }
   }}
   
   /* 統計最近距離 < 10 的樹木們 */
   int ans[10] = {0};
   for(i = 0; i < num; ++i) if(nearest[i] < 100) ans[(int)sqrt(nearest[i])]++;
   
   /* 印出答案 */
   for(i = 0; i < 10; ++i) printf("%4d", ans[i]);
   puts("");

   return 0;
}
