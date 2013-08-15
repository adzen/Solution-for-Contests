/* 12199399 0.082	*/

/* 一維最大和 的題目... */

/* 稍微想了一下，總算自己能想出這個演算法了XD */

#include <stdio.h>

int n, input[10000], sum[10000];

int maxSum1D(){
   if(n == 1) return input[0];
   
   int maxSum = input[0], min = 0;
   sum[0] = input[0];
   
   int i;
   for(i = 1; i < n; i++){
      if(sum[i-1] < min) min = sum[i-1];   /* 在這之前最小的和（可能是負數） */
      sum[i] = sum[i-1] + input[i];
      if(sum[i]-min > maxSum) maxSum = sum[i]-min;   /* 計算最大和(DP) */
   }
   return maxSum;
}

int main(){
   while( scanf("%d", &n) && n ){
      int i;
      for(i = 0; i < n; i++) scanf("%d", &input[i]);
      
      int ans = maxSum1D();
      if(ans <= 0) puts("Losing streak.");
      else printf("The maximum winning streak is %d.\n", ans);
   }

   return 0;
}
