/*
 * Compare two files, print the first line where they differ.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 4096

int main(int argc, char* argv[]) {
    char line_1[BUFFER];
    char line_2[BUFFER];

    if (argc != 3) {
        printf("%s\n", "Try 'compare file1 file2'");
        return -1;
    }

    FILE* f = fopen(argv[1], "r");
    FILE* s = fopen(argv[2], "r");
    if (f == NULL || s == NULL) {
        perror("Error opening file");
        return -1;
    }

    while ((fgets(line_1, BUFFER, f) != NULL) && (fgets(line_2, BUFFER, s) != NULL)) {
        if (strcmp(line_1, line_2) != 0) {
            printf("1\t%s2\t%s", line_1,line_2); 
        }
    }

    fclose(f);
    fclose(s);

    return 0;
}
