/* 142694 윤이삭 8장 20번 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int arr[5] = { 1,2,3,4,5 };		//배열 선언
	int *ptr = arr;					//배열 가리키는 포인터 선언
	int i = 0;
	double avg = 0;

	printf("배열 : ");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ptr[i]);		//배열 원소를 가리키는 포인터 사용
	}
	printf("\n");

	for (i = 0; i < 5; i++)
	{
		avg += *(ptr + i);
	}

	printf("배열의 평균 : %lf\n", avg/5);

	return 0;
}
	
	

