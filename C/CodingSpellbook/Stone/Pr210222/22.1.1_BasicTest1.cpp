/*
* 코딩마법서 22.1.1 기초테스트 1
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
* 1
* 12
* 123
* 1234
* 12345
*/

#include <cstdio>
int main() {
	int i = 0, j = 0;
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}