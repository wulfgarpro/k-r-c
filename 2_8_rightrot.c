#include <stdio.h>
#include <limits.h>

char rightrot(char x, char n) {
    // 00000101
    // go_left is 8 - 2 = 6 (low order to high order)
    char go_left = (sizeof(x) * CHAR_BIT) - n;
    return ((x << go_left) | (x >> n)); 
}

int main(void) {
    char x = 5; // 00000101 
                // 10000010 rotate 1
                // 01000001 rotate 2 (65)
    char n = 2;

    printf("%d\n", rightrot(x, n));

    return 0;
}
