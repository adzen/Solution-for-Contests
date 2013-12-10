/* 小於一百萬，且十進位和二進位表示法皆是 palindrome 的數字總和 */

/* 算簡單題吧...這裡嘗試列舉十進位的 palindrome 時使用了新方法 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 把左邊反過來變成右邊，兩者再接起來。中間有時可以重疊 */
int palin(int in, int center){
    char left[100], right[100] = {0};
    sprintf(left, "%d", in);
    
    int i = strlen(left)-1, j = 0;
    while(i >= 0){
        right[j] = left[i];
        i--;
        j++;
    }
    
    if(center) strcat(left, right+1);
    else strcat(left, right);
    
    return atoi(left);
}

/* 判斷二進位時是否是 palindrome */
int binpalin(int in){
    int rev = 0, temp = in;
    while(temp){
        rev = (rev << 1) | (temp & 0x1);
        temp >>= 1;
    }
    return (rev == in);
}

int main(){
    int part, ans = 0;
    for(part = 1; part <= 999; part++){
        int next = palin(part, 0);
        if( binpalin(next) ) ans += next;
        next = palin(part, 1);
        if( binpalin(next) ) ans += next;
    }
    printf("%d\n", ans);
    return 0;
}
