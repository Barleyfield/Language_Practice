#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int arr[10];
	int i=0;
	printf("정수 10개 입력: ");
	
	for( ; i<10; i++)
	{
		scanf("%d", &arr[i]);
	}
	i=0;

	
	printf("홀수 출력: ");
	for( ; i<10; i++)
	{
		if( arr[i] % 2 == 1)
		{
			printf("%d ", arr[i]);
		}
		
	}
	i=0;
	printf("\n");
	
	printf("짝수 출력: ");
	for( ; i<10; i++)
	{
		if( arr[i] % 2 == 0 )
		{
			printf("%d ", arr[i]);
		}
	}
	i=0;
	printf("\n");
	return 0;
	
	
}

	