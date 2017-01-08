/*
 * Write a program to print a set of files, starting each new one on a new page, 
 * with a title and a running page count for each file.
 *
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define FILE_MODE "r"
#define PAGE_SIZE 1000 // 1000 chars is a page

struct PAGE_FORMAT {
    char* title;
    int   page_count;
} page;

FILE* get_file(const char* file_name) {
    FILE* f;
    f = fopen(file_name, FILE_MODE);
    return f;
}

int main(int argc, char* argv[]) {
    int size = argc - 1;

    FILE* files[size];
    if (argc > 1) {
        int i = 1;
        for (i; i < size; i++) {
            files[i] = get_file(argv[i]);
        }
    }

    int i = 0;
    for (i; i < size; i++) {
        char* line;
        while (fgets(line, PAGE_SIZE, files[i]) != NULL) {
            //printf("%s", line);
        }
    }

    return 0;
}
