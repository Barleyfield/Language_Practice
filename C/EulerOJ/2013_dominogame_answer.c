#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n, i, j, sum = 0;
	scanf("%d", &n);
	for (i = 0; i <= n; i++)		// 밑의 눈
		for (j = 0; j <= i; j++)	// 위의 눈
			sum += (i + j);

	printf("%d\n", sum);
	return 0;
}