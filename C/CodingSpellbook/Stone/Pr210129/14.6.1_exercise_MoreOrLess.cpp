/*
* 코딩마법서 14.6.1 연습문제
* 1개의 정수 A가 주어졌을 때, 주어진 정수가 1 이상 10 이하이면 '1 or more and 10 or less'를,
* 만일 그렇지 않다면 'less than 1 or greater than 10'을 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 -100 이상 100 이하의 1개의 정수 A가 주어진다.
* Output Form : 주어진 정수가 1 이상 10 이하이면 '1 or more and 10 or less'를, 그렇지 않다면
*               'less than 1 or greater than 10'을 출력
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0;
	scanf("%d", &a);
	if (a >= 1 && a <= 10) {
		printf("1 or more and 10 or less");
	}
	else {
		printf("less than 1 or greater than 10");
	}
	return 0;
}