#include <stdio.h>

#define COLS 4 // def of tab stop
#define LIM 10

void getinput(void);
//void displaycols(int cols, int nc);

int main(void) {
    getinput();
    return 0;
}

void getinput() {
    char chars[LIM];

    char c;
    int i = 0, nc = 0;
    for(;(c = getchar()) && c != EOF; i++){
        if(c == '\t') {
            //int tabpos = i;
            int diff = (nc - (nc + i));

            for(;diff > 0; diff--) {
                chars[diff] = ' ';
            }
            //chars[]
            //displaycols(COLS);
        } else {
            chars[i] = c;
            nc++;
        }
    }

    int k;
    for(k = 0; k < nc; k++) {
        printf("%c", chars[k]);
    }
}

/*void displaycols(int cols, int nc) {
    int i;
    for(i = 0; i < cols; i++) {
        putchar(' ');
    }
}*/