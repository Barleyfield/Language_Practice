/*
* 코딩마법서 14.5 연산자
*/
#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0;
	scanf("%d", &a);
	if (!(a % 2)) {
		printf("a is even\n");
	}
	else {
		printf("a is odd\n");
	}
	return 0;
}