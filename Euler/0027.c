/* f(n) = n^2 + an + b, where |a| < 1000 and |b| < 1000
   求可以讓 f(n) 從 n=0~K 皆會是質數的 (a,b)，且 K 是最大的... */
   
/* 先篩法建質數表...然後發現 n=0 時 f(n)=b，所以 b 只要列舉小於 1000 的質數即可 */

#include <stdio.h>

#define TOP 1000000

char notprime[TOP];
int primes[80000], primen;

/* 檢查是不是質數 */
int isprime(long long in){
    if(in <= 1) return 0;   /* 包含負數 */
    if(in < TOP) return 1-notprime[in];   /* 已經建表的直接用表格檢查 */
    printf("ERROR!");   /* 剩下的例外好像因為質數表夠大，所以從來沒發生(?) */
    return 0;
}

int main(){
    /* 老樣子的篩法 */
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
    
    int a, bp, founda, foundb, maxn = 0;
    for(bp = 0; primes[bp] < 1000; bp++){    /* b 列舉小於 1000 的質數即可 */
        int b = primes[bp];
        for(a = -999; a < 1000; a++){    /* a 則只好全都列舉了 */
            long long n;
            for(n = 1; isprime(n*n+a*n+b); n++);
            n--;
            if(n > maxn){   /* 找到更高的 K 就更新 */
                founda = a;
                foundb = b;
                maxn = n;
            }
        }
    }
    
    printf("%d\n", founda*foundb);
    return 0;
}
