#include <stdio.h>

/* Some tests with typedef and function pointer after reading
 * chp-6 
 */

/* Using a hash define like this doesn't result in correct
 * fn ptr syntax as hoped; this is where typedef is a
 * better utility; that is, you can't use PTF to refer to
 * our function pointer like you can with a typedef 
 */
#define PTF int (*)(int,int)
typedef int (*PTF_t)(int, int);

void test(PTF_t fn) {
    printf("test called\n");
    printf("calling fn\n");
    printf("fn: %d\n", fn(1,1));
}

int myRealFunction(int a, int b) {
    return a+b;
}

int main(void) {
    // Using the typedef'd version
    PTF_t myPointerToFunction = &myRealFunction;
    test(myPointerToFunction);

    // Non typedef'd version requires this; less readable
    int (*PTF2_t)(int,int) = &myRealFunction;
    // PTF2_t another = &myRealFunction;    /* this is an error */
    test(PTF2_t);

    return 0;
}
