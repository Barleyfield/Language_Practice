/*
* 코딩마법서 14.6.2 연습문제
* 2개의 정수 A,B가 주어졌을 때, 두 정수 중에서 음수가 있다면 'One of A or B is negative number'를,
* 만일 그렇지 않다면 'both A and B are zero or more'를 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1개의 공백으로 분리되어 -100 이상 100 이하의 2개의 정수 A,B가 주어진다.
* Output Form : (문제와 동일)
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if (a < 0 || b < 0) {
		printf("One of A or B is negative number\n");
	}
	else {
		printf("Both A and B are zero or more\n");
	}
	return 0;
}
