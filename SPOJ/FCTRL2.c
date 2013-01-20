/* 8544704  Small factorials  0.00 1.7M */
/* 1! ~ 100! ¤j¼Æ­¼ªk */

#include <stdio.h>

typedef struct{
   int dig[50];
} bignum;

bignum ans[101];

void mul(bignum *big, bignum *ori, int multi){
   int i;
   for(i = 0; i < 50; ++i){
      big->dig[i] += ori->dig[i] * multi;
      big->dig[i+1] += big->dig[i] / 10000;
      big->dig[i] %= 10000;
   }
}

void print(bignum *input){
   int i = 49;
   while(input->dig[i] == 0) i--;
   printf("%d", input->dig[i--]);
   while(i >= 0) printf("%04d", input->dig[i--]);
   puts("");
}

int main(){
   ans[1].dig[0] = 1;
   
   int i;
   for(i = 2; i <= 100; ++i) mul(&ans[i], &ans[i-1], i);
   
   int test;
   scanf("%d", &test);
   
   while(test-- > 0){
      scanf("%d", &i);
      print(&ans[i]);
   }

   return 0;
}
