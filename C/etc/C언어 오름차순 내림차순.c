#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void ascend(void);		//오름차순 함수
void descend(void);		//내림차순 함수


int main(void)
{
	int menu = 0;
	printf("1. 오름차순 2. 내림차순 \n");		//고르기
	printf("선택: ");
	scanf("%d", &menu);

	switch(menu)
	{
	case 1:
		ascend();
		break;
	case 2:
		descend();
		break;
	default:
		printf("ㄲㅈ");
		break;			//1,2 외 다른 거 입력하면 ㄲㅈ
	}



	printf("\n");
	return 0;
}

void ascend(void)
{
	int arr[10]={0};
	int a=0, b=0, temp=0;


		for(a=0; a<10; a++)
		{
			printf("%d번째 값 입력: ", a+1);
			scanf("%d", &arr[a]);
		}
	
		printf("\n");

		for(a=0; a<9; a++)			// arr[b]와 arr[b+1] 비교하기, 큰 값을 arr[b+1], 즉 오른쪽으로 보냄.
		{					// a<9인 이유는 수가 10개라 9번 바꿔주기 때문
			for( b=0; a+b<9; b++)		//처음에 9번 바꾸면 arr[9]엔 자동으로 최댓값 됨 -> arr[8]값 구하기.
			{
				if( arr[b] >= arr[b+1] )	//이런 식으로 계속 arr[0]까지 구함.
				{
					temp = arr[b];
					arr[b] = arr[b+1];
					arr[b+1] = temp;
				}
			}
		}

		for(a=0; a<10; a++)
		{
			printf("%d ", arr[a]);
		}
		
}

void descend(void)
{
	int arr[10]={0};
	int a=0, b=0, temp=0;


		for(a=0; a<10; a++)
		{
			printf("%d번째 값 입력: ", a+1);
			scanf("%d", &arr[a]);
		}
	
		printf("\n");
		
		for(a=0; a<9; a++)
		{
			for(b=0; a+b<9; b++)
			{
				if( arr[b] <= arr[b+1] )	//내림차순도 오름차순이랑 같음. 차이는 최솟값을 저장한다는 것.
				{
					temp = arr[b];
					arr[b] = arr[b+1];
					arr[b+1] = temp;
				}
			}
		}

		for(a=0; a<9; a++)
		{
			printf("%d ", arr[a]);
		}
		printf("%d", arr[9]);		//요거 입력 안해주면 수가 9개만 나오는 데 왜 그런지 모르겠음 ㅠ
}