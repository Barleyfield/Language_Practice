/*
* 코딩마법서 19.1 완전수
*/

#include <cstdio>
int main() {
	int i = 0, num = 0, sum = 0;
	num = 28;
	for (i = 1; i <= num - 1; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}

	if (sum == num) {
		printf("Perfect Number!\n");
	}
	return 0;
}