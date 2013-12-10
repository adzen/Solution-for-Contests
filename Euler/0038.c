



#include <stdio.h>

int digcat(int a, int b){
    int min = 1, max = 10, temp = b;
    while( !(temp >= min && temp < max) ){
        min = max;
        max = min * 10;
    }
    return a * max + b;
}

int main(){
    int base, max = 0;
    for(base = 1; base <= 999999; base++){
        char used[10] = {0};
        int concatenat = 0;
        
        /* n = 1 */
        int temp = base;
        while(temp > 0){
            int last = temp % 10;
            
            if(last > 0 && used[last] == 0) used[last] = 1;
            else break;
            
            temp /= 10;
        }
        if(temp > 0) continue;
        
        concatenat = digcat(concatenat, base);
                
        
        /* n >= 2 */
        int n = 2;
        while(1){
            int temp = base * n;
            while(temp > 0){
                int last = temp % 10;
            
                if(last > 0 && used[last] == 0) used[last] = 1;
                else break;
            
                temp /= 10;
            }
            
            if(temp > 0){
                if(n > 2 && concatenat > max){
                    printf("base = %d, n = %d\n", base, n-1);
                    max = concatenat;
                }
                break;
            }
            
            concatenat = digcat(concatenat, base * n);
            
            n++;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
