/*
* 코딩마법서 21.3.5 연습문제
* 아래와 같이 출력하기
*     #
*    ###
*   #####
*  #######
* #########
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int i = 0, j = 0, n = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < (n - i - 1); j++) {
			printf(" ");
		}
		for (j = 0; j < (i + 1); j++) {
			printf("#");
		}
		// 윗부분까지 하면 삼각형 중에서 왼쪽 완성
		// 아래부분 : 삼각형의 오른쪽 부분
		for (j = 0; j < i; j++) {
			printf("#");
		}

		printf("\n");
	}
	return 0;
}