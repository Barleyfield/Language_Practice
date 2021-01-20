/*
* 코딩마법서 09.4.1 연습문제
* 3개의 정수 A,B,C,가 주어진다. 주어진 세 정수의 사칙 연산을 계산하는 프로그램을 작성하라.
* Input Form : 1 이상 100 이하의 정수 A,B,C가 1개의 공백으로 분리하여 첫째 줄에 주어진다.
* Output Form : 첫째 줄에는 세 정수의 덧셈 연산을 출력하고, 둘째 줄에는 뺄셈 연산을,
*               셋째 줄에는 곱셈 연산을, 넷째 줄에는 나눗셈 연산을 "입력과 출력의 예"
*               와 같은 형식으로 각 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0, c = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a + b + c);
	printf("%d-%d-%d=%d\n", a, b, c, a - b - c);
	printf("%d*%d*%d=%d\n", a, b, c, a * b * c);
	printf("%d/%d/%d=%d\n", a, b, c, a / b / c);
	return 0;
}