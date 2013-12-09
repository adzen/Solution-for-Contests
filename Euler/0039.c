/* a+b+c = p, a^2+b^2 = c^2, 在 p <= 1000 的情況下，哪個 p 可以有最多的解？ */

/* 先把 1000 以下的平方數算好備用，剩下就只是窮舉而已 */

#include <stdio.h>

int sq[1000];

int main(){
    /* 0^2 ~ 999^2 */
    int i;
    for(i = 0; i < 1000; i++) sq[i] = i*i;
    
    int p, maxp, maxnum = 0;
    for(p = 12; p <= 1000; p++){   /* 最小的 p 是 3+4+5=12 */
        int solNum = 0, a;
        for(a = 1; a < p; a++){
            int bc = p-a, b;
            for(b = a; b < bc; b++){
                int c = bc-b;
                if(c >= b && sq[a]+sq[b] == sq[c]) solNum++;
            }
        }
        
        if(solNum > maxnum){
            maxnum = solNum;
            maxp = p;
        }
    }
    
    printf("p = %d (%d solutions)\n", maxp, maxnum);

    return 0;
}
