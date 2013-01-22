/* 11171077 0.008 */
/* 括號配對的題目。小心 count 的定義。 */
/* WA的點：空白行 → YES。
           可能有空白（請用gets()）
           跳出迴圈，還要檢查 top 是否回歸 -1 */

#include <stdio.h>

int main(){
   char str[4000];
   
   while( gets(str) != NULL ){
      char stack[4000];
      int i = 0, count = 1, top = -1, yes = 1;
      while( str[i] ){
         if(str[i] == '[') stack[++top] = '[';
         else if(str[i] == '{') stack[++top] = '{';
         else if(str[i] == '<') stack[++top] = '<';
         else if(str[i] == '(' && str[i+1] == '*'){   /*  (*  */
            stack[++top] = '*';
            i++;
         }else if(str[i] == '(') stack[++top] = '(';
         else if(str[i] == ']'){
            if(top >= 0 && stack[top] == '['){
               top--;
            }else{
               yes = 0;
               break;
            }
         }else if(str[i] == '}'){
            if(top >= 0 && stack[top] == '{'){
               top--;
            }else{
               yes = 0;
               break;
            }
         }else if(str[i] == '>'){
            if(top >= 0 && stack[top] == '<'){
               top--;
            }else{
               yes = 0;
               break;
            }
         }else if(str[i] == ')'){
            if(top >= 0 && stack[top] == '('){
               top--;
            }else{
               yes = 0;
               break;
            }
         }else if(str[i] == '*' && str[i+1] == ')'){    /*  *)  */
            if(top >= 0 && stack[top] == '*'){
               top--;
            }else{
               yes = 0;
               break;
            }
            i++;
         }
         
         i++;
         count++;
      }
      
      if(yes && top == -1) puts("YES");
      else printf("NO %d\n", count);
   }

   return 0;
}
