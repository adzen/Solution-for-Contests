#include <stdio.h>

#define TOP 1000000

char tested[TOP];

int chain(long long in){
    if(in == 1) return 1;
    else{
        if(in < TOP) tested[in] = 1;
        
        if(in % 2) return chain(3*in+1) + 1;
        else return chain(in/2) + 1;
    }
}

int main(){
    int max = 0, maxi, i;
    for(i = TOP-1; i >= 1; i--){
        if(tested[i]) continue;
        int terms = chain(i);
        if(terms > max){
            max = terms;
            maxi = i;
        }
    }
    printf("%d\n", maxi);
    return 0;
}
