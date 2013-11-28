#include <stdio.h>

int main(){
   long long int ans[21][21];
   
   int i;
   for(i = 0; i < 21; i++) ans[i][0] = ans[0][i] = 1;
   
   int j;
   for(i = 1; i < 21; i++){
   for(j = 1; j < 21; j++){
      ans[i][j] = ans[i-1][j] + ans[i][j-1];
   }}
   
   printf("%lld\n", ans[20][20]);   
   while(1);
   return 0;
}
