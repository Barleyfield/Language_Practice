/*
* 코딩마법서 16.5.1 연습문제
* 1개의 양의 정수 N이 주어지면 1부터 N까지 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 N이 주어진다.
* Output Form : 1부터 N까지의 정수를 작은 수부터 큰 수 순으로 각각 1개의 공백으로 분리하여 출력하라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}
