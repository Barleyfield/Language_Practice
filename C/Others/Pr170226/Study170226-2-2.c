#include <stdio.h>
int main(void)
{
	int num1, num2, num3, result;
	

	printf("정수 3개: ");
	scanf_s("%d %d %d", &num1, &num2, &num3);

	result = (num1 - num2) * (num2 + num3) * (num3 % num1);
	printf("%d, %d, %d 연산하기: %d", num1, num2, num3, result);
	return 0;
	
}


