#include <stdio.h>
int main(void)
{
	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	int *ptr1 = &arr[0];
	int *ptr2 = &arr[5];
	int i = 6;

	for (; i >= *ptr1; i--)
	{
		printf("%d \n", *(ptr2--));
	}
	return 0;
}


	