// 연산자 우선 순위
#include <stdio.h>

int main() {
	int a = 2, b = 3, c = 4, d;
	d = a * b + c >= 8 && c / a - b != 0;
	printf("d = %d\n", d);
	return 0;
}