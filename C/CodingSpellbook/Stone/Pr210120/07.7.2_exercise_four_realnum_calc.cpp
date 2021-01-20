/*
* 코딩마법서 07.7.2 연습문제
* 2개의 실수형 변수 a,b를 선언하여 a,b에 정수 데이터를 입력받아
* 덧셈, 뺄셈, 곱셈, 나눗셈, 나머지 연산을 하는 프로그램을 작성하라.
* Input Form : 1번째 줄에는 실수형 변수 a에 1개의 실수를 입력받는다.
*              2번째 줄에는 실수형 변수 b에 1개의 실수를 입력받는다.
*              입력되는 정수는 1 이상 100 이하의 양의 실수이다.
* Output Form : 1번째 줄에는 입력받은 두 실수에 대한 덧셈 연산을,
*				2번째 줄에는 뺄셈 연산을, 3번 줄에는 곱셈 연산을,
*				4번째 줄에는 나눗셈 연산을 "입력과 출력의 예"와 같은 형식으로 출력하여라.
*				출력되는 모든 실수는 소수점 셋째 자리에서 반올림하여 소수점 둘째
*				자리까지 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	double a = 0, b = 0;
	printf("두 수 입력 : \n");
	scanf("%lf", &a);
	scanf("%lf", &b);
	printf("%.2lf+%.2lf=%.2lf\n", a, b, a + b);
	printf("%.2lf-%.2lf=%.2lf\n", a, b, a - b);
	printf("%.2lf*%.2lf=%.2lf\n", a, b, a * b);
	printf("%.2lf/%.2lf=%.2lf\n", a, b, a / b);
	return 0;
}
