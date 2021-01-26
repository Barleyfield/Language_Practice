/*
* 코딩마법서 12.2 if문을 이용한 동등 비교
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a != b) {
		printf("%d != %d\n", a, b);
	}
	return 0;
}