



#include <stdio.h>

int sq[1000];

int main(){
    int i;
    for(i = 0; i < 1000; i++) sq[i] = i*i;
    
    int p, maxp, maxnum = 0;
    for(p = 12; p <= 1000; p++){
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
