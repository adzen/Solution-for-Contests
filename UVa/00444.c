/* 11100463 0.008 */
/* �����D�رԭz�[�ѱK�]�ϥ� ascii code�^ */
/* RE ���I�G�D�ت��W�Ҽg���A�}�C�n�}�j�ܦh�~�| AC... OTZ */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* �����Ӧr�� */
void rev(char *in){
   int end = strlen(in)-1, start = 0;
   while(start < end){
      char t = in[end];
      in[end] = in[start];
      in[start] = t;
      start++;
      end--;
   }
}

int main(){
   char text[10000];

   while( gets(text) != NULL ){
      if( isdigit(text[0]) ){
         /* �n�ѽX... */
         rev(text);
         char ans[30000] = {0};
         int ansi = 0, texti = 0;
         while(text[texti]){
            char tok[10] = {0};
            switch(text[texti]){
               case '1':  /* �ѤT��Ʀr */
                  strncpy(tok, text+texti, 3);
                  ans[ansi++] = atoi(tok);
                  texti += 3;
                  break;
               default:  /* �Ѩ��Ʀr */
                  strncpy(tok, text+texti, 2);
                  ans[ansi++] = atoi(tok);
                  texti += 2;
                  break;
            }
         }
         puts(ans);
      }else{
         /* �n�[�K... */
         int i;
         char ans[30000] = {0}, tok[10];
         for(i = 0; text[i]; ++i){
            sprintf(tok, "%d", text[i]);  /* �L�X ascii code */
            strcat(ans, tok);
         }
         rev(ans);
         puts(ans);
      }
   }

   return 0;
}
