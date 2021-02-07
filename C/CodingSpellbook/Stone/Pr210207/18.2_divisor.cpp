/*
* 코딩마법서 18.2 약수
*/

#include <cstdio>
int main() {
	int i = 0;
	for (i = 1; i <= 12; i++) {
		if (12 % i == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}