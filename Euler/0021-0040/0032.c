/* a * b = c。abc 剛好把數字 1~9 都用了一遍，求所有符合這條件的 c 總和。 */

/*
1. 首先用兩個一位數相乘的結果，猜測 a,b,c 的最後一位數字可能組合有哪些。
2. 再去猜 a,b,c 各別可能是幾位數。
3. 使用條件 1. 2. 用迴圈去列舉，並檢查有無重複、或沒用到的數字
4. 把所有可能的乘積 c 排序，剔除重複出現的，相加即可
*/

#include <stdio.h>
#include <stdlib.h>

long long product[100], productNum;
int can[50][2], canNum;

/* 各長度的搜尋範圍 */
int max[] = {0, 9,98,987,9876,98765, 987654,9876543,98765432,987654321};
int min[] = {0, 1,12,123,1234,12345, 123456,1234567,12345678,123456789};

/* 傳回數字的長度 */
int len(int in){
    int ans = 0;
    while(in > 0){
        ans++;
        in /= 10;
    }
    return ans;
}

/* 檢查 a,b,c 是否把 1~9 都各用過一次 */
int nodup(int a, int b, int c){
    char used[10] = {0};
    while(a > 0){
        int dig = a % 10;
        if(used[dig] == 0) used[dig] = 1;
        else return 0;
        a /= 10;
    }
    while(b > 0){
        int dig = b % 10;
        if(used[dig] == 0) used[dig] = 1;
        else return 0;
        b /= 10;
    }
    while(c > 0){
        int dig = c % 10;
        if(used[dig] == 0) used[dig] = 1;
        else return 0;
        c /= 10;
    }
    
    int i;
    for(i = 1; i <= 9 && used[i]; i++);
    return (i > 9);
}

void trycan(int lena, int lenb, int lenc){
    /* a 和 b 最後一位數已經知道了，剩下的長度 */
    lena--;
    lenb--;
    
    int a, b, canid;
    for(canid = 0; canid < canNum; canid++){
    for(a = min[lena]; a <= max[lena]; a++){
    for(b = min[lenb]; b <= max[lenb]; b++){
        long long reala = a*10 + can[canid][0];   /* 實際 a 是多少 */
        long long realb = b*10 + can[canid][1];   /* 實際 b 是多少 */
        if(a <= b){   /* 這裡假設數字 a <= b */
            long long realc = reala * realb;
            /* c 的長度符合預期，且 a,b,c 用過的數字符合條件，就加進列表中 */
            if( len(realc) == lenc && nodup(reala, realb, realc) ){
                product[productNum++] = realc;
            }
        }
    }}}
}

int cmp(const long long *a, const long long *b){
    return (*a - *b);
}

int main(){
    /* 尋找 a,b 最後一位數的組合可能有哪些？ */
    int i, j;
    for(i = 1; i <= 9; i++){
    for(j = i; j <= 9; j++){
        int last = (i*j)%10;
        if(i != j && j != last && last != 0){
            can[canNum][0] = i;
            can[canNum][1] = j;
            canNum++;
            can[canNum][0] = j;
            can[canNum][1] = i;
            canNum++;
        }
    }}
    printf("canNum = %d\n", canNum);
    
    /* 猜測 a,b,c 的長度 */
    int lena, lenb;
    for(lena = 1;    lena < 9; lena++){
    for(lenb = lena; lenb < 9; lenb++){     /* 這裡假設數字 a <= b */
       /* len(a) + len(b) + len(a)+len(b)-1 = 9 */
       if(lena + lenb + lena+lenb-1 == 9) trycan(lena, lenb, lena+lenb-1); 
       /* len(a) + len(b) + len(a)+len(b)   = 9 */
       if(lena + lenb + lena+lenb == 9) trycan(lena, lenb, lena+lenb);
    }}
    printf("productNum = %lld\n", productNum);
    
    /* 排序 */
    qsort(product, productNum, sizeof(long long), cmp);
    
    /* 剔除重複的相加即可 */
    long long sum = product[0], cur = product[0];
    for(i = 1; i < productNum; ++i){
        if(product[i] != cur){
            cur = product[i];
            sum += product[i];
        }
    }
    printf("sum = %lld\n", sum);
    
    return 0;
}
