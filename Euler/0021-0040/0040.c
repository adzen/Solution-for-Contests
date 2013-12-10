/* 0.123456789101112131415161718192021... 的小數點後某幾個數字相乘是多少？ */

/* 先估計區塊的大小，在算出 該數 和 該數的第幾個數字... */

/* 要注意 index 從 0 開始或從 1 開始的轉換orz */

#include <stdio.h>


/* 取得 num 的第幾個數字 */
int getDigit(int num, int index){
    printf("num = %d, index = %d\n", num, index);
    
    char tok[100];
    sprintf(tok, "%d", num);
    printf("[%d]\n", tok[index]-'0');
    return (tok[index]-'0');
}

int main(){
    /* 先估計區塊長度 */
    int start[8] = {0, 0, 9}, i, min = 10, max = 100;
    for(i = 3; i < 8; ++i){
        start[i] = start[i-1] + (max-min) * (i-1);
        printf("start[%d] = %d\n", i, start[i]);
        min = max;
        max = min * 10;
    }
    
    /* 針對每個 query 去找該數 */
    int product = 1, query[7] = {1,10,100,1000,10000,100000,1000000}, queryn = 7, q;
    i = 1;
    min = 1;
    max = 10;
    for(q = 0; q < queryn; q++){
        /* 尋找合適的區塊 */
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
