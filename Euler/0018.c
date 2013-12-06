#include <stdio.h>

#define TOP 15

int curSum[100], input[100], next[100];

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    scanf("%d", &curSum[0]);
    
    int num, i;
    for(num = 2; num <= TOP; num++){
        for(i = 0; i < num; ++i){
            scanf("%d", &input[i]);
            
            if(i == 0) next[0] = input[0] + curSum[0];
            else if(i == num-1) next[i] = input[i] + curSum[i-1];
            else next[i] = input[i] + max(curSum[i-1], curSum[i]);
        }
        
        for(i = 0; i < num; ++i) curSum[i] = next[i];        
    }
    
    int max = 0;
    for(i = 0; i < num; ++i) if(curSum[i] > max) max = curSum[i];
    printf("%d\n", max);
    
    return 0;
}
