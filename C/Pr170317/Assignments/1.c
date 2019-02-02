/* 문제 1번 142694 윤이삭 */

#include <stdio.h>
#define pi 3.14		//원주율을 pi로 선언, 3.14로 정의

int main(void)
{
	double n = 6.89;			//반지름을 실수형인 n로 선언
	double result;		//마찬가지로 원의 면적을 실수형인 result로 선언

	result = pi * n * n;		//원의 넓이 구하기
	printf("원의 면적은 \n%lf \n", result);		//double형이므로 %lf 써주기
	return 0;
}

	