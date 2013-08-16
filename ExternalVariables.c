#include <stdio.h>

int age; // set it external to function (global)

void setage();

/*
 * 1.10 External Variables and Scope
 */
int main(void) {
    extern int age;

    setage(); // this sets the external variable

    printf("Age is: %d\n", age); // this confirms it has been set in the setage function

    return 0;
}

void setage() {
    extern int age; // this is not a local variable
    age = 26;
}
