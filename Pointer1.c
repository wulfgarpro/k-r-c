#include <stdio.h>

/*
 * Basic pointer example
 */
int main(void) {
    int foo = 1;
    int* foo_ptr; // declare pointer

    foo_ptr = &foo; // assign int pointer variable to address of foo

    printf("%d\n", *foo_ptr); // dereference pointer variable to get foo value

    *foo_ptr = 2; // dereference pointer variable to change value of foo variable

    printf("%d\n", *foo_ptr);
    printf("%d\n", foo); // print original variable, not the pointer

    return 0;
}