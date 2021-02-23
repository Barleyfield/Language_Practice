/*
* 코딩마법서 22.1.8 기초테스트 8
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
* 123456789
*  3456789
*   56789
*    789
*     9
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		// 왼쪽 삼각형 공백
		for (j = 1; j < i; j++) {
			printf(" ");
		}
		// 왼쪽 삼각형 내용
		// 시작은 끝나는 숫자인 (n - 2 + i)에서 (n-i) 작은 숫자. 그래야 현재 줄 번호(i)가 늘어날수록
		// 줄에서 표시하는 숫자의 개수가 감소 -> 그런데 이대로 하면 01234 2345 이렇게 출력되므로,
		// 끝나는 숫자에서 1을 늘려서 (n - 1 + i) - (n - i)에서 시작하도록 수정

		// n-2+i까지여야 4,5,6,7로 끝날 수 있음. n-1+i면 5,6,7,8로 끝나서 도형 안이뻐짐
		for (j = (n - 1 + i) - (n - i); j <= (n - 2 + i); j++) {
			printf("%d", j);
		}
		// 오른쪽 삼각형 내용
		// 왼쪽 삼각형 내용 각 줄의 마지막 숫자+1부터 시작 숫자로 놓고(예: 5로 끝나므로 6부터 시작), 2n-1까지 증가
		for (j = (n - 1 + i); j <= (2 * n - 1); j++) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}