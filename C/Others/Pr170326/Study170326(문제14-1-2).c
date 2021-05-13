#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void Swap3(int *ptr1, int *ptr2, int *ptr3)
{
	int temp = *ptr1;
	*ptr1 = *ptr3;
	*ptr3 = *ptr2;
	*ptr2 = temp;


	printf("%d %d %d", *ptr1, *ptr2, *ptr3);

}

int main(void)
{
	int num1, num2, num3;
	printf("수 3개 입력: ");
	scanf("%d %d %d", &num1, &num2, &num3);
	Swap3(&num1, &num2, &num3);
	return 0;
}

