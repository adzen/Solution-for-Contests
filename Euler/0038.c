/* 把「某個數的 1~N 倍（n > 1）」結果合併，可以把數字 1~9 各用過一遍，求最大的合併結果  */

/* 還算簡單的題目... */

#include <stdio.h>

/* 數字合併 */
int digcat(int a, int b){
    int min = 1, max = 10, temp = b;
    while( !(temp >= min && temp < max) ){
        min = max;
        max = min * 10;
    }
    return a * max + b;
}

int main(){
    int base, max = 0;
    for(base = 1; base <= 9999; base++){   /* 因為 n > 1，所以 base 就不用舉超過四位數字了 */
        char used[10] = {0};
        int concatenat = 0;
        
        /* 先檢查 n = 1 的情況 */
        int temp = base;
        while(temp > 0){
            int last = temp % 10;
            
            if(last > 0 && used[last] == 0) used[last] = 1;
            else break;
            
            temp /= 10;
        }
        if(temp > 0) continue;
        
        /* 把 n = 1 的結果合併 */
        concatenat = digcat(concatenat, base);
                
        
        /* 檢查 n >= 2 的情況 */
        int n = 2;
        while(1){
            int temp = base * n;
            while(temp > 0){
                int last = temp % 10;
            
                if(last > 0 && used[last] == 0) used[last] = 1;
                else break;
            
                temp /= 10;
            }
            
            if(temp > 0){
                /* 這個 n 失敗，上一個成功的 n（即 n-1）必須大於 1 */
                if(n-1 > 1 && concatenat > max){
                    printf("base = %d, n = %d\n", base, n-1);
                    max = concatenat;
                }
                break;
            }
            
            /* 把這個成功的 n 的結果合併 */
            concatenat = digcat(concatenat, base * n);
            
            n++;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
