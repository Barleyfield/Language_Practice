#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, result = 0;
	scanf("%d", &n);
	// 1부터 N 미만
	for (i = 1; i < n; i++) {
		if ((i%3==0) || (i%5==0)) {
			result += i;
		}
	}
	printf("%d\n", result);
	return 0;
}