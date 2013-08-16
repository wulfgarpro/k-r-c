#include <stdio.h>

/*
 * 1.5.3 Line Counting
 *
 * Exercise 1-8
 */
int main(void) {
	int c, nl = 0;

	while((c = getchar()) != EOF) {
		if(c == '\n'){
			nl++;
		}
		if(c == '\t'){
			nl++;
		}
		if(c == ' '){
			nl++;
		}
	}
    printf("%d\n", nl);

	return 0;
}
