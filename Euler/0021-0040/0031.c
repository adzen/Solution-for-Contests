/* 換零錢問題...經典的 DP */

#include <stdio.h>

long long coin[8] = {1,2,5,10,20,50,100,200};
long long dp[201][8];   /* [金額][硬幣] */
long long sum[201];

int main(){
    int value, type;
    for(value = 1; value <= 200; value++){
        for(type = 0; type < 8; type++){
            if(value == coin[type]) dp[value][type] = 1;
            else if(value > coin[type]){
                /* 剩下的錢只能用跟它一樣大或較小的來換，避免重複計算 */
                int smaller;
                for(smaller = 0; smaller <= type; smaller++) dp[value][type] += dp[value-coin[type]][smaller];    
            }else dp[value][type] = 0;
            
            /*printf("dp[%d][%d]=%lld\n",value,type,dp[value][type]);*/
            sum[value] += dp[value][type];
        }
    }
    printf("%lld\n", sum[200]);

    return 0;
}
