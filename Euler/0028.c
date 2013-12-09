



#include <stdio.h>

int matrix[1001][1001];
int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

const int size = 1001;

int main(){
    int i = (size-1)/2, j = (size-1)/2, num = 1, max = size*size;
    
    int dir = 0, curlen = 0, maxlen = 1, two = 0;
    while(num <= max){
        matrix[i][j] = num++;   /* 填數字 */
        
        /* 移動 */
        i += direction[dir][0];
        j += direction[dir][1];
        
        curlen++;
        if(curlen >= maxlen){
            dir = (dir+1) % 4;   /* 轉方向 */
            curlen = 0;
            
            if(two == 0){
                two = 1;
            }else{
                maxlen++;
                two = 0;
            }
        }
    }
        
    int ans = 0;
    /* 加總 */
    for(i = 0; i < size; i++){
        ans += matrix[i][i];
        ans += matrix[size-1-i][i];
    }
    ans--;
    printf("%d\n", ans);
    
    return 0;
}
