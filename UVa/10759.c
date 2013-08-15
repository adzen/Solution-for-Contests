/* 12206415 0.012 */

/* 機率組合 + DP 的題目 */
/* 問 num 個骰子，「至少」丟出點數和為 sum 的機率是多少？ */

/* 起初真的用分數寫。發現分母會溢位。
   只好學 Morris 大神的方式，DP 表格只記錄分子<(_ _)> */
   
/* 這題的 DP 表：紀錄「num 個骰子丟出點數和為 sum」的機率 */   

#include <stdio.h>

unsigned long long int dpTable[25][145], total[25];   /* 骰子個數，點數總和 */

/* 就最大公因數咩 */
unsigned long long int gcd(unsigned long long int a, unsigned long long int b){
   unsigned long long int c = a % b;
   while(c){
      a = b;
      b = c;
      c = a % b;
   }
   return b;
}

/* 填滿 DP 表格 */
void dp(){
   /* 初始條件 */
   int sum;
   for(sum = 1; sum <= 6; sum++) dpTable[1][sum] = 1;
   total[1] = 6;
   
   /* 開始填... */
   int num;
   for(num = 2; num < 25; num++){
      total[num] = total[num-1] * 6;    /* 分母 */
      for(sum = num; sum <= num*6; sum++){
         int point;
         for(point = 1; point <= 6; point++){
            if(sum-point >= 0) dpTable[num][sum] += dpTable[num-1][sum-point];
         }
      }
   }
}

int main(){
   dp();
   
   int num, sum;

   while( scanf("%d%d", &num, &sum) && num ){
      /* 兩種簡單的情況先列出來 */
      if(num * 6 < sum){
         puts("0");
      }else if(num >= sum){
         puts("1");
      }else{
         unsigned long long int ans = 0, t = total[num];
         
         /* 累加分子 */
         int thissum;
         for(thissum = sum; thissum <= num * 6; thissum++){
            ans += dpTable[num][thissum];
         }
         
         /* 化成最簡分數 */
         unsigned long long int g = gcd(ans, t);
         ans /= g;
         t /= g;
         
         printf("%llu/%llu\n", ans, t);
      }
   }

   return 0;
}
