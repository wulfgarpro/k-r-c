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

typedef struct PAGE_FORMAT {
    char* title;
    int   page_count;
} Page;

/* Get all the file pointers.
 */
FILE* get_file(const char* file_name) {
    FILE* f;
    f = fopen(file_name, FILE_MODE);
    return f;
}

/* Page a file to stdout and track page count.
 */
void page_file(char* file_name, FILE* file) {
    Page p; 
    p.title = file_name;
    p.page_count = 0;

    char line[PAGE_SIZE];
    while (fgets(line, PAGE_SIZE, file) != NULL) {
        p.page_count++;
        printf("Title: %s\n\n%s\n\nPage #: %d\n", p.title, line, p.page_count);
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    int size = argc - 1;

    FILE* files[size];
    if (argc > 1) {
        int i = 0;
        for (i; i < size; i++) {
            files[i] = get_file(argv[i+1]);
        }
    }

    int i = 0;
    for (i; i < size; i++) {
        page_file(argv[i+1], files[i]); 
    }

    return 0;
}
