/* 11532086 404K 0MS */
/* 呃...就全部加起來求平均即可... */

#include <stdio.h>

int main(){
   int count = 12;
   double ans = 0.0, in;
   
   while( count-- > 0 && scanf("%lf", &in) ) ans += in;   
   printf("$%.2f\n", ans/12);

   return 0;
}
