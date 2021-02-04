/*
* 코딩마법서 16.5.3 연습문제
* 2개의 양의 정수 A,B가 주어지면 A부터 B까지 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 A와 B가 1개의 공백으로 분리되어 주어진다. (1≤A≤B≤100)
* Output Form : A부터 B까지의 정수를 작은 수부터 큰 수 순으로 각각 1개의 공백으로 분리하여 첫째 줄에 출력하라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0, i = 0;
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
	
}