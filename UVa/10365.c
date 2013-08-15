/* 12201768	0.013	*/

/* 給固定數量的積木要排成長方體，然後使包裝紙的用量最小（長方體的表面積最小）。 */

/* 積木的數量不大，直接拆成 a*b*c 的連乘暴搜即可 */

#include <stdio.h>

/* 由長、寬、高計算表面積 */
int faces(int mul[]){
   return (mul[0]*mul[1] + mul[0]*mul[2] + mul[1]*mul[2]) * 2;
}

/* 回溯法暴搜 */
void solve(int *ans, int input, int mul[], int muln){
   if(muln == 0){
      for(mul[0] = 1; mul[0] <= input; mul[0]++){
         if(input % mul[0] == 0) solve(ans, input/mul[0], mul, 1);
      }
   }else if(muln == 1){
      for(mul[1] = mul[0]; mul[1] <= input; mul[1]++){
         if(input % mul[1] == 0) solve(ans, input/mul[1], mul, 2);
      }
   }else{
      if(input >= mul[1]){
         mul[2] = input;
         int sol = faces(mul);   /* 計算答案 */
         if(sol < *ans) *ans = sol;  /* 找出最小的 */
      }
   }
}

int main(){
   int test, in;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &in) ){
      int min = 0x7fffffff, mul[3];
      solve(&min, in, mul, 0);
      printf("%d\n", min);
   }

   return 0;
}
