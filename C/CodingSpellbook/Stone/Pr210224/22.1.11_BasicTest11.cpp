/*
* 코딩마법서 22.1.11 기초테스트 11
* 아래와 같이 문자를 출력하여라
* A
* AB
* ABC
* ABCD
* ABCDE
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int i = 0, j = 0;
	char c1;
	char c_default = 'A';
	scanf("%c", &c1);
	for (i = 0; i <= (c1 - c_default); i++) {
		for (j = 0; j <= i; j++) {
			printf("%c", c_default + j);
		}
		printf("\n");
	}
	return 0;
}