#include <stdio.h>
int main(void)
{
	int num = 0, a = 1;
	int total = 1;
	printf("정수를 입력하십시오: ");
	scanf_s("%d", &num);

	while (num < 0)
	{
		printf("양의 정수만 입력하십시오: ");
		scanf_s("%d", &num);
	}


	for (; a <= num; a++)
	{
		total = total * a;
	}
	printf("결과는 %d \n", total);
	return 0;
}


