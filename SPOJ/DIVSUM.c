/* 9309018  Divisor Summation  0.64 2.3M */

/* �D "proper" divisor ���M */
/* http://en.wikipedia.org/wiki/Divisor_function */

/* 
TLE ���I�G
�e������ 500000 �� 250000
����]�Ƥ��ѻݭn sqrt(in) �� bound�]�������ӽ�ƪ�ݧ��^

�n�p�߷��J = 1�A���׬O 0�C
*/

#include <stdio.h>
#include <math.h>

int prime[42000], primen;
char notprime[500001];

int main(){
   /* �إ߽�ƪ� */
   int i = 2, j;
   while(i <= 250000){
      prime[primen++] = i;
      j = i * 2;
      while(j <= 500000){
         notprime[j] = 1;
         j += i;
      }
      i++;
      while(i <= 250000 && notprime[i]) ++i;
   }

   
   int test, in;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &in) ){
      int ans = 1;
      int temp = in;
      int top = sqrt(in) + 1;    /* bound */
      for(i = 0; i < primen && prime[i] <= top && temp > 1; ++i){
         int mul = 1, sum = 1;
         int count = 0;
         while(temp % prime[i] == 0){   /* �p�⦸��� */
            temp /= prime[i];
            count++;
            mul *= prime[i];
            sum += mul;
         }
         ans *= sum;
      }
      if(temp > 1) ans *= (temp+1);   /* �L�F bound�A�@�w�O��� */
      printf("%d\n", ans-in);   /* �O�o�O "proper" divisor */
   }

   return 0;
}
