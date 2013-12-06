
#include <stdio.h>

int main(){
    int add = 8, sum = 28;
    while(1){
        sum += add;
        add++;
        
        int divNum = 1, temp = sum, div = 2;
        while (temp > 1) {
            int times = 0;
            while (temp % div == 0) {
                temp /= div;
                times++;
            }
            divNum *= (times + 1);
            
            div++;
        }
        
        if (divNum >= 500) break;
    }

    printf("%d\n", sum);
    return 0;
}
