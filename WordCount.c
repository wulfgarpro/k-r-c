#include <stdio.h>

/*
 * 1.5.4 Word Counting
 */
int main() {
    int c;

    while((c = getchar()) != EOF) {
        if(c == '\t' || c == ' ' || c == '\n'){
            printf("\n");
        } else {
            printf("%c", c);
        }
    }
    return 0;
}
