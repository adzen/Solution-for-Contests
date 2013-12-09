


#include <stdio.h>

int gcd(int a, int b){
    while(b > 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    int up, down;
    int ansup = 1, ansdn = 1;
    for(up = 10; up <= 98; up++){
    for(down = up+1; down <= 99; down++){
        if(up % 10 == 0 && down % 10 == 0) continue;
        
        int up1 = up / 10, up2 = up % 10, dn1 = down / 10, dn2 = down % 10;
        if(up1 == dn1 && up2*down == dn2*up){
            ansup *= up2;
            ansdn *= dn2;
        }else if(up1 == dn2 && up2*down == dn1*up){
            ansup *= up2;
            ansdn *= dn1;
        }else if(up2 == dn1 && up1*down == dn2*up){
            ansup *= up1;
            ansdn *= dn2;
        }else if(up2 == dn2 && up1*down == dn1*up){
            ansup *= up1;
            ansdn *= dn1;
        }
    }}
    
    int com = gcd(ansup, ansdn);
    printf("%d / %d = %d / %d\n", ansup, ansdn, ansup/com, ansdn/com);
    
    return 0;    
}
