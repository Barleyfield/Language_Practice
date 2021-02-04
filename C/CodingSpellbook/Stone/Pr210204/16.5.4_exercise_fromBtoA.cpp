/*
* 코딩마법서 16.5.4 연습문제
* 2개의 양의 정수 B,A가 주어지면 B부터 A까지 출력하는 프로그램을 작성하라.
* Input Form : 첫째 줄에 1 이상 100 이하의 양의 정수 B와 A가 1개의 공백으로 분리되어 주어진다. (1≤A≤B≤100)
* Output Form : B부터 A까지의 정수를 큰 수부터 작은 수 순으로 각각 1개의 공백으로 분리하여 첫째 줄에 출력하라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0, i = 0;
	scanf("%d %d", &b, &a);
	for (i = b; i >= a; i--) {
		printf("%d ", i);
	}
	return 0;
}