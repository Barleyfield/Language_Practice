// 탑스팟 2020년 컴퓨터일반 기출문제집 C언어 1058번

#include <stdio.h>
int a = 10;
int b = 20;
int c = 30;

void func(void) {
	static int a = 100;
	int b = 200;
	a++;
	b++;
	c = a;
	// printf("a in func : %d\n", a);
}

int main(void) {
	func();
	func();
	printf("a=%d, b=%d, c=%d\n", a, b, c);
	return 0;
}