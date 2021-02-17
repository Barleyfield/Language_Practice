/*
* 코딩마법서 20.2 연습문제
* 1개의 양의 정수 N이 주어지면 N! 과정을 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 N이 주어진다.
* Output Form : "입력과 출력의 예"와 같이 N! 과정을 첫째 줄에 출력하여라
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("%d", i);
		if (i < n) {
			printf("*");
		}
	}
	return 0;
}