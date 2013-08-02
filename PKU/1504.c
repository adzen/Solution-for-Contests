/* 11904639 340K 32MS */
/* 就顛倒後相加再顛倒即可。剛好測試資料不會產生溢位的問題XD */

#include <stdio.h>

/* 傳回顛倒後的結果 */
int reverse(int in){
   int ans = 0;
   while(in){
      ans = ans * 10 + in % 10;
      in /= 10;
   }
   return ans;
}

int main(){
   int test, a, b;
   scanf("%d", &test);
   
   while( test-- && scanf("%d%d", &a, &b) ){
      printf("%d\n", reverse(reverse(a)+reverse(b)) );
   }

   return 0;
}
