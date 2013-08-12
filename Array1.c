#include <stdio.h>

#define SIZE 100

/*
 * This program prints a word size histogram horizontally.
 */
int main() {
    int c, i, j, charCount = 0, word_number = 0, word[SIZE];

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            ++charCount;
        }
        else {
            word[word_number] = charCount;
            charCount = 0;
            ++word_number;
        }

    }

    for (i = 0; i < word_number; ++i) {
        printf("%d: ", i+1);
        for (j = 0; j < word[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}