#include <stdio.h>

/*
 * 1.5.2 Count Characters
 */
int main(void) {
	double nc;
	while(getchar() != EOF) {
		++nc;
	}

	printf("%.0f\n", nc);
	return 0;
}
