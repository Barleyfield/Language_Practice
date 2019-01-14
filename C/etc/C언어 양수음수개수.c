/* 142694 윤이삭 문제 1번 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS	

int main(void)
{
	int arr[10]={0};
	int i=0, pos=0, neg=0, zero=0;

	printf("10개의 정수를 입력하세요: ");
	for(i=0; i<10; i++)		//10개의 정수 입력
	{
		scanf("%d", &arr[i]);
	}
	printf("\n");

	printf("입력된 배열: ");
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);		//배열 출력
		if( arr[i] > 0 )		
		{
			pos += 1;				//정수>0이면 pos 1씩 증가
		}
		else if ( arr[i] < 0 )
		{
			neg += 1;				//정수<0이면 neg 1씩 증가
		}
		else
			zero += 1;				//정수=0이면 zero 1씩 증가
	}

	printf("\n");
	printf("양수: %d개, 음수: %d개, 0: %d개", pos, neg, zero);		//증가된 pos, neg, zero값을 출력
	return 0;
}



	