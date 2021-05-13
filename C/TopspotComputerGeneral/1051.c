// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1051번

#include <stdio.h>
int foo(int a, int* b) {
	int c;
	*b = a + 1;
	c = a - 1;
	return c;
}

void main() {
	int a = 5;
	int b = 3;
	int c = 0;
	b = foo(a, &c);
	c = foo(b, &a);
	printf("a=%d, b=%d, c=%d\n", a, b, c);
}