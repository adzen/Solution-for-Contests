



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
                int smallerType;
                for(smallerType = 0; smallerType <= type; smallerType++){
                    dp[value][type] += dp[value-coin[type]][smallerType];    
                }
            }else dp[value][type] = 0;
            
            /*printf("dp[%d][%d]=%lld\n",value,type,dp[value][type]);*/
            sum[value] += dp[value][type];
        }
    }
    printf("%lld\n", sum[200]);

    return 0;
}
