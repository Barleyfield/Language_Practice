#include <stdio.h>
int Big(int num1, int num2, int num3);
int Small(int num1, int num2, int num3);



int main(void)
{
	int num1, num2, num3;
	printf("3개의 정수를 입력하세요: ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	printf("큰 수는 %d \n", Big(num1, num2, num3));
	printf("작은 수는 %d \n", Small(num1, num2, num3));
	
	return 0;

}

int Big(int num1, int num2, int num3)
{
	if (num1 > num2)
		return (num1 > num3) ? num1 : num3;
	else
		return (num2 > num3) ? num2 : num3;

}

int Small(int num1, int num2, int num3)
{
	if (num1 < num2)
		return (num1 < num3) ? num1 : num3;
	else
		return (num2 < num3) ? num2 : num3;

}

