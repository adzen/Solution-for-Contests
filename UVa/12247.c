/* 11163495 0.012 */
/* �T�Ԩ�ӡA�C������j�p�A�n�o�X��˪��P�~�ॲ�өO�H */
/* �C�|���طf�t�A�C���i��R���A�̫�A�䦳�S���̤p���P�i�H�o */

#include <stdio.h>

/* no�G52 �i�P���i��ʡC(a,b,c)��誺�P�A(aa,bb,cc)�ڭ̪��P */
void deal(char no[], int a, int b, int c, int aa, int bb, int cc){
   int win = 0, opp;   /* win�G�e�����Ĺ�F�X���Copp�G�ѤU�����O�H */
   if(aa == -1){
      opp = a;
      if(bb > b) win++;
      if(cc > c) win++;
   }else if(bb == -1){
      opp = b;
      if(aa > a) win++;
      if(cc > c) win++;
   }else{
      opp = c;
      if(aa > a) win++;
      if(bb > b) win++;
   }
   
   if(win == 0){
      /* ����G�Y�ϳ̫�@��Ĺ�F�A�]�O�H 1:2 ��F */
      for(a = 1; a <= 52; a++) no[a] = 1;  /* �R���Ҧ��i�� */
   }else if(win == 1){
      for(a = 1; a <= opp; a++) no[a] = 1;   /* ���F�nĹ�ĤT���A�� <= opp ���i����R�� */ 
   }else{
      /* ��Ĺ�G�Y�ϳ̫�@����F�A�]���H 2:1 ��� */
      /* ��������� */
   }
}

int main(){
   int a, b, c, x, y;
   
   while( scanf("%d%d%d%d%d", &a, &b, &c, &x, &y) && a ){
      char no[53] = {0};
      no[a] = no[b] = no[c] = no[x] = no[y] = 1;   /* ���R���w�g�o�X�h���P */
      
      /* ���ذt��i�� */
      deal(no, a, b, c, x, y, -1);
      deal(no, a, b, c, y, x, -1);
      deal(no, a, b, c, x, -1, y);
      deal(no, a, b, c, y, -1, x);
      deal(no, a, b, c, -1, x, y);
      deal(no, a, b, c, -1, y, x);
      
      /* ��X�̤p���i�� */
      int i;
      for(i = 1; i <= 52; ++i) if(no[i] == 0) break;
      printf("%d\n", (i > 52) ? -1 : i );
   }

   return 0;
}
