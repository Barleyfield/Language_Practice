/*
* 코딩마법서 20.1 팩토리얼
*/

#include <cstdio>
int main() {
	int i = 0, fact = 1;
	for (i = 1; i <= 5; i++) {
		fact *= i;
	}
	printf("%d\n", fact);
	return 0;
}