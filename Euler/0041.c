


#include <stdio.h>

#define TOP 10000000

char notprime[TOP];
int prime[700000], primen;

int allDigit(int prime, int len){
    char used[10] = {0};
    while(prime > 0){
                if(prime%10 > 0 && prime%10 <= len && used[prime%10] == 0) used[prime%10] = 1;
                else return 0;
                prime /= 10;
    }
    
    int i;
    for(i = 1; i <= len; ++i) if(used[i] == 0) return 0;
    return 1;
}

int main(){
    int i = 2, j;
    while(i < TOP){
            /*primen++;*/
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
    
    int len = 7, min = 1000000, max = 9999999;
    for(i = primen-1; i >= 0; --i){
             /* adjust */
             while( !(min <= prime[i] && prime[i] <= max) ){
                    len--;
                    max = min-1;
                    min /= 10;
             }
             
             if( allDigit(prime[i], len) ){
                 printf("%d\n", prime[i]);
                 break;
             }
    }
    
    while(1);
    return 0;
}
