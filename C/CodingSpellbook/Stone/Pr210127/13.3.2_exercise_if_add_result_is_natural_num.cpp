/*
* 코딩마법서 13.3.2 연습문제
* 2개의 정수 A,B가 주어지면 if else문을 이용하여 두 정수의 합이 자연수인지를 판별하는
* 프로그램을 작성하라.
* Input Form : 첫째 줄에 1개의 공백으로 분리되어 -100 이상 100 이하의 2개의 정수가 주어진다.
* Output Form : 두 정수의 합이 자연수이면 'Natural Number'를, 자연수가 아니면
* '0 or Negative Number'를 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if ((a + b) > 0) {
		printf("Natural Number\n");
	}
	else {
		printf("0 or Negative Number");
	}
	return 0;
}