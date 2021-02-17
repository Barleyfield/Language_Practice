#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, result = 1;
	scanf("%d", &n);
	printf("%d!=(", n);
	for (i = 1; i <= n; i++) {
		printf("%d", i);
		result *= i;
		if (i < n) {
			printf("*");
		}
	}
	printf(")=%d\n", result);
	return 0;
}