#include <stdio.h>

/*
 * 1.5.1 File Copying
 */
int main() {
    int c;

    c = getchar();
    while(c != EOF) {
        putchar(c);
        c = getchar();
    }

    // printf("%i", EOF);
    return 0;
}
