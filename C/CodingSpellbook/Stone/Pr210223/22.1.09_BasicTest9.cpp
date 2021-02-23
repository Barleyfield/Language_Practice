/*
* 코딩마법서 22.1.9 기초테스트 9
* 아래와 같이 문자를 출력하여라
* A
* B
* C
* D
* E
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	char c1;
	char c_default = 'A';
	int i = 0;
	// 원하는 문자 입력 시 A부터 그 문자까지 출력
	scanf("%c", &c1);

	for (i = 0; i <= (c1 - c_default); i++) {
		printf("%c", c_default + i);
		printf("\n");
	}
	return 0;
}