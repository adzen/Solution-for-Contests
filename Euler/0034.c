/*「數字的階乘總和 == 該數字大小」的數字總和 */

/* 應該算簡單吧...就純粹列舉並檢查而已 */


#include <stdio.h>

int main(){
    /* 0! ~ 9! */
    int fact[10] = {1}, i;
    for(i = 1; i < 10; ++i) fact[i] = fact[i-1] * i;
    
    int sum = 0;
    for(i = 3; i <= 1000000; ++i){
        int factDig = 0, j = i;
        while(j > 0){
            factDig += fact[j%10];
            j /= 10;
        }
        
        if(factDig == i){
            printf("%d\n", i);
            sum += i;
        }
    }
    printf("ans = %d\n", sum);
    
    return 0;
}
