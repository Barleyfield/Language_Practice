#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", 1+(6*((1+(n-1))*(n-1)/2)));
	return 0;
}