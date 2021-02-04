#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int i = 0, n = 0, result = 0;
	scanf("%d", &n);
	for (i = 1; i <= 100; i++) {
		result += (n*i);
	}
	printf("%d\n", result);
	return 0;
}