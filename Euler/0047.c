






#include <stdio.h>

#define TOP 10000000

char notprime[TOP] = {1,1};
int prime[1000000], primen;

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
    printf("primen = %d\n", primen);
    
    for(i = 646; i < TOP; i++){
        if(notprime[i] && notprime[i+1] && notprime[i+2] && notprime[i+3]){
            int p, np, found = 1;
            for(np = i; np < i+4; np++){
                int count = 0;
                for(p = 0; prime[p] < np; p++){
                    if(np % prime[p] == 0) count++;
                }
                if(count != 4){
                    i = np;
                    found = 0;
                    break;
                }
            }
            
            if(found){
                printf("ans = %d\n", i);
                break;
            }
        }
    }

    return 0;
}
