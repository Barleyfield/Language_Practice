#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, result = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		result += (i * i);
	}
	printf("%d\n", result);
	return 0;
}