#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int temp, i;
	printf("¼öÀÔ·Â: ");
	scanf("%d", &i);

	while (i > 0)
	{
		temp = i % 10;
		i = i / 10;
		printf("%d", temp);
	}
	printf("\n"); 
	return 0;
}

		
		
