/* 11100497 0.012 */
/* 經典的 2D 找單字問題。 */
/* 有點小麻煩的題目。不過用遞迴寫，好像好看很多XD */

#include <stdio.h>
#include <ctype.h>

/* 八個方向 */
const int dirs[8][2] = { {-1,-1}, {-1,0}, {-1,1},
                         { 0,-1},         { 0,1},
                         { 1,-1}, { 1,0}, { 1,1} };

/* 把字串 toupper() */
void strup(char *in){
   int i = 0;
   while(in[i]){
      in[i] = toupper(in[i]);
      ++i;
   }
}

/* 找到了！...使用遞迴的方式XD */
int yoshi(char mx[][51], int height, int width, char *find, int dir, int x, int y){
   if(*find == 0){  /* 結束條件：成功找完整個字串 */
      return 1;
   }else if(x >= 0 && x < height && y >= 0 && y < width && mx[x][y] == *find){
      /* 使用遞迴方式，檢查下一個字母 */
      return yoshi(mx, height, width, find+1, dir, x+dirs[dir][0], y+dirs[dir][1]); 
   }else return 0;  /* 沒有配對，提前失敗 */
}

/* 對於每個 query 印出正確答案 */
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
      /* 讀取方格 */
      int height, width;
      scanf("%d%d", &height, &width);
      
      char mx[50][51] = {0};
      int i;
      for(i = 0; i < height; ++i){
         scanf("%s", mx+i);
         strup(mx+i);
      }
      
      /* 讀取 query */
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
