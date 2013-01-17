/* 11146379 0.008 */
/* 先說為啥題目的例子，答案會是 60... */
/* 因為原本每人各做 1/3。
   A 做了 5/9，相當於多做了 2/9。
   B 做了 4/9，相當於多做了 1/9。
   而 C 付的錢只按照「多做的」比例分配，所以答案會是 60... XDD */
/* 想到答案後，剩下都很好寫 */

#include <stdio.h>

int main(){
   int test;
   scanf("%d", &test);
   
   while( test-- > 0 ){
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      
      double a = (double)x / (x+y) - 1.0 / 3.0;  /* A 多做了多少？ */
      double b = (double)y / (x+y) - 1.0 / 3.0;  /* B 多做了多少？ */
      
      if(a <= 0.0){  /* A 沒多做。通通的錢都給 B。 */
         puts("0");
      }else if(b <= 0.0){  /* B 沒多做。通通的錢都給 A。 */
         printf("%d\n", z);
      }else{  /* 剩下直接按照比例分配即可 */
         printf("%.0f\n", a/(a+b)*z);
      }
   }

   return 0;
}
