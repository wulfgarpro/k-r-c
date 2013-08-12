#include <stdio.h>

#define SIZE 26

/*
 * This program prints a character frequency histogram horizontally.
 */
int main() {
    int characters[25], frequencies[25];

    // only supports characters
    characters[0] = 'a';
    characters[1] = 'b';
    characters[2] = 'c';
    characters[3] = 'd';
    characters[4] = 'e';
    characters[5] = 'f';
    characters[6] = 'g';
    characters[7] = 'h';
    characters[8] = 'i';
    characters[9] = 'j';
    characters[10] = 'k';
    characters[11] = 'l';
    characters[12] = 'm';
    characters[13] = 'n';
    characters[14] = 'o';
    characters[15] = 'p';
    characters[16] = 'q';
    characters[17] = 'r';
    characters[18] = 's';
    characters[19] = 't';
    characters[20] = 'u';
    characters[21] = 'v';
    characters[22] = 'w';
    characters[23] = 'x';
    characters[24] = 'y';
    characters[25] = 'z';

    // init all to 0
    int a;
    for(a = 0; a < SIZE; a++){
        frequencies[a] = 0;
    }

    int c, k;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            for(k = 0; k < SIZE; ++k){
                if(characters[k] == c){
                    frequencies[k]++;
                }
            }
        }
    }

    int i, j;
    for (i = 0; i < SIZE; ++i) {
        printf("%c: ", characters[i]);
        for (j = 0; j < frequencies[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}