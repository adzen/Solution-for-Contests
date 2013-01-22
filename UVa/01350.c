/* 11171202 0.076 */
/* 把 1~20 列出來就看到規律了XD */
/* 長度1的有1個、長度2的有1個、長度3的有2個、長度4的有3個... (費氏數列) */
/* 知道長度後，看和上一個長度最後的編號差多少，剩下的用遞迴生出來XDDD */

#include <stdio.h>

int fib[40] = {1,1,2,3, 5, 8,13};
int sum[40] = {1,2,4,7,12,20,33};

/* start: 剩下的空格起始位置。len: 剩下的空格長度。in: 數列的編號 */
void fill(char *ans, int start, int len, int in){
   if(len == 1){
      ans[start] = '1';
   }else if(len == 2){
      ans[start] = '1';
      ans[start+1] = '0';
   }else{
      /* 看和上一個長度最後的編號差多少 */
      int remain = in - sum[len-2] - 1;
      
      if(remain == 0){  /* 100000... */
         ans[start] = '1';
         int i;
         for(i = start+1; i < start+len; ++i) ans[i] = '0';
      }else{
         /* 用差值 remain 再去找剩餘的長度 */
         int newlen;
         for(newlen = 1; remain > sum[newlen-1]; newlen++);
         
         /* 先把前面的 100000... 填滿 */
         ans[start] = '1';
         int i;
         for(i = start+1; i < start+len-newlen; ++i) ans[i] = '0';
         
         /* 遞迴XD */
         fill(ans, start+len-newlen, newlen, remain);
      }
   }
}

int main(){
   /* 計算好 fib 和 sum */
   int i;
   for(i = 6; i < 40; ++i){
      fib[i] = fib[i-1] + fib[i-2];
      sum[i] = sum[i-1] + fib[i];
   }
   
   int test, in;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &in) ){
      /* 用 sum 看長度是多少 */
      int len;
      for(len = 1; in > sum[len-1]; len++);
      
      char ans[40] = {0};
      fill(ans, 0, len, in);  /* 遞迴方式填滿答案 */
      puts(ans);      
   }

   return 0;
}
