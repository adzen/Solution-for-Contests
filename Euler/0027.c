#include <stdio.h>

#define TOP 1000000

char notprime[TOP];
int primes[80000], primen;

int isprime(long long in){
    if(in <= 1) return 0;
    if(in < TOP) return 1-notprime[in];
    printf("ERR");
    return 0;
}

int main(){
    int i = 2, j;
    while(i < TOP){
        primes[primen++] = i;
        j = i * 2;
        while(j < TOP){
            notprime[j] = 1;
            j += i;
        }
        i++;
        while(i < TOP && notprime[i]) i++;
    }
    /*printf("%d\n", primen);*/
    
    int a, bp, founda, foundb, maxn = 0;
    for(bp = 0; primes[bp] < 1000; bp++){
        int b = primes[bp];
        for(a = -999; a < 1000; a++){
            long long n;
            for(n = 1; isprime(n*n+a*n+b); n++);
            n--;
            if(n > maxn){
                founda = a;
                foundb = b;
                maxn = n;
            }
        }
    }
    
    printf("%d\n", founda*foundb);
    return 0;
}
