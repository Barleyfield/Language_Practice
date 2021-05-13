#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void BinaryChange(int num);

int main(void)
{
	int n=0;
	printf("10진수 정수 입력: ");
	scanf("%d", &n);
	printf("\n");
	BinaryChange(n);
	printf("\n");
	return 0;

}

void BinaryChange(int num)
{
	int i = 0;
	int a = 0;
	int arr[100];


	while(num<0)			//0 이하의 정수가 입력되면 다시 입력하도록.
	{
		printf("0 이상의 정수를 입력하십시오: ");
		scanf("%d", &num);
	}
	if( num == 0)			//num이 0일때 0 출력
		printf("0\n");
	else if ( num == 1)		//num이 1일때 1 출력. 2 이상부터는 제대로 되는데 0,1만 쓰레기 값이 나와서 미리 정해줌
		printf("1\n");
	else
	{
		for( ; num>=1; i++)
		{
			arr[i] = (num % 2);			//num을 2로 나눈 나머지를 배열에 저장
			num = num / 2;				//그 다음 num을 2로 나눔
			if( num == 1)				//num이 1이 되면 arr[i+1], 즉 배열의 마지막에 1 저장.
			{
				arr[i+1] = 1;
				break;
			}

		}
		a = i;

		printf("%d", arr[a+1]);			//배열의 맨 마지막 항부터 출력, 이거 안해주면 앞에 수 잘리는데 왜 잘리는지는 모르겠음.
		for( ; a>=0; a--)
		{
			printf("%d", arr[a]);		//arr[a] ~ arr[0]까지 출력
		}
	}
}

	

	