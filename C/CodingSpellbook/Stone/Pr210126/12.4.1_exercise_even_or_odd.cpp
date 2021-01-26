/*
* 코딩마법서 12.4.1 연습문제
* 1개의 양의 정수 A가 주어지면 주어진 정수가 짝수인지 홀수인지 판별하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 1개의 양의 정수 A가 주어진다.
* Output Form : 주어진 정수가 짝수이면 even, 홀수이면 odd를 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0;
	scanf("%d", &a);
	if (a % 2 == 0) {
		printf("even\n");
	}
	else {
		printf("odd\n");
	}
	return 0;
}