/*
* 코딩마법서 22.1.6 기초테스트 6
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
* 123456789
*  1234567
*   12345
*    123
*     1
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		// 왼쪽 삼각형 공백
		for (j = 2; j <= i; j++) {
			printf(" ");
		}
		// 왼쪽 삼각형 숫자
		for (j = 1; j <= (n+1-i); j++) {
			printf("%d", j);
		}
		// 오른쪽 삼각형
		if (n > 1) {
			for (j = (n + 2) - i; j <= (2*(n+1-i)-1); j++) {
				printf("%d", j);
			}
		}
		printf("\n");
	}
	return 0;
}