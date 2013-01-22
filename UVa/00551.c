/* 11171077 0.008 */
/* �A���t�諸�D�ءC�p�� count ���w�q�C */
/* WA���I�G�ťզ� �� YES�C
           �i�঳�ťա]�Х�gets()�^
           ���X�j��A�٭n�ˬd top �O�_�^�k -1 */

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
