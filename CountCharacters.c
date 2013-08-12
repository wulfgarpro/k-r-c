#include <stdio.h>

/*
 * 1.5.2 Character Counting
 */
int main() {
    double nc;
    char c;

    for(nc = 0; (c=getchar() != EOF); ++nc){
        printf("%c\n", c);
    }
    printf("%.0f\n", nc);
    return 0;
}
