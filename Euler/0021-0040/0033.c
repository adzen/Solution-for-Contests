/* 有四個 兩位數/兩位數 且 大小小於 1 的分數，若分子分母同時去掉同一個數字後的大小會不變 
   求這四個分數的乘積，使用最簡分數表示時的分母 */
   
/* 呃...數字很小，算簡單題吧... */

#include <stdio.h>

int gcd(int a, int b){
    while(b > 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    int up, down;
    int ansup = 1, ansdn = 1;  /* 四個分數的乘積 */
    for(up = 10; up <= 98; up++){
    for(down = up+1; down <= 99; down++){   /* 分子 < 分母 */
        if(up % 10 == 0 && down % 10 == 0) continue;   /* 分子和分母不能同時是 10 的倍數 */
        
        /* 四種情況 */
        int up1 = up / 10, up2 = up % 10, dn1 = down / 10, dn2 = down % 10;
        if(up1 == dn1 && up2*down == dn2*up){
            ansup *= up2;
            ansdn *= dn2;
        }else if(up1 == dn2 && up2*down == dn1*up){
            ansup *= up2;
            ansdn *= dn1;
        }else if(up2 == dn1 && up1*down == dn2*up){
            ansup *= up1;
            ansdn *= dn2;
        }else if(up2 == dn2 && up1*down == dn1*up){
            ansup *= up1;
            ansdn *= dn1;
        }
    }}
    
    /* 化成最簡分數 */
    int com = gcd(ansup, ansdn);
    printf("%d / %d = %d / %d\n", ansup, ansdn, ansup/com, ansdn/com);
    
    return 0;    
}
