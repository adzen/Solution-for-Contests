




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
