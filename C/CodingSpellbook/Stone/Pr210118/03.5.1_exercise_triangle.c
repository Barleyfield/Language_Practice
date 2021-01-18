/*
* 코딩마법서 03.5 연습문제
* 삼각형 모양을 출력하는 프로그램 작성
* 약간 변형 : 숫자 넣으면 그 숫자만큼 출력하기
*/

#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	int n = 0, i = 0, j = 0;
	printf("n 입력 : ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("#");
		}
		printf("\n");
	}

	return 0;
}