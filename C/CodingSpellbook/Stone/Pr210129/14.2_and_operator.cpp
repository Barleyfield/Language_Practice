/*
* 코딩마법서 14.2 AND 연산자
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	if (a > 0 && b > 0) {
		printf("a>0 and b>0\n");
	}
	else {
		printf("a<=0 or b<=0\n");
	}
	return 0;
}