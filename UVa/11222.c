/* 11146447 0.008 */
/* ���T�ӦP�ǵ��諸�D�ءA�ݸѥX�̦h�u��L��H�Ѥ��X�Ӫ��D�ءv���H�O�H */
/* 1. �} problem �}�C �� ��T�ӤH���D�ر��@�M�A�Φ줸�B����� */
/* 2. �έp problem �}�C�G��X�̦h��(max)�A�åB�����n�L�����D�� */
/* 3. �����̧ǬݼƥءA�� max �@�˪��L�X�Y�i�C */

#include <stdio.h>

int main(){
   int test, ti;
   scanf("%d", &test);
   
   for(ti = 1; ti <= test; ti++){
      printf("Case #%d:\n", ti);
      
      char problem[10001] = {0};
      
      /* 1. ��T�H���@�����p���@�M */
      int man, num, temp;
      for(man = 1; man <= 3; ++man){
         scanf("%d", &num);
         for(; num > 0; num--){
            scanf("%d", &temp);
            problem[temp] |= (0x1 << man);  /* (A, B, C) �̧ǥN��O (0x2, 0x4, 0x8) */
         }
      }
      
      /* 2. �έp problem �}�C */
      int only[3][10001] = {0}, max = 0;  /* only[x][0] �N��Ӽ� */
      for(num = 1; num <= 10000; num++){
         if(problem[num] == 0x2){
            only[0][0]++;
            if(only[0][0] > max) max = only[0][0];
            only[0][ only[0][0] ] = num;
         }else if(problem[num] == 0x4){
            only[1][0]++;
            if(only[1][0] > max) max = only[1][0];
            only[1][ only[1][0] ] = num;
         }else if(problem[num] == 0x8){
            only[2][0]++;
            if(only[2][0] > max) max = only[2][0];
            only[2][ only[2][0] ] = num;
         }
      }
      
      /* 3. ��� max �@�˪��L�X�Y�i */
      for(man = 1; man <= 3; ++man){
         if(only[man-1][0] == max){
            printf("%d %d", man, only[man-1][0]);  /* ���L �s�� �� �D�� */
            for(num = 1; num <= only[man-1][0]; num++) printf(" %d", only[man-1][num]);
            putchar('\n');
         }
      }
   }

   return 0;
}
