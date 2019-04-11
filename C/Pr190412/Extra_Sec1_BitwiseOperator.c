// 비트 연산자
#include <stdio.h>

int main() {
	int a = 5, b = 7, c, d, e, f;
	c = a & b;
	d = a | b;
	e = a ^ b;
	f = ~b;
	a = a >> 1;
	b = b << 3;
	printf("a: %d, b: %d, c: %d, d: %d, e: %d, f: %d\n", a, b, c, d, e, f);
}