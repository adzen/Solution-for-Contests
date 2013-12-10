



#include <stdio.h>

int main(){
    long long fact[10] = {1}, i;
    for(i = 1; i < 10; ++i) fact[i] = fact[i-1] * i;
    
    long long sum = 0;
    for(i = 3; i <= 1000000; ++i){
        long long factDig = 0, j = i;
        while(j > 0){
            factDig += fact[j%10];
            j /= 10;
        }
        if(factDig == i){
            printf("%lld\n", i);
            sum += i;
        }
    }
    printf("ans = %lld\n", sum);
    
    return 0;
}
