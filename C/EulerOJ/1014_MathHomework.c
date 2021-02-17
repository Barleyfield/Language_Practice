#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, result = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		result *= i;
	}
	printf("%d\n", result);
}