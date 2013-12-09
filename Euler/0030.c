


#include <stdio.h>

int sq[10];    /* 0~9 的五次方 */

/* 求數字的五次方之和 */
int fifth(int in){
    int ans = 0;
    while(in > 0){
        ans += sq[in%10];
        in /= 10;
    }
    return ans;
}

int main(){
    /* 先計算 0~9 的五次方 */
    int i;
    for(i = 0; i < 10; ++i) sq[i] = i*i*i*i*i;
    
    int len, min = 10, max = 100, sum = 0;
    for(len = 2; len < 8; len++){
        printf("len = %d\n", len);
        for(i = min; i < max; ++i){   /* 列舉該長度的數字們計算 */
              if( fifth(i) == i ){
                  sum += i;
                  printf("\t%d\n", i);
              }
        }
        
        min = max;
        max = min * 10;
    }
    
    printf("%d\n", sum);
    return 0;
}
