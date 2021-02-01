/*
* 코딩마법서 15.2 복합 if문과 else
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0;
	scanf("%d", &a);
	if (a > 0) {
		printf("Positive Number\n");
	}
	else if (a < 0) {
		printf("Negative Number\n");
	}
	else {
		printf("Zero\n");
	}
	return 0;
}