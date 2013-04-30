/* 11544135 400K 16MS */
/* 就大數加法而已... */
/* 為了保險，我會把 prefix 的 '0' 去掉... */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
   int num[20];
} bign;

/* 歸零 */
void zero(bign *in){
   int i;
   for(i = 0; i < 20; ++i) in->num[i] = 0;
}

/* 從字串變成大數 */
void make(bign *out, char *str){
   int len = strlen(str), i = 0;
   while(str[i] && str[i] == '0') i++;  /* 忽略前面的 '0' */
   
   zero(out);
   if(str[i]){      
      int end = len, start = len - 8, bigi = 0;
      while(start >= i){
         out->num[bigi++] = atoi(str + start);
         str[start] = 0;
         end -= 8;
         start -= 8;
      }
      
      if(end) out->num[bigi++] = atoi(str);      
   }
}

/* 就大數加法... */
void add(bign *out, bign *in){
   int i, carry = 0;
   for(i = 0; i < 20; ++i){
      out->num[i] += in->num[i] + carry;
      carry = out->num[i] / 100000000;
      out->num[i] %= 100000000;
   }
}

void print(bign *out){
   int i = 19;
   while(i >= 0 && out->num[i] == 0) i--;
   
   if(i < 0) puts("0");
   else{
      printf("%d", out->num[i--]);
      while(i >= 0) printf("%08d", out->num[i--]);
      puts("");
   }
}

int main(){
   char line[120];
   
   bign ans;
   zero(&ans);
   
   while( scanf("%s", line) && strcmp(line, "0") ){
      bign num;
      make(&num, line);
      add(&ans, &num);
   }
   print(&ans);

   return 0;
}
