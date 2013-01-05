/* 11100497 0.012 */
/* �g�媺 2D ���r���D�C */
/* ���I�p�·Ъ��D�ءC���L�λ��j�g�A�n���n�ݫܦhXD */

#include <stdio.h>
#include <ctype.h>

/* �K�Ӥ�V */
const int dirs[8][2] = { {-1,-1}, {-1,0}, {-1,1},
                         { 0,-1},         { 0,1},
                         { 1,-1}, { 1,0}, { 1,1} };

/* ��r�� toupper() */
void strup(char *in){
   int i = 0;
   while(in[i]){
      in[i] = toupper(in[i]);
      ++i;
   }
}

/* ���F�I...�ϥλ��j���覡XD */
int yoshi(char mx[][51], int height, int width, char *find, int dir, int x, int y){
   if(*find == 0){  /* ��������G���\�䧹��Ӧr�� */
      return 1;
   }else if(x >= 0 && x < height && y >= 0 && y < width && mx[x][y] == *find){
      /* �ϥλ��j�覡�A�ˬd�U�@�Ӧr�� */
      return yoshi(mx, height, width, find+1, dir, x+dirs[dir][0], y+dirs[dir][1]); 
   }else return 0;  /* �S���t��A���e���� */
}

/* ���C�� query �L�X���T���� */
void answer(char mx[][51], int height, int width, char *find){
   int i, j, dir;
   for(i = 0; i < height; ++i){
   for(j = 0; j < width; ++j){
   for(dir = 0; dir < 8; ++dir){
      if( yoshi(mx, height, width, find, dir, i, j) ){
         printf("%d %d\n", i+1, j+1);
         return;
      }
   }}}
}

int main(){
   int test;
   scanf("%d", &test);
   
   while(test-- > 0){
      /* Ū����� */
      int height, width;
      scanf("%d%d", &height, &width);
      
      char mx[50][51] = {0};
      int i;
      for(i = 0; i < height; ++i){
         scanf("%s", mx+i);
         strup(mx+i);
      }
      
      /* Ū�� query */
      int num;
      scanf("%d", &num);
      
      char find[100] = {0};
      for(i = 0; i < num; ++i){
         scanf("%s", find);
         strup(find);
         answer(mx, height, width, find);
      }
      
      if(test) puts("");
   }
   
   return 0;
}
