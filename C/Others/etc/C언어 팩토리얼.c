#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int num = 0;
	int i = 1;
	int result = 1;

	printf("자연수를 입력하세요: ");	
	scanf("%d", &num);

	while (num <= 0)
	{	
		printf("자연수를 입력하세요: ");	//음수는 입력 안 하셔도 돼요.
		scanf("%d", &num);
	}

	for (; i <= num; i++)
		result *= i;			//i가 num과 같아질 때까지 i 증가. 증가하는 동안 i를 result(초기값 1)와 계속 곱해줌.

	printf("결과: %d\n", result);
	return 0;
}



	
	