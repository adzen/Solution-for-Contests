/* 經典的 DP 題目... */

/* 直接拿 Problem 18 的程式碼改掉 TOP 即可...XDD */

#include <stdio.h>

#define TOP 100

int curSum[100], input[100], next[100];

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    freopen("input.txt","r",stdin);
    
    scanf("%d", &curSum[0]);
    
    int num, i;
    for(num = 2; num <= TOP; num++){
        for(i = 0; i < num; ++i){
            scanf("%d", &input[i]);   /* 讀下一排的數字 */
            
            if(i == 0) next[0] = input[0] + curSum[0];
            else if(i == num-1) next[i] = input[i] + curSum[i-1];
            else next[i] = input[i] + max(curSum[i-1], curSum[i]);
        }
        
        for(i = 0; i < num; ++i) curSum[i] = next[i];   /* 移動 */     
    }
    
    int max = 0;
    for(i = 0; i < num; ++i) if(curSum[i] > max) max = curSum[i];   /* 找最大的 */
    printf("%d\n", max);
    
    return 0;
}
