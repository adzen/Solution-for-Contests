/* 傳說中的 3n+1 問題...
   求小於 1 000 000 的正整數中，哪個數字當開頭會最長？ */
  
/* 從 999 999 往下列舉，依序算出長度即可。
   算長度時可順便把同一條 chain 中出現的數字註記掉（因為一定比較短） */
   
/* 小心過程可能會溢位 */

#include <stdio.h>

#define TOP 1000000

char tested[TOP];   /* 出現過的數字表 */

/* 使用遞迴方式，計算 chain 的長度 */
int chain(long long in){
    if(in == 1) return 1;
    else{
        if(in < TOP) tested[in] = 1;
        
        if(in % 2) return chain(3*in+1) + 1;
        else return chain(in/2) + 1;
    }
}

int main(){
    int max = 0, maxi, i;
    for(i = TOP-1; i >= 1; i--){
        if(tested[i]) continue;   /* 出現過的就跳過 */
        int terms = chain(i);
        if(terms > max){
            max = terms;
            maxi = i;
        }
    }
    printf("%d\n", maxi);
    return 0;
}
