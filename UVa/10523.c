/* 12204140	0.042 */

/* 大數加法、乘法、次方 + 簡單的 DP... */
/* 要算次方不用直接連乘。拿上一次的結果再乘一次即可 */

#include <stdio.h>
#include <string.h>

typedef struct{
   int n[500];
} bign;

bign dpTable[16][151];   /* 前面 A 後面 N */

/* 印出大數 */
void print(bign *in){
   int i = 499;
   while(i >= 0 && in->n[i] == 0) i--;
   
   if(i < 0) puts("0");
   else{
      printf("%d", in->n[i--]);
      while(i >= 0) printf("%04d", in->n[i--]);
      putchar('\n');
   }
}

/* 大數乘法 */
void mul(bign *ans, bign *in, int mul){
   int carry = 0, i;
   for(i = 0; i < 500; ++i){
      ans->n[i] = in->n[i] * mul + carry;
      carry = ans->n[i] / 10000;
      ans->n[i] %= 10000;
   }
}

/* 大數加法 */
void add(bign *ans, bign *ina, bign *inb){
   int carry = 0, i;
   for(i = 0; i < 500; ++i){
      ans->n[i] = ina->n[i] + inb->n[i] + carry;
      carry = ans->n[i] / 10000;
      ans->n[i] %= 10000;
   }
}

/* 建 DP 表格 */
void dp(){
   int a, n;
   for(a = 1; a <= 15; a++){
      dpTable[a][1].n[0] = a;    /* 初始值 */
      bign powans = dpTable[a][1];
      
      for(n = 2; n <= 150; n++){
         bign ans1 = {{0}};
         mul(&ans1, &powans, a);
         powans = ans1;   /* 記錄起來供下次使用 */
         
         bign ans2 = {{0}};
         mul(&ans2, &ans1, n);
         add(&dpTable[a][n], &ans2, &dpTable[a][n-1]);
      }
   }
}

int main(){
   dp();
   
   int n, a;
   
   while( scanf("%d%d", &n, &a) != EOF ) print(&dpTable[a][n]);

   return 0;
}
