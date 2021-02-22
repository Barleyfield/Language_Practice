/*
* 코딩마법서 22.1.4 기초테스트 4
* 2중 for문을 이용하여 "출력의 예"와 같이 출력하는 프로그램을 작성하라.
* 12345
*  2345
*   345
*    45
*     5
*/

#include <cstdio>
int main() {
	int i = 0, j = 0;
	for (i = 1; i <= 5; i++) {
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