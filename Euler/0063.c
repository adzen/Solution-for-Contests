/* K = b^p，K 是 p 位數的組合有多少個？ */

/* 列舉 b^p，用 log10() 看是幾位數... */

/* b 只列舉 1~9 的原因在於，「當 b=10 時，K 一定會是 p+1 位數」。
   所以 b 再往上繼續列舉的結果，一定會超過 p 位數 */

#include <stdio.h>
#include <math.h>

int main(){
    int b, p, ans = 0;
    for(p = 1; ; p++){   /* b^p */
        int count = 0;
        for(b = 1; b < 10; b++){
            double dig = log10(pow(b,p));
            
            if(dig >= p-1 && dig < p){
                count++;
                ans++;
            }
        }
        if(count == 0) break;
    }
    printf("%d\n", ans);
    return 0;
}
