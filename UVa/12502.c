/* 11146379 0.008 */
/* ������ԣ�D�ت��Ҥl�A���׷|�O 60... */
/* �]���쥻�C�H�U�� 1/3�C
   A ���F 5/9�A�۷��h���F 2/9�C
   B ���F 4/9�A�۷��h���F 1/9�C
   �� C �I�����u���ӡu�h�����v��Ҥ��t�A�ҥH���׷|�O 60... XDD */
/* �Q�쵪�׫�A�ѤU���ܦn�g */

#include <stdio.h>

int main(){
   int test;
   scanf("%d", &test);
   
   while( test-- > 0 ){
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      
      double a = (double)x / (x+y) - 1.0 / 3.0;  /* A �h���F�h�֡H */
      double b = (double)y / (x+y) - 1.0 / 3.0;  /* B �h���F�h�֡H */
      
      if(a <= 0.0){  /* A �S�h���C�q�q�������� B�C */
         puts("0");
      }else if(b <= 0.0){  /* B �S�h���C�q�q�������� A�C */
         printf("%d\n", z);
      }else{  /* �ѤU�������Ӥ�Ҥ��t�Y�i */
         printf("%.0f\n", a/(a+b)*z);
      }
   }

   return 0;
}
