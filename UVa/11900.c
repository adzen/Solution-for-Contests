/* 11176304 0.000 */
/* �J���e�q���� + ���q����...
   ��n���q�q�p�ƨ�j...�N�q�Y�@����A���줣�欰��N�n */

#include <stdio.h>

int main(){
   int test, ti = 1, egg, num, gm, eggs[100];
   scanf("%d", &test);
   
   while( test-- && scanf("%d%d%d", &egg, &num, &gm) ){
      int i, total = 0;
      for(i = 0; i < egg; ++i) scanf("%d", &eggs[i]);
      for(i = 0; i < egg && total <= gm && i < num; ++i) total += eggs[i];
      printf("Case %d: %d\n", ti++, (total > gm) ? (i-1) : (i) );
   }

   return 0;
}
