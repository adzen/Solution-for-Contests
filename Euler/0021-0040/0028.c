/* 格子問題...依照範例的數字擺放方式，求兩條對角線的數字總和... */

/* 簡單但實作有點小麻煩的題目。小心中間的 1 不要多加了 */

#include <stdio.h>

int matrix[1001][1001];
int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };    /* 右下左上 */

const int size = 1001;

int main(){
    /* 初始座標設在中間。中間要填 1 */
    int i = (size-1)/2, j = (size-1)/2, num = 1, max = size*size;
    
    int dir = 0, curlen = 0, maxlen = 1, two = 0;
    while(num <= max){
        matrix[i][j] = num++;   /* 填數字 */
        
        /* 移動 */
        i += direction[dir][0];
        j += direction[dir][1];
        
        curlen++;
        if(curlen >= maxlen){   /* 要轉方向了 */
            dir = (dir+1) % 4;   /* 轉方向 */
            curlen = 0;
            
            /* 每轉兩次方向，移動距離再加一 */
            if(two == 0){
                two = 1;
            }else{
                maxlen++;
                two = 0;
            }
        }
    }
    
    /* 加總 */    
    int ans = 0;
    for(i = 0; i < size; i++){
        ans += matrix[i][i];          /* \\ */
        ans += matrix[size-1-i][i];   /* // */
    }
    ans--;   /* 小心要去掉中間多加了一次 */
    printf("%d\n", ans);
    
    return 0;
}
