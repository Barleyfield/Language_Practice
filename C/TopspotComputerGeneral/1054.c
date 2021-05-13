// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1054번
#include <stdio.h>

int my(int i, int j) {
	if (i < 3) i = j = 1;
	else {
		i = i - 1;
		j = j - i;
		printf("%d, %d, ", i, j);
		return my(i, j);
	}
}

int main() {
	my(5, 14);
	return 0;
}