/*
* 코딩마법서 21.3.1 연습문제
* 아래와 같이 출력하기
* #
* ##
* ###
* ####
* #####
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("#");
		}
		printf("\n");
	}
	return 0;
}