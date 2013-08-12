#include <stdio.h>

#define MAXLINE 1000 // impose limit on characters

int getLine(char line[], int lim);
void copy(char to[], char from[]);

/*
 * 1.9 Character Arrays
 *
 * Exercise 1-16
 */
int main()
{
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    printf("This program only supports MAXLINE input characters.\n");

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0){
        //printf("%d -> ", max);
        printf("%d -> %s", max, longest); // print a character array as a string
    }

    return 0;
}

int getLine(char line[], int lim)
{
    int i, c;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
        if(i < lim-1) {
            line[i] = c;
        } else {
            ++i; // for exercise 1-16, print arbitrary size, but don't add characters over MAXLINE to array
        }

    }

    if(c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0'; // null character to mark end of array

    return i;
}

void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0') {
        ++i;
    }
}
