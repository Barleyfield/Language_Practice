/*
* 코딩마법서 13.2 if else문과 동등 비교
*/

#pragma warning(disable:4996)
#include <cstdio>

int main() {
	int a = 0;
	scanf("%d", &a);
	if (a % 3 == 0) {
		printf("Multiples of 3\n");
	}
	else {
		printf("Not a multiples of 3\n");
	}
	return 0;
}