/*
* 코딩마법서 16.5.2 연습문제
* 1개의 양의 정수 N이 주어지면 N부터 1까지 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 N이 주어진다.
* Output Form : N부터 1까지의 정수를 큰 수부터 작은 수 순으로 각각 1개의 공백으로 분리하여 출력하라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0;
	scanf("%d", &n);
	for (i = n; i >= 1; i--) {
		printf("%d ", i);
	}
	return 0;
}