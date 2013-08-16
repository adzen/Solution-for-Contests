/* 12208759 0.019 */

/* 機率的題目...阿喜高等演算法有出過模擬作業... */

/* 注意看題目中的 2/3 是怎麼算出來的就想通了。 */

#include <stdio.h>

int main(){
   int cow, car, show;
   
   while( scanf("%d%d%d", &cow, &car, &show) != EOF ){
      int door = cow + car;
      double initCow = (double)cow / door;   /* 一開始選到牛的機率 */
      double initCar = (double)car / door;   /* 一開始選到車的機率 */
      int remainCow = cow - show;
      double cowToCar = (double)car / (door-show-1);    /* 牛換到車的機率（分母減一是扣除原本選到的那個門） */
      double carToCar = (double)(car-1) / (door-show-1);  /* 車換到車的機率（分子減一是扣除原本選到的那台車） */
      printf("%.5f\n", initCow * cowToCar + initCar * carToCar);
   }

   return 0;
}
