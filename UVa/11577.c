/* 11176579 0.016 */
/* �N�p��C���r���̱`�X�{���^��r���]�����j�p�g�^�O����...
   ��²��XDDDD */

#include <stdio.h>
#include <ctype.h>

int main(){
   int test;
   char line[300];
   gets(line);
   sscanf(line, "%d", &test);
   
   while( test-- && gets(line) ){
      int max = 0, fre[26] = {0}, i;
      for(i = 0; line[i]; ++i){
         if( isupper(line[i]) ) fre[ line[i]-'A' ]++;
         else if( islower(line[i]) ) fre[ line[i]-'a' ]++;
      }
      
      for(i = 0; i < 26; ++i) if(fre[i] > max) max = fre[i];
      for(i = 0; i < 26; ++i) if(fre[i] == max) putchar(i+'a');
      putchar('\n');
   }

   return 0;
}
