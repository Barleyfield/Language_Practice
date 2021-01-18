/*
* 코딩마법서 06.10.2 연습문제
* 2개의 실수형 변수 a,b에 12.34와 23.12를 선언과 동시에 초기화한 후 두 실수의 사칙 연산을 하는 프로그램을 작성하라.
* 소수점 둘째 자리까지 출력
*/

#include <cstdio>
int main() {
	double a = 12.34, b = 23.12;
	printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
	printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
	printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
	printf("%.2lf / %.2lf = %.2lf\n", a, b, a / b);
	return 0;
}