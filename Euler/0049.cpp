






#include <cstdio>

#include <algorithm>

#define TOP 10000

using namespace std;

char notprime[TOP] = {1,1};
int prime[10000], primen;

int isper(int a, int b){
    char used[10] = {0};
    
    while(a){
        used[a%10]++;
        a /= 10;
    }
    while(b){
        used[b%10]--;
        b /= 10;
    }
    
    int i;
    for(i = 0; i < 10; ++i) if(used[i] != 0) return 0;
    return 1;
}

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
    
    for(i = primen-1; prime[i] >= 1000; i--){
        int dig[4], temp = prime[i];
        for(j = 0; j < 4; j++){
            dig[j] = temp % 10;
            temp /= 10;
        }
        /*printf("prime %d\n", prime[i]);*/
        int find = 0;
        sort(dig, dig+4);
        while( next_permutation(dig, dig+4) ){
            if(dig[0] > 0){
                int guess = 0;
                for(j = 0; j < 4; j++) guess = guess * 10 + dig[j];
                /*printf("[%d]", guess);*/
                if(guess > prime[i] && notprime[guess] == 0 && 
                    isper(guess, guess+guess-prime[i]) && notprime[guess+guess-prime[i]] == 0){
                    printf("%d%d%d\n", prime[i], guess, guess+guess-prime[i]);
                    find = 1;
                    break;
                }
            }
        }
        
        if(find) break;
    }

    return 0;
}
