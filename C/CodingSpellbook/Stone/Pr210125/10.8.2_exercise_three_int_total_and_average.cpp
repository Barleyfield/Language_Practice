/*
* 코딩마법서 10.8.2 연습문제
* 3개의 정수 A,B,C가 주어지면 주어진 세 수의 총합과 평균을 구하는 프로그램을 작성하라.
* Input Form : 1 이상 100 이하의 정수 A,B,C가 1개의 공백으로 분리되어 첫째 줄에 주어진다.
* Output Form : 첫째 줄에는 입력으로 주어진 세 정수의 총합을 출력하고,
*               둘째 줄에는 세 정수의 평균을 소수점 둘째 자리(셋쩨 자리 반올림)까지 출력하여라.
*               총합은 정수이기 때문에 반드시 정수형 서식 문자 %d를 이용해서 값을 출력하고,
*               평균은 실수이기 때문에 반드시 실수형 서식 문자 %lf를 이용하여 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int a = 0, b = 0, c = 0;
	double result = 0;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", a + b + c);
	result = (a + b + c) / 3.0;
	printf("%.2lf\n", result);
	return 0;
}