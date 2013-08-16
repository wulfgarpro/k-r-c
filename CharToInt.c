#include <stdio.h>
#include <limits.h>

/*
 * Example of converting a string (char array) to an integer.
 */
int main(void) {
    char s[5] = {'1', '2', '3', '4', '5'};

    int i, n;

    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0'); // coersion
    }

    printf("%d\n", n);

    return 0;
}
