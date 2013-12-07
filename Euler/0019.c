#include <stdio.h>

int days[12] = {31,28,31, 30,31,30, 31,31,30, 31,30,31};

int isleap(int year){
    return (year % 4 == 0) && (year % 100) || (year % 400 == 0);
}

int main(){
    int ans = 0, year, month, jan_1_1900 = 1;
    /* 1900 is leap */
    for(month = 1; month <= 12; month++){
        jan_1_1900 += days[month-1];
        if(month == 2) jan_1_1900++;
    }
    
    int jan_1_1901 = jan_1_1900 % 7;
    for(year = 1901; year <= 2000; year++){
        for(month = 1; month <= 12; month++){
            if(jan_1_1901 % 7 == 0) ans++;
            jan_1_1901 += days[month-1];
            if( month == 2 && isleap(year) ) jan_1_1901++;
        }
    }
    
    printf("%d\n", ans);
    return 0;    
}
