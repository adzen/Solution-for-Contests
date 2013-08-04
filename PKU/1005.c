/* 10030934 408K 0MS */
/* 半圓每年會增加 50 的面積，問最快何時會碰到該房子地點？ */
/* 先求距離原點的最短距離，*用該距離求碰到那瞬間半圓的面積，再把該面積除 50 即可 */

#include <stdio.h>
#include <math.h>

int main(){
   const double pi = asin(1) * 2;
   int n, t = 1;
   scanf("%d", &n);
   
   double a, b;
   while( n-- && scanf("%lf%lf", &a, &b) ){
      double area = (a*a+b*b) * pi / 2;
      double ans = ceil(area / 50);
      printf("Property %d: This property will begin eroding in year %.0f.\n", t++, ans);
   }
   printf("END OF OUTPUT.\n");

   return 0;
}
