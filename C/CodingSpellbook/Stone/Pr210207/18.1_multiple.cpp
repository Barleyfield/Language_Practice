/*
* 코딩마법서 18.1 배수
*/

#include <cstdio>
int main() {
	int i = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 3 == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}