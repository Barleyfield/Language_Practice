#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, result_even = 0, result_odd = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		// 짝수
		if (i % 2 == 0) {
			result_even += i;
		} else {
			result_odd += i;
		}
	}
	printf("%d\n%d\n", result_even, result_odd);
}