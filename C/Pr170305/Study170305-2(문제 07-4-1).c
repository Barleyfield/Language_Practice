#include <stdio.h>
int main(void)
{
	int num1 = 0, num2 = 0;
	int total = 0;

	printf("정수 1 입력: ");
	scanf_s("%d", &num1);
	printf("정수 2 입력: ");
	scanf_s("%d", &num2);

	for (; num1 <= num2; num1++)
	{
		total = total + num1;
	}
	printf("정수 1부터 정수 2까지의 합 : %d \n", total);
	return 0;
}


		