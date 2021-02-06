/*
* 코딩마법서 17.2.1 연습문제
* 1개의 양의 정수 N이 주어지면 1부터 N까지의 총합을 가우스 계산을 이용하여 구하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 N이 주어진다.
* Output Form : 1부터 N까지의 총합을 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0;
	scanf("%d", &n);
	printf("%d", (1+n)*n/2);
	return 0;
}