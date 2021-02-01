#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n1 = 0, n2 = 0, n3 = 0;
	scanf("%d %d %d", &n1, &n2, &n3);
	// 같은 숫자 3개
	if ((n1 == n2) && (n2 == n3) && (n1 == n3)) {
		printf("%d\n", (n1 * 1000) + 10000);
	}
	// 같은 숫자 2개
	else if ((n1 == n2) || (n2 == n3) || (n1 == n3)) {
		if( (n1 == n2) || (n2 == n3))
			printf("%d\n", (n2 * 100) + 1000);
		else if ((n2 == n3) || (n1 == n3))
			printf("%d\n", (n3 * 100) + 1000);
	}
	// 모두 다른 숫자
	else {
		// n1이 제일 클 경우
		if ((n1 >= n2) && (n2 >= n3))
			printf("%d\n", n1 * 100);
		// n2가 제일 클 경우
		else if ((n2 >= n1) && (n2 >= n3))
			printf("%d\n", n2 * 100);
		// n3이 제일 클 경우
		else if ((n3 >= n1) && (n3 >= n2))
			printf("%d\n", n3 * 100);
	}

	return 0;
}