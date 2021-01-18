/*
* 코딩마법서 06.10.1 연습문제
* 2개의 정수형 변수 a,b에 54와 32를 선언함과 동시에 초기화한 후
* 두 정수의 사칙 연산을 하는 프로그램
*/

#include <cstdio>
int main() {
	int a = 54, b = 32, i=0;
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);
	
	return 0;
}