#include <stdio.h>

/*
 * Set x bits p->n as right most n bits of y
 */
int setbits(int x, int p, int n, int y) {
    /*int mask = ~((~0) << n);
    printf("%d\n", mask); // 00000001
    int mask_a = ((mask & y) << p);
                                   
    printf("%d\n", mask_a);
    int mask_b = (~(mask) << p) & x; 
                                    
    printf("%d\n", mask_b);
    return mask_a | mask_b;*/

    int bitmask = ~((~0) << n);
    return ((bitmask & y) << p) | (~(bitmask << p) & x);
}

int main(void) {
    int x = 5; // 00000101
    int y = 2; // 00000010
    int p = 2;
    int n = 1;

    // expect: 00000001 (1)
    printf("%d\n", setbits(x,p,n,y));
    return 0;
}
