

#include <stdio.h>

int abundant[21200] = {12}, num = 1;
char can[28124];

int main(){
    int i;
    for(i = 13; i <= 28123; ++i){
        int sumOfDiv = 0, div;
        for(div = 1; div < i; div++) if(i % div == 0) sumOfDiv += div;
        if(sumOfDiv > i) abundant[num++] = i;    
    }
    printf("num = %d\n", num);
    
    int j;
    for(i = 0; i < num; ++i){
        for(j = i; j < num; ++j){
            if( abundant[i]+abundant[j] >= 28124 ) break;
            can[ abundant[i]+abundant[j] ] = 1;
        }
    }
    
    int ans = 0;
    for(i = 0; i <= 28123; ++i) if(can[i] == 0) ans += i;
    printf("ans = %d\n", ans);
    while(1);
    return 0;
}
