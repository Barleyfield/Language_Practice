#include <stdio.h>
int main(void)
{
	int arr[3][9]={0};
	int i=2, j;

	for( ; i<5; i++)
	{
		for(j=1; j<10; j++)
		{
			arr[i-2][j-1] = i*j;
		}
	}

	

	for( i=2; i<5; i++)
	{
		for(j=1; j<10; j++)
		{
			printf("%d ", arr[i-2][j-1]);
		}
		printf("\n");
	}

	return 0;
}


