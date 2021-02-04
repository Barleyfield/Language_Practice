#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int i = 0, n = 0, result = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		result += ((i + 1) * (n - i));
	}
	printf("%d\n", result);
	return 0;
}