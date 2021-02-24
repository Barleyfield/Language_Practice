/*
* 코딩마법서 22.1.12 기초테스트 12
* 아래와 같이 문자를 출력하여라
*     A
*    BCD
*   CDEFG
*  DEFGHIJ
* EFGHIJKLM
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int i = 0, j = 0;
	char c1;
	char c_default = 'A';
	scanf("%c", &c1);
	for (i = 0; i <= (c1 - c_default); i++) {
		// 삼각형 공백
		// i+1을 붙인 이유는 그냥 i만 쓰면 i 시작값이 0이기 때문에 공백 개수가 5,4,3,2,1순으로 나온다.
		for (j = (c1 - c_default) - (i+1); j >= 0; j--) {
			printf(" ");
		}

		// 삼각형 내용
		for (j = (i + 1); j <= (3 * i + 1); j++) {
			printf("%c", c_default + (j-1));	// j-1를 하지 않으면 A가 아니라 B부터 시작한다.
		}
		printf("\n");
	}
	return 0;
}