/*
* 코딩마법서 03.5 연습문제
* 다이아몬드 모양을 출력하는 프로그램 작성
* 약간 변형 : 숫자 넣으면 그 숫자만큼 출력하기
*/

#pragma warning(disable:4996)
#include <stdio.h>
int main() {
	/*
	* n : 입력받는 수
	* i : 전체 반복문 제어 변수
	* j : # 작성 반복문 제어 변수
	* k : 공백 작성 반복문 제어 변수
	*/
	int n = 0, i = 0, j = 0, k = 0;
	printf("n 입력 : ");
	scanf("%d", &n);

	// 윗줄
	for (i = 1; i <= n; i++) {
		for (k = i; k <= (n - 1); k++) {
			// 공백은 4,3,2,1과 같이 내림차순으로 감소
			printf(" ");
		}
		for (j = 1; j <= (2*i - 1); j++) {
			// #은 1,3,5,7처럼 홀수 개로 증가하므로 j 최대 범위도 홀수 범위로.
			printf("#");
		}
		for (k = i; k <= (n - 1); k++) {
			printf(" ");
		}
		printf("\n");
	}

	// 아랫줄
	for (i = 1; i <= n-1; i++) {
		for (k = (n - i); k <= (n - 1); k++) {
			printf(" ");
		}
		for (j = 1; j <= (2*(n-i) - 1); j++) {
			// 아랫줄이므로 최대 # 개수-2부터 2개씩 적어지도록 해야 한다.
			printf("#");
		}
		for (k = (n - i); k <= (n - 1); k++) {
			printf(" ");
		}
		printf("\n");
	}



	return 0;
}