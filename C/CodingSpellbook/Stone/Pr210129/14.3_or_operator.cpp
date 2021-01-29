/*
* 코딩마법서 14.3 OR 연산자
*/
#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if (a % 2 == 0 || b % 2 == 0) {
		printf("a or b is even number\n");
	}
	else {
		printf("a and b is odd number\n");
	}
	return 0;
}