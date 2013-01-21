/* 11163495 0.012 */
/* 三戰兩勝，每次都比大小，要發出怎樣的牌才能必勝呢？ */
/* 列舉六種搭配，每次進行刪除，最後再找有沒有最小的牌可以發 */

#include <stdio.h>

/* no：52 張牌的可能性。(a,b,c)對方的牌，(aa,bb,cc)我們的牌 */
void deal(char no[], int a, int b, int c, int aa, int bb, int cc){
   int win = 0, opp;   /* win：前兩場中贏了幾場。opp：剩下的對手是？ */
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
      /* 必輸：即使最後一場贏了，也是以 1:2 輸了 */
      for(a = 1; a <= 52; a++) no[a] = 1;  /* 刪除所有可能 */
   }else if(win == 1){
      for(a = 1; a <= opp; a++) no[a] = 1;   /* 為了要贏第三場，把 <= opp 的可能全刪除 */ 
   }else{
      /* 必贏：即使最後一場輸了，也仍以 2:1 獲勝 */
      /* 不做任何事 */
   }
}

int main(){
   int a, b, c, x, y;
   
   while( scanf("%d%d%d%d%d", &a, &b, &c, &x, &y) && a ){
      char no[53] = {0};
      no[a] = no[b] = no[c] = no[x] = no[y] = 1;   /* 先刪除已經發出去的牌 */
      
      /* 六種配對可能 */
      deal(no, a, b, c, x, y, -1);
      deal(no, a, b, c, y, x, -1);
      deal(no, a, b, c, x, -1, y);
      deal(no, a, b, c, y, -1, x);
      deal(no, a, b, c, -1, x, y);
      deal(no, a, b, c, -1, y, x);
      
      /* 找出最小的可能 */
      int i;
      for(i = 1; i <= 52; ++i) if(no[i] == 0) break;
      printf("%d\n", (i > 52) ? -1 : i );
   }

   return 0;
}
