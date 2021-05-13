#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int arr[4][4] = { 0 };
	int arr2[4][4] = { 0 };
	int arr3[4][4] = { 0 };
	int arr4[4][4] = { 0 };
	int a = 0, b = 0, n = 1;
	int temp = 0;

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			arr[a][b] = n;
			n++;
		}
	}

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			printf("%2d ", arr[a][b]);
		}
		printf("\n");
	}
	printf("\n");
	

	
	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			arr2[b][3 - a] = arr[a][b];
		}
	}

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			printf("%2d ", arr2[a][b]);
		}
		printf("\n");
	}
	printf("\n");

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			arr3[b][3 - a] = arr2[a][b];
		}
	}

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			printf("%2d ", arr3[a][b]);
		}
		printf("\n");
	}
	printf("\n");

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			arr4[b][3 - a] = arr3[a][b];
		}
	}

	for (a = 0; a < 4; a++)
	{
		for (b = 0; b < 4; b++)
		{
			printf("%2d ", arr4[a][b]);
		}
		printf("\n");
	}
	printf("\n");


		
		


	return 0;
}



	


