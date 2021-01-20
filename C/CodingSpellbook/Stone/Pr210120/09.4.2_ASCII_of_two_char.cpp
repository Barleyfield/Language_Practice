/*
* 코딩마법서 09.4.2 연습문제
* 2개의 단일 문자가 주어진다. 주어진 두 문자의 ASCII 값을 출력하는 프로그램을 작성하라.
* Input Form : 영문 알파벳 2개가 1개의 공백으로 분리하여 첫째 줄에 주어진다.
* Output Form : 1번째 주어진 문자와 ASCII 값을 콜론(:)으로 구분하여 첫째 줄에 출력하고,
*				2번째 주어진 문자와 ASCII 값을 콜론(:)으로 구분하여 둘째 줄에 출력하라.
*/

#pragma warning(disable:4996)
#include <cstdio>

int main() {
	char a, b;
	scanf("%c %c", &a, &b);
	printf("%c:%d\n", a, a);
	printf("%c:%d\n", b, b);
	return 0;
}