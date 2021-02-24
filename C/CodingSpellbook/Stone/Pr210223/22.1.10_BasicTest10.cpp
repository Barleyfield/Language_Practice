/*
* 코딩마법서 22.1.10 기초테스트 10
* 아래와 같이 문자를 출력하여라
*     A
*    BBB
*   CCCCC
*  DDDDDDD
* EEEEEEEEE
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	char c1;
	char c_default = 'A';
	int i = 0, j = 0;
	scanf("%c", &c1);
	for (i = 0; i <= (c1 - c_default); i++) {
		// 삼각형 왼쪽 공백
		for (j = ((c1 - c_default) - i - 1); j >= 0; j--) {
			printf(" ");
		}
		// 삼각형 내용
		// j의 최대 범위를 (2 * (i+1) - 1)로 해줘야 처음부터 A가 출력된다. 2*i-1로 하면 B 1개부터 출력
		for (j = 0; j < (2 * (i+1) - 1); j++) {
			printf("%c", c_default + i);
		}
		printf("\n");
	}
	return 0;
	
}