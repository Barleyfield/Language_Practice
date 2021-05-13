#include <stdio.h>

int main(void) {
	int i, j, k;
	printf("Enter two numbers : ");
	scanf("%d %d", &i, &j);
	k = i + j;
	printf("The result is %d.\n", k);
	return 0;
}