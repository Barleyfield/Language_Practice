/*
* 코딩마법서 15.1 복합 if문
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a;
	scanf("%d", &a);
	if (a % 4 == 0) {
		printf("Mod is 0 \n");
	}
	else if (a % 4 == 1) {
		printf("Mod is 1\n");
	}
	else if (a % 4 == 2) {
		printf("Mod is 2\n");
	}
	return 0;
}