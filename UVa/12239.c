/* 11163370 0.052 */
/* �ݦ����X 0~N�A�������y�A�R�h�⦸��y���t�A�i���i��R���H */
/* �N���h�j��C�| + �ت�Y�i...��²�� */

#include <stdio.h>

int main(){
   int number, balln, list[100], i, j;
   
   while( scanf("%d%d", &number, &balln) && number+balln ){
      for(i = 0; i < balln; ++i) scanf("%d", &list[i]);
      
      char used[100] = {0};   /* 0 �N���X�٦b�A1 �N��Q�R�F */
      for(i = 0; i < balln; ++i){
      for(j = i; j < balln; ++j){
         int p = list[i] - list[j];
         if(p < 0) p *= -1;
         used[p] = 1;
      }}
      
      char yes = 1;
      for(i = 0; i <= number; ++i){
         if(used[i] == 0){
            yes = 0;
            break;
         }
      }
      
      puts( yes ? "Y" : "N" );
   }

   return 0;
}
