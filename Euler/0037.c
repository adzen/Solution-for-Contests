





#include <stdio.h>
#include <stdlib.h>

#define TOP 1000000

char notprime[TOP] = {1,1};
int prime[80000], primen;

int main(){
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
    for(i = 4; i < primen; i++){   /* 略過 2,3,5,7 */
        char dig[100];
        sprintf(dig, "%d", prime[i]);
        
        int j = 1;
        while(dig[j] && notprime[atoi(dig+j)] == 0) j++;
        if(dig[j] > 0) continue;
        
        j--;
        while(j > 0 && (dig[j]=0, notprime[atoi(dig)] == 0) ) j--;
        if(j > 0) continue;
        
        ans += prime[i];
    }
    printf("sum = %d\n", ans);

    return 0;
}
