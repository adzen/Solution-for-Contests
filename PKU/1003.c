/* 11532090 396K 0MS */
/* �N�u�O�@���֥[�A�����F�ؼЪ��שζW�L���� */

#include <stdio.h>

int main(){
   double f;
   
   while( scanf("%lf", &f) && f >= 0.005 ){
      int ans = 0;
      double sum = 0.0;
      
      while( sum < f ){
         sum += 1.0 / (ans+2);
         ans++;
      }
      
      printf("%d card(s)\n", ans);
   }

   return 0;
}
