/*
* 코딩마법서 22.1.3 기초테스트 3
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
*     5
*    45
*   345
*  2345
* 12345
*/

#include <cstdio>
int main() {
	int i = 0, j = 0;
	for (i = 5; i >= 1; i--) {
		for (j = 1; j <= 5; j++) {
			if (j >= i)
				printf("%d", j);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}