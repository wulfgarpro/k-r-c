#include <stdio.h>

/*
 * Set x bits p->n as right most n bits of y
 */
int setbits(int x, int p, int n, int y) {
    int mask = ~((~0) << n);
    return ((mask & y) << p) | ((~(mask) << p) & x);
}

int main(void) {
    int x = 5; // 00000101
    int y = 2; // 00000010
    int p = 2;
    int n = 1;

    // expect: 00000100 (4)

    printf("%d\n", setbits(x,p,n,y));
    return 0;
}
