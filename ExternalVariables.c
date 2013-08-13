#include <stdio.h>

int age;

void setage();

int main(void) {
    extern int age;

    setage(); // this sets the external variable

    printf("Age is: %d\n", age); // this confirms it has been set in the setage function

    return 0;
}

void setage() {
    extern int age;
    age = 26;
}