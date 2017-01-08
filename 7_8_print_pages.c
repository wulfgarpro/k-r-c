/*
 * Write a program to print a set of files, starting each new one on a new page, 
 * with a title and a running page count for each file.
 *
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define FILE_MODE "r"
#define PAGE_SIZE 80 // 80 lines is a page

typedef struct PAGE_FORMAT {
    char* title;
    int   page_count;
} Page;

/* Get all the file pointers.
*/
FILE* get_file(const char* file_name) {
    FILE* f;
    f = fopen(file_name, FILE_MODE);
    if (f == NULL) {
        fprintf(stderr, "Error opening file %s.\n", file_name);
        exit(1);
    }
    return f;
}

/* Page a file to stdout and track page count.
*/
void page_file(char* file_name, FILE* file) {
    Page p = { 
        file_name,
        1,
    };

    bool start = true;
    int line_count = 0, c = 0;

    while ((c = fgetc(file)) != EOF) {
        if (start && line_count == 0) {
            printf("Title:    %s-------", p.title);
            printf("\n------- \n\n");
            start = false;
        }

        putchar(c); // stdout

        if (c == '\n')
            line_count += 1; 

        if (line_count == PAGE_SIZE) {
            printf("\nPage #: %d-------", p.page_count);
            printf("\n------- \n\n");
            p.page_count++;
            line_count = 0;
            start = true;
        }

        if (ferror(file)) {
            fprintf(stderr, "Error reading from %s.\n", file_name);
            exit(2);
        }

        if (ferror(stdout)) {
            fprintf(stderr, "Error writing to stdout.\n");
            exit(2);
        }
    }

    printf("\nPage #: %d-------", p.page_count);
    printf("\n------- \n\n");

    fclose(file);
}

int main(int argc, char* argv[]) {
    int size = argc - 1;

    FILE* files[size];
    if (argc == 1) {
        fprintf(stderr, "No files specified, nothing to do.\n");
    } else {
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
