/* 142694 윤이삭 8장 21번 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNING

int main(void)
{
	int arr[10] = { 15,23,7,78,34,67,45,36,90,71 };
	int *ptr = arr;
	int i = 0;
	int value = 0;

	printf("원본 배열: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(ptr + i));		//원본 배열 출력
	}

	printf("\n");
	printf("증가량을 입력하세요: ");
	scanf("%d", &value);
	printf("증가 후 배열: ");

	for (i = 0; i < 10; i++)
	{	
		printf("%d ", ptr[i] + value);		//증가량 배열 출력. ptr[i]로 해도 *(ptr+i)와 동일한 효과.
	}
	printf("\n");

	return 0;
}
