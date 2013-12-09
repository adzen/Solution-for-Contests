


#include <stdio.h>
#include <stdlib.h>

long long product[10000], productNum;
int can[50][2], canNum;

int max[] = {0, 9,98,987,9876,98765, 987654,9876543,98765432,987654321};
int min[] = {0, 1,12,123,1234,12345, 123456,1234567,12345678,123456789};

int len(int in){
    int ans = 0;
    while(in > 0){
        ans++;
        in /= 10;
    }
    return ans;
}

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
    int a, b, canid;
    lena--;
    lenb--;
    for(canid = 0; canid < canNum; canid++){
    for(a = min[lena]; a <= max[lena]; a++){
    for(b = min[lenb]; b <= max[lenb]; b++){
        long long reala = a*10 + can[canid][0];
        long long realb = b*10 + can[canid][1];
        if(a <= b){
            long long realc = reala * realb;
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
    
    int lena, lenb;
    for(lena = 1;    lena < 9; lena++){
    for(lenb = lena; lenb < 9; lenb++){
       /* len(a) + len(b) + len(a)+len(b)-1 = 9 */
       if(lena + lenb + lena+lenb-1 == 9) trycan(lena, lenb, lena+lenb-1); 
       /* len(a) + len(b) + len(a)+len(b)   = 9 */
       if(lena + lenb + lena+lenb == 9) trycan(lena, lenb, lena+lenb);
    }}
    printf("productNum = %lld\n", productNum);
    
    qsort(product, productNum, sizeof(long long), cmp);
    
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
