/* 很簡單的題目。注意一下題目的判斷條件即可。 */

#include <stdio.h>

bool isfull(char map[][5]){
   for(int i = 0; i < 4; ++i){
   for(int j = 0; j < 4; ++j){
      if(map[i][j] == '.') return false;
   }}
   return true;
}

bool iswon(char map[][5], char player){
   for(int row = 0; row < 4; ++row){
      int col;
      for(col = 0; col < 4; ++col){
         if(map[row][col] != player && map[row][col] != 'T') break;
      }
      if(col == 4) return true;
   }
   
   for(int col = 0; col < 4; ++col){
      int row;
      for(row = 0; row < 4; ++row){
         if(map[row][col] != player && map[row][col] != 'T') break;
      }
      if(row == 4) return true;
   }
   
   int check1[][2] = { {0,0},{1,1},{2,2},{3,3} }, i;
   for(i = 0; i < 4; ++i){
      if(map[check1[i][0]][check1[i][1]] != player && 
         map[check1[i][0]][check1[i][1]] != 'T') break;
   }
   if(i == 4) return true;
   
   int check2[][2] = { {0,3},{1,2},{2,1},{3,0} };
   for(i = 0; i < 4; ++i){
      if(map[check2[i][0]][check2[i][1]] != player && 
         map[check2[i][0]][check2[i][1]] != 'T') break;
   }
   if(i == 4) return true;
   
   return false;
}

int main(){
   int test, ti = 1;
   scanf("%d", &test);
   
   while(test--){
      char map[4][5] = {0};
      for(int i = 0; i < 4; ++i) scanf("%s", &map[i]);
      
      bool fulled = isfull(map);
      bool X = iswon(map, 'X');
      bool O = iswon(map, 'O');
      
      if(X && !O) printf("Case #%d: X won\n", ti++);
      else if(O && !X) printf("Case #%d: O won\n", ti++);
      else if(fulled)printf("Case #%d: Draw\n", ti++);
      else printf("Case #%d: Game has not completed\n", ti++);
   }

   return 0;
}
