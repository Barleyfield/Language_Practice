/*
* 코딩마법서 13.1 if else문과 대소 비교
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0;
	scanf("%d", &a);
	if (a > 10) {
		printf("a>10\n");
	}
	else {
		printf("a<=10\n");
	}
	return 0;
}