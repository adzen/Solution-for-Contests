/* 1182335 0.012 */
/* 小麻煩的題目...不過不難XD */

#include <stdio.h>
#include <limits.h>

int map[100][100];

void load(int size){
   int i, j;
   for(i = 0; i < size; i++){
   for(j = 0; j < size; j++){
      scanf("%d", &map[i][j]);
   }}
}

int find_max(int size){
   int max = INT_MIN, i, j;
   for(i = 0; i < size; i++){
   for(j = 0; j < size; j++){
      /* XXXX */
      if(j + 4 <= size){
         int sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]; 
         if(sum > max) max = sum;
      }
      
      /* X
         X
         X
         X */
      if(i + 4 <= size){
         int sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
         if(sum > max) max = sum;
      }
      
      /* XX
         XX */
      if(i + 2 <= size && j + 2 <= size){
         int sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i][j+1];
         if(sum > max) max = sum;
      }
      
      /* ??? 
         ??? */
      if(i + 2 <= size && j + 3 <= size){
         const int cal[5][4][2] = { { {0,0}, {0,1}, {1,1}, {1,2}, },           
                                    { {0,0}, {0,1}, {0,2}, {1,2}, },
                                    { {0,0}, {1,0}, {1,1}, {1,2}, },
                                    { {0,0}, {0,1}, {0,2}, {1,1}, },
                                    { {0,1}, {1,0}, {1,1}, {1,2}, } };
         int type, point;
         for(type = 0; type < 5; type++){
            int sum = 0;
            for(point = 0; point < 4; point++){
               sum += map[ i+cal[type][point][0] ][ j+cal[type][point][1] ];
            }
            if(sum > max) max = sum;
         }
      }
      
      /* ?? 
         ??
         ?? */
      if(i + 3 <= size && j + 2 <= size){
         const int cal[5][4][2] = { { {0,1}, {1,1}, {1,0}, {2,0}, },
                                    { {0,0}, {0,1}, {1,0}, {2,0}, },
                                    { {0,1}, {1,1}, {2,1}, {2,0}, },
                                    { {0,0}, {1,0}, {1,1}, {2,0}, },
                                    { {0,1}, {1,0}, {1,1}, {2,1}, } };
         int type, point;
         for(type = 0; type < 5; type++){
            int sum = 0;
            for(point = 0; point < 4; point++){
               sum += map[ i+cal[type][point][0] ][ j+cal[type][point][1] ];
            }
            if(sum > max) max = sum;
         }
      }
   }}
   
   return max;
}

int main(){
   int size, ti = 1;
   
   while( scanf("%d", &size) && size ){
      load(size);
      printf("%d. %d\n", ti++, find_max(size) );
   }

   return 0;
}
