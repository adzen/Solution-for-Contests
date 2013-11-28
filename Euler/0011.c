#include <stdio.h>

int main(){
   int r, c, map[20][20];
   for(r = 0; r < 20; r++){
   for(c = 0; c < 20; c++){
      scanf("%d", &map[r][c]);
   }}
   
   int max = 0, i;
   /* vertical */
   for(r = 0; r < 16; r++){
   for(c = 0; c < 20; c++){
      int product = 1;
      for(i = r; i < r+4; i++) product *= map[i][c];
      if(product > max) max = product;
   }}
   
   /* horizon */
   for(r = 0; r < 20; r++){
   for(c = 0; c < 16; c++){
      int product = 1;
      for(i = c; i < c+4; i++) product *= map[r][i];
      if(product > max) max = product;
   }}
   
   /* \\ */ 
   int j;
   for(r = 0; r < 16; r++){
   for(c = 0; c < 16; c++){
      int product = 1;
      for(i = r, j = c; i < r+4; i++, j++) product *= map[i][j];
      if(product > max) max = product;
   }}
   
   /* // */
   for(r = 3; r < 20; r++){
   for(c = 0; c < 16; c++){
      int product = 1;
      for(i = r, j = c; j < c+4; i--, j++) product *= map[i][j];
      if(product > max) max = product;
   }}
   
   printf("%d\n", max);
   while(1);
   return 0;
}
