/*
* 코딩마법서 16.4 구간의 합 구하기
*/

#include <cstdio>
int main() {
	int i = 0, s = 0;
	for (i = 1; i <= 5; i++) {
		s += i;
	}
	printf("%d\n", s);
	return 0;
}