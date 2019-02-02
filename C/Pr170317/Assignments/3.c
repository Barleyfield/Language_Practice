/* 문제 3번 142694 윤이삭 */
#include <stdio.h>
#define us 1120		// us에 숫자 1120 선언

int main(void)
{
	double n = 0;		// 한화 선언. int형으로 선언 시 결과값에서 소수점이 출력이 되지 않아 double로 선언했습니다.
	printf("환전할 값을 입력하세요: ");
	scanf_s("%lf", &n);		//double형이므로 %lf 써주기
	double result = n / us;		//결과값 선언
	printf("%lf 원 -> %lf 달러 \n", n, result);
	return 0;
}
