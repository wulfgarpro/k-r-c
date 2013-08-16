#include <stdio.h>

#define COLS    4 // def of tab stop
#define LIM     1024

/*
 * This program replaces tabs with the appropriate amount of spaces to reach a tab stop.
 *
 * Exercise 1-20
 */

int GetLine(char s[], int lim);

int CalculateNumberOfSpaces(int offset, int tabsize)
{
    return tabsize - (offset % tabsize); // mod here gives us the cyclic remainder from our position in the line, then we calc the difference (the number of spaces)
}

int GetLine(char s[], int lim)
{
    int i, c;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main(void)
{
    char buffer[LIM];

    int i, j, k, l;
    while(GetLine(buffer, LIM) > 0) {
        for(i = 0, l = 0; buffer[i] != '\0'; i++) {
            if(buffer[i] == '\t') {
                j = CalculateNumberOfSpaces(l, COLS); // l tracks our position in the line
                for(k = 0; k < j; k++) {
                    putchar(' ');
                    l++;
                }
            } else {
                putchar(buffer[i]);
                l++;
            }
        }
    }
    return 0;
}
