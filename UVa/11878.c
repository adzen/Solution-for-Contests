/* 11100574 0.008 */
/* ���@��p���D�ت��@�����ΡC�Эp���`�@����X�D�C */
/* ��²�檺 string parsing...XD */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
   char text[100];
   int count = 0;  /* �����D�� */
   
   while( scanf("%s", text) != EOF ){
      if( strchr(text, '?') == NULL ){  /* �p�G�S�� '?' */
         int a = atoi(text), b, c;  /* a */
         
         char *p = strchr(text, '+');
         if(p != NULL) b = atoi(p+1);  /* b: �[����M���᭱�� */
         p = strchr(text, '-');
         if(p != NULL) b = atoi(p);  /* b: ��������t��XD */
         
         p = strchr(text, '=');
         c = atoi(p+1);   /* c */
         
         /* �������ذ��D�]�[�M��^�Ʀ��P�@�ء]�[�^XD */
         if(a+b == c) count++;
      }
   }
   
   printf("%d\n", count);
   return 0;
}
