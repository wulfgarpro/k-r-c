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

    // bitmask of n 1's, right aligned
    int bitmask = ~((~0) << n);

    // A: this &'s the right most n bits of y with mask
    // and moves this to p
    // B: shift bitmask to p and convert 1's to 0's then
    // & with x to 0 out p->n of x
    // then
    // A | B to combine A and B (result)
    return ((bitmask & y) << p) | (~(bitmask << p) & x);
}

int main(void) {
    int x = 5; // 00000101
    int y = 2; // 00000010
    int p = 2;
    int n = 1;

    // expect: 00000001 (1)
    printf("%d\n", setbits(x,p,n,y));

    // example un-named bit flag struct, NOTICE the colon syntax
    struct {
        unsigned int val_a : 1; // this is 1 bit
        unsigned int val_b : 1;
    } flags;

    // rather than OR'ing a mask, turn on like so
    flags.val_a = flags.val_b = 1;

    // rather than AND'int a mask, turn off like so
    flags.val_a = flags.val_b = 0;

    // rather than a mish$-mash, test expression like so
    if (flags.val_a == 0 && flags.val_b == 0) {
        // here
    }
    return 0;
}
