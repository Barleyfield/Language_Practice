#include <stdio.h>

int main() {
	printf("1-2+3-4+5...+99-100 : ");
	int i = 0, sum = 0;
	for (i = 1; i <= 100; i++) {
		sum = (i % 2 == 1) ? (sum + i) : (sum - i);
	}
	printf("%d\n", sum);

	return 0;
}