


#include <stdio.h>

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
    
    for(i = 9; i < TOP; i += 2){
        if(notprime[i]){
            int sq = 1, found = 0;
            while(1){
                int remain = i - 2*sq*sq;
                if(remain < 0) break;
                if(notprime[remain] == 0){
                    found = 1;
                    break;
                }
                sq++;
            }
                
            if(found == 0){
                printf("ans = %d\n", i);
                break;
            }
        }
    }

    return 0;
}
