



#include <stdio.h>

int getDigit(int num, int index){
    printf("num = %d, index = %d\n", num, index);
    
    char tok[100];
    sprintf(tok, "%d", num);
    printf("[%d]\n", tok[index]-'0');
    return (tok[index]-'0');
}

int main(){
    int start[8] = {0, 0, 9}, i, min = 10, max = 100;
    for(i = 3; i < 8; ++i){
        start[i] = start[i-1] + (max-min) * (i-1);
        printf("start[%d] = %d\n", i, start[i]);
        min = max;
        max = min * 10;
    }
    
    int product = 1, query[7] = {1,10,100,1000,10000,100000,1000000}, queryn = 7, q;
    i = 1;
    min = 1;
    max = 10;
    for(q = 0; q < queryn; q++){
        while( !(start[i] < query[q] && query[q] <= start[i+1]) ){
            i++;
            min = max;
            max = min * 10;
        }
        printf("q[%d] = %d => start[%d] = %d\n", q, query[q], i, start[i]);
        product *= getDigit(min + (query[q]-start[i]-1)/i, (query[q]-start[i]-1)%i);
    }
    printf("ans = %d\n", product);

    return 0;
}
