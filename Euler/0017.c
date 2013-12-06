/* 用英文寫 1~1000 時，總共需要幾個英文字母？ */

/* 簡單來說就是用遞迴... */

#include <stdio.h>

int base[20] = {
    0, 3, 3, 5, 4,  4, 3, 5, 5, 4,  /*  1~ 9 */
    3, 6, 6, 8, 8,  7, 7, 9, 8, 8   /* 10~19 */  
};

int tenth[10] = {0, 0, 6, 6, 5,  5, 5, 7, 6, 6};  /* 20~90 */

int count(int num){
    if(num < 20) return base[num];
    
    if(num == 1000) return 11; /* one thousand */
    
    if(num >= 100){   /* 100~999 */
        if(num % 100 == 0) return base[num/100] + 7;   /* ... hundred */
        else return base[num/100] + 7 + 3 + count(num%100);   /* ... hundred and ... */
    }else{   /* 20~99 */
        if(num % 10 == 0) return tenth[num/10];
        else return tenth[num/10] + base[num%10];
    }
}

int main(){
    int sum = 0, i;
    for(i = 1; i <= 1000; i++) sum += count(i);
    printf("%d\n", sum);
    return 0;
}
