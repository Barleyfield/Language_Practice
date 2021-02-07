/*
* 코딩마법서 18.3.3 연습문제
* 1개의 양의 정수 N이 주어지면 N에 대한 약수의 개수를 구하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 N이 주어진다.
* Output Form : N에 대한 약수의 개수를 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, result = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			result++;
		}
	}
	printf("%d\n", result);
	return 0;
}