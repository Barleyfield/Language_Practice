/*
* 코딩마법서 22.1.7 기초테스트 7
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
*     9
*    789
*   56789
*  3456789
* 123456789
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		// 왼쪽 삼각형 공백
		for (j = n; j > i; j--) {
			printf(" ");
		}
		// 왼쪽 삼각형 내용
		// 2(n-i)+1부터 시작해야 9,7,5,3,1처럼 아랫줄로 내려갈수록 시작숫자가 2씩 감소
		for (j = 2 * (n - i) + 1; j <= (2 * n - i); j++) {
			printf("%d", j);
		}
		// 오른쪽 삼각형 내용
		// 2n-i+1부터 시작해야 둘째 줄부터 9, 89, 789처럼 내려올 수 있음
		if (n > 1) {
			for (j = (2 * n - i + 1); j <= (2 * n - 1); j++) {
				printf("%d", j);
			}
		}

		printf("\n");
	}
	return 0;
}