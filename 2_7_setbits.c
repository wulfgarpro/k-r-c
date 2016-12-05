#include <stdio.h>

unsigned int setbits(int x, int p, int n) {
    return (x ^ ~((~0) << n) << (p+1-n));
}

int main(void) {
    int x = 5; // 00000101 
    int p = 3; // 00001011 // 11
    int n = 3;

    printf("%d\n", setbits(x,p,n));
    return 0;
}
