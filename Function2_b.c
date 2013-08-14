#include <stdio.h>

// function prototype for use in this source file # see Function2_a.c
int add(int a, int b);

int main(void){
    int a = 1;
    int b = 2;

    printf("a + b is %d\n", add(a,b));

    return 0;
}