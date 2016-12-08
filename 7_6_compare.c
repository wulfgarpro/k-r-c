/*
 * Compare two files, print the first line where they differ.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if(argc > 2) {
        FILE*  first = fopen(argv[1], "r");
        FILE* second = fopen(argv[1], "r");
    } else {
        printf("%s\n", "Try 'compare file1 file2'");
        return -1;
    }
    return 0;
}
