/* 「從左邊砍數字，和從右邊砍數字都會是質數」的質數，求這些質數的總和 */

/* 篩法找出質數們，一一檢查其性質即可... */


#include <stdio.h>
#include <stdlib.h>

#define TOP 1000000

char notprime[TOP] = {1,1};
int prime[80000], primen;

int main(){
    /* 老樣子的篩法 */
    int i = 2, j;
    while(i < TOP){
        prime[primen++] = i;
        j = i * 2;
        while(j < TOP){
            notprime[j] = 1;
            j += i;
        }
        i++;
        while(i < TOP && notprime[i]) i++;
    }
    /*printf("primen = %d\n", primen);*/
    
    int ans = 0;
    for(i = 4; i < primen; i++){   /* 要記得略過 2,3,5,7 */
        char dig[100];
        sprintf(dig, "%d", prime[i]);
        
        /* 從左邊砍數字 */
        int j = 1;
        while(dig[j] && notprime[atoi(dig+j)] == 0) j++;
        if(dig[j] > 0) continue;
        
        /* 從右邊砍數字 */
        j--;
        while(j > 0 && (dig[j]=0, notprime[atoi(dig)] == 0) ) j--;
        if(j > 0) continue;
        
        ans += prime[i];
    }
    printf("sum = %d\n", ans);

    return 0;
}
