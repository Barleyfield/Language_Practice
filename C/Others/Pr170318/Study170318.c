/* 문제 11-1-1 */
#include <stdio.h>

int main(void)
{
	int i, max = 0, min=0;		//최댓값, 최솟값 변수 선언
	int arr[5];
	printf("5개 정수 입력: ");
	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	i = 0;
	max = arr[0];
	min = arr[0];

	for (i = 0; i < 4; i++)			// 최댓값 arr[i+1]과 비교. arr[i+1]이 더 크면 그게 최댓값으로, 아니면 그대로. 이걸 for문으로 반복.
	{
		if (max <= arr[i + 1])
		{
			max = arr[i + 1];
		}
		
	}

	for (i = 0; i < 4; i++)		//최솟값도 마찬가지. arr[i+1]이 더 작으면 그게 최솟값.
	{
		if (min > arr[i + 1])
		{
			min = arr[i + 1];
		}
	}

	printf("최댓값 : %d \n", max);
	printf("최솟값 : %d \n", min);
	printf("합계 : %d \n", arr[0] + arr[1] + arr[2] + arr[3] + arr[4]);		//합계는 그냥 더함.
	return 0;
}

