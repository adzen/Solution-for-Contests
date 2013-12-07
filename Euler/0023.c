/* 求所有「無法用兩個 abundant numbers 的和表示」的正整數總和... */

/* 題目講了「大於 28123 的數字皆可用兩個 abundant numbers 相加」，
   所以我們只要找 <= 28123 的數字即可 */

#include <stdio.h>

int abundant[21200] = {12}, num = 1;
char can[28124];

int main(){
    /* 尋找 13~28123 的 abundant number */
    int i;
    for(i = 13; i <= 28123; ++i){
        int sumOfDiv = 0, div;
        for(div = 1; div < i; div++) if(i % div == 0) sumOfDiv += div;
        if(sumOfDiv > i) abundant[num++] = i;    
    }
    printf("num = %d\n", num);
    
    /* 列舉兩個 abundant 相加的結果註記在 can[] 上 */
    int j;
    for(i = 0; i < num; ++i){
        for(j = i; j < num; ++j){
            if( abundant[i]+abundant[j] >= 28124 ) break;
            can[ abundant[i]+abundant[j] ] = 1;
        }
    }
    
    /* 把 can[] 沒被註記的（無法用兩個 abundant 相加的數）加起來即可 */
    int ans = 0;
    for(i = 0; i <= 28123; ++i) if(can[i] == 0) ans += i;
    printf("ans = %d\n", ans);

    return 0;
}
