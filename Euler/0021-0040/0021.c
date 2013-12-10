/* 求小於一萬所有 amicable numbers 的總和... */

/* 數字頗小，求因數和時直接試除即可... */

/* 要注意 a ≠ b 這個條件 */

#include <stdio.h>

int dn[10000];   /* 每個數字的 d(n) */

int main(){
    /* 先算 2~9999 的 d(n) */
    int i;
    for(i = 2; i < 10000; ++i){
        int sumOfDiv = 0, div;
        for(div = 1; div < i; div++) if(i % div == 0) sumOfDiv += div;
        dn[i] = sumOfDiv;
    }
    
    /* 再把符合條件的加起來即可 */
    int ans = 0;
    for(i = 2; i < 10000; ++i) if(dn[i] != i && dn[i] < 10000 && dn[dn[i]] == i) ans += i;
    printf("%d\n", ans);
    
    return 0;
}
