/* 11171202 0.076 */
/* �� 1~20 �C�X�ӴN�ݨ�W�ߤFXD */
/* ����1����1�ӡB����2����1�ӡB����3����2�ӡB����4����3��... (�O��ƦC) */
/* ���D���׫�A�ݩM�W�@�Ӫ��׳̫᪺�s���t�h�֡A�ѤU���λ��j�ͥX��XDDD */

#include <stdio.h>

int fib[40] = {1,1,2,3, 5, 8,13};
int sum[40] = {1,2,4,7,12,20,33};

/* start: �ѤU���Ů�_�l��m�Clen: �ѤU���Ů���סCin: �ƦC���s�� */
void fill(char *ans, int start, int len, int in){
   if(len == 1){
      ans[start] = '1';
   }else if(len == 2){
      ans[start] = '1';
      ans[start+1] = '0';
   }else{
      /* �ݩM�W�@�Ӫ��׳̫᪺�s���t�h�� */
      int remain = in - sum[len-2] - 1;
      
      if(remain == 0){  /* 100000... */
         ans[start] = '1';
         int i;
         for(i = start+1; i < start+len; ++i) ans[i] = '0';
      }else{
         /* �ήt�� remain �A�h��Ѿl������ */
         int newlen;
         for(newlen = 1; remain > sum[newlen-1]; newlen++);
         
         /* ����e���� 100000... �� */
         ans[start] = '1';
         int i;
         for(i = start+1; i < start+len-newlen; ++i) ans[i] = '0';
         
         /* ���jXD */
         fill(ans, start+len-newlen, newlen, remain);
      }
   }
}

int main(){
   /* �p��n fib �M sum */
   int i;
   for(i = 6; i < 40; ++i){
      fib[i] = fib[i-1] + fib[i-2];
      sum[i] = sum[i-1] + fib[i];
   }
   
   int test, in;
   scanf("%d", &test);
   
   while( test-- && scanf("%d", &in) ){
      /* �� sum �ݪ��׬O�h�� */
      int len;
      for(len = 1; in > sum[len-1]; len++);
      
      char ans[40] = {0};
      fill(ans, 0, len, in);  /* ���j�覡�񺡵��� */
      puts(ans);      
   }

   return 0;
}
