

#include <stdio.h>

int dn[10000];

int main(){
    int i;
    for(i = 2; i < 10000; ++i){
        int sumOfDiv = 0, div;
        for(div = 1; div < i; div++) if(i % div == 0) sumOfDiv += div;
        dn[i] = sumOfDiv;
    }
    
    int ans = 0;
    for(i = 2; i < 10000; ++i) if(dn[i] < 10000 && dn[i] != i && dn[dn[i]] == i) ans += i;
    printf("%d\n", ans);
    
    return 0;
}
