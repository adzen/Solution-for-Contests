/* 11170645 0.008 */
/* �N�Ө�W�h�@���ഫ�A�����ӦP�ˬ���C��n�d�Ҥ��� -1 ���S�ҡC */

#include <stdio.h>

typedef struct{
   char m[4][4];
} grid;

/* �ˬd�O�_�����O 0 */
int iszero(grid g){
   int i, j;
   for(i = 0; i < 3; ++i){
   for(j = 0; j < 3; ++j){
      if(g.m[i][j] != '0') return 0;
   }}
   return 1;
}

int main(){
   int test;
   scanf("%d", &test);
   
   while(test--){
      grid ori, next;
      
      int i;
      for(i = 0; i < 3; ++i) scanf("%s", ori.m[i]);
      
      /* ���� 0 �O�S�� */
      if( iszero(ori) ){
         puts("-1");
         continue;
      }
      
      int count = 0;
      while(1){
         /* ���ഫ�s�� next */
         int j;
         for(i = 0; i < 3; ++i){
         for(j = 0; j < 3; ++j){
            int ans = 0;
            if(i-1 >= 0 && ori.m[i-1][j] == '1') ans++;
            if(i+1 <  3 && ori.m[i+1][j] == '1') ans++;
            if(j-1 >= 0 && ori.m[i][j-1] == '1') ans++;
            if(j+1 <  3 && ori.m[i][j+1] == '1') ans++;
            next.m[i][j] = ans % 2 + '0';
         }}
         
         /* �ˬd�O�_��Ӥ@�� */
         int conti = 0;
         for(i = 0; i < 3; ++i){
         for(j = 0; j < 3; ++j){
            if(ori.m[i][j] != next.m[i][j]) conti = 1;
         }}
         
         if( !conti ) break;
         count++;
         ori = next;
      }
      
      printf("%d\n", count-1);
   }

   return 0;
}
