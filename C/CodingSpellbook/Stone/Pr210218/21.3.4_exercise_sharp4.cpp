/*
* 코딩마법서 21.3.4 연습문제
* 아래와 같이 출력하기
* #####
*  ####
*   ###
*    ##
*     #
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int n = 0, i = 0, j = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for(j = 0; j < i; j++) {
			printf(" ");
		}
		for (j = 0; j < (n - i); j++) {
			printf("#");
		}
		printf("\n");
	}
	return 0;
}