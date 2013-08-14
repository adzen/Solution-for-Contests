/* 12198162 0.009 */

/* 數字的基底轉換。先轉十進位，再轉到目標的基底即可 */
/* 記得要檢查不合法的數字 */
/* WA：轉完後的結果若為 0 要記得印 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
   int baseA, baseB;
   char numA[100];
   
   while( scanf("%d%d%s", &baseA, &baseB, numA) != EOF ){
      int dig[100], dign = 0, numn = strlen(numA)-1;
      long long int numAinBase10 = 0, pow = 1;
      
      while(numn >= 0){
         dig[dign] = isdigit(numA[numn]) ? (numA[numn]-'0') : (numA[numn]-'A'+10);
         
         /* 檢測不合法的數字 */
         if(dig[dign] >= baseA){
            printf("%s is an illegal base %d number\n", numA, baseA);
            numAinBase10 = -1;
            break;
         }
         
         /* 先轉成十進位 */
         numAinBase10 += pow * dig[dign];
         
         dign++;
         pow *= baseA;
         numn--;
      }
      
      if(numAinBase10 >= 0){
         int Bdig[100] = {0}, Bdign = 0;
         
         /* 沒有考慮 = 0 的情況會 WA */
         if(numAinBase10 == 0){
            printf("%s base %d = 0 base %d\n", numA, baseA, baseB);
            continue;
         }
         
         /* 轉成目標的基底 */
         while(numAinBase10){
            Bdig[Bdign++] = numAinBase10 % baseB;
            numAinBase10 = numAinBase10 / baseB;
         }
         
         /* 印出結果 */
         printf("%s base %d = ", numA, baseA);
         while(--Bdign >= 0){
            if(Bdig[Bdign] >= 10) putchar(Bdig[Bdign]-10+'A');
            else putchar(Bdig[Bdign]+'0');
         }
         printf(" base %d\n", baseB);
      }  
   }

   return 0;
}
