/*
* 코딩마법서 13.3 여러 개의 if문
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a;
	scanf("%d", &a);
	if (a > 0)
		printf("Positive Integer\n");
	if (a < 0)
		printf("Negative Integer\n");
	if (a == 0)
		printf("Zero\n");

	return 0;
}