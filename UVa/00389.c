/* 12198205 0.065 */

/* 題目跟 00355 很像，所以程式碼直接拿來改... */

/* 差別在於：輸入順序換一下 + 記得向右對齊 + 超過長度要 ERROR */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
   int baseA, baseB;
   char numA[100];
   
   while( scanf("%s%d%d", numA, &baseA, &baseB) != EOF ){   /* 換一下輸入 */
      int dig[100], dign = 0, numn = strlen(numA)-1;
      long long int numAinBase10 = 0, pow = 1;
      
      while(numn >= 0){
         dig[dign] = isdigit(numA[numn]) ? (numA[numn]-'0') : (numA[numn]-'A'+10);
         
         if(dig[dign] >= baseA){
            printf("%s is an illegal base %d number\n", numA, baseA);
            numAinBase10 = -1;
            break;
         }
         
         numAinBase10 += pow * dig[dign];
         
         dign++;
         pow *= baseA;
         numn--;
      }
      
      if(numAinBase10 >= 0){
         int Bdig[100] = {0}, Bdign = 0;
         
         if(numAinBase10 == 0){
            printf("      0\n");
            continue;
         }
         
         while(numAinBase10){
            Bdig[Bdign++] = numAinBase10 % baseB;
            numAinBase10 = numAinBase10 / baseB;
         }
         
         /* 超過長度要記得 ERROR */
         if(Bdign > 7){
            puts("  ERROR");
            continue;
         }
         
         /* 向右對齊 */
         int blank = 7-Bdign;
         while(blank--) putchar(' ');
         
         while(--Bdign >= 0){
            if(Bdig[Bdign] >= 10) putchar(Bdig[Bdign]-10+'A');
            else putchar(Bdig[Bdign]+'0');
         }
         printf("\n");
      }  
   }

   return 0;
}
