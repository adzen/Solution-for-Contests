/* 11163510 0.008 */
/* ����D�C���Ȫ��Ӽ� ��h �s���Ӽ� �Y�iXD */

#include <stdio.h>

int main(){
   int n, ti = 1;
   
   while( scanf("%d", &n) && n ){
      int zero = 0, pos = 0, i, temp;
      for(i = 0; i < n; ++i){
         scanf("%d", &temp);
         if(temp == 0) zero++;
         else pos++;
      }
      
      printf("Case %d: %d\n", ti++, pos-zero);
   } 

   return 0;
}
