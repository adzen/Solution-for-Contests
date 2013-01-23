/* 11173021 0.004 */
/* 模擬題。規則有點微妙，不過對照題目範例應可理解 */

#include <stdio.h>

char map[1000][1000];

/* 設定好一堆 '1' 的邊界 */
void border(int r, int c){
   int i;
   for(i = 0; i <= r; ++i) map[i][0] = map[i][c+1] = '1';
   for(i = 0; i <= c; ++i) map[0][i] = map[r+1][i] = '1';
}

const int dirs[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

int main(){
   int r, c;
   
   while( scanf("%d%d", &r, &c) && r+c ){
      /* 讀取地圖，並設定好邊界 */
      int i;
      for(i = 1; i <= r; ++i) scanf("%s", map[i]+1);
      border(r, c);
      
      int x = r, y = 1, dir = 0;
      while(1){
         /* 試著移動，如果不能就左轉再試試看 */
         int nx, ny;
         while(1){
            nx = x + dirs[dir][0];
            ny = y + dirs[dir][1];
            
            if(map[nx][ny] != '1') break;
            dir = (dir+1) % 4;
         }
         x = nx;
         y = ny;
         
         map[x][y]--;   /* 累計走過的次數 */
         
         /* 如果右邊不是牆壁，就向右轉 */
         if(map[ x+dirs[(dir+3)%4][0] ][ y+dirs[(dir+3)%4][1] ] != '1') dir = (dir+3) % 4;
         
         /* 如果到終點就跳出 */
         if(x == r && y == 1) break;
      }
      
      /* 統計五個數字答案 */
      int ans[5] = {0};
      for(x = 1; x <= r; x++){
      for(y = 1; y <= c; y++){
      for(i = 0; i <= 4; i++){
         if(map[x][y] == '0'-i) ans[i]++;
      }}}
      
      for(r = 0; r < 5; ++r) printf("%3d", ans[r]);
      puts("");
   }

   return 0;
}
