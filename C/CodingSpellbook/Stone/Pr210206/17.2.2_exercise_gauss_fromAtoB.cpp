/*
* 코딩마법서 17.2.2 연습문제
* 2개의 양의 정수 A,B가 주어지면 A부터 B까지의 총합을 가우스 계산을 이용하여 구하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 A,B가 1개의 공백으로 분리되어 주어진다. (1≤A≤B≤100)
* Output Form : A부터 B까지의 총합을 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a + b) * (b - a + 1) / 2);
	return 0;
}