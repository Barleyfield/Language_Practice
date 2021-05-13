// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1055번

#include <stdio.h>
int main() {
	int a = 5, b = 5;
	a *= 3 + b++;
	printf("%d %d", a, b);
	return 0;
}
