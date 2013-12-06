/* 第一個擁有超過 500 個因數的 triangle number？ */

/* 本來想說答案會很大，所以先用 C# 寫。不過答案 int 竟然放得下orz */
 
/* 就做質因數分解，由次方數可得知因數個數... */

#include <stdio.h>

int main(){
    int add = 8, sum = 28;
    while(1){
        sum += add;
        add++;
        
        int divNum = 1, temp = sum, div = 2;
        while (temp > 1) {
            int times = 0;
            while (temp % div == 0) {
                temp /= div;
                times++;
            }
            divNum *= (times + 1);
            
            div++;
        }
        
        if (divNum >= 500) break;
    }

    printf("%d\n", sum);
    return 0;
}
