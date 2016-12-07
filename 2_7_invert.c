#include <stdio.h>

unsigned int setbits(int x, int p, int n) {
    return (x ^ ~((~0) << n) << (p+1-n));
}

int main(void) {
    int x = 5;
    int p = 3; 
    int n = 3;

    // 00000101
    // 00001110
    // XOR
    // 00001011 // 11 

    printf("%d\n", setbits(x,p,n));
    return 0;
}
