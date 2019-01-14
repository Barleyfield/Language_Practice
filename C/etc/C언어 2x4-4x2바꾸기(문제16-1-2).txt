#include <stdio.h>
int main(void)
{
	int i=0, j=0;
	int arr1[2][4]={
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};

	int arr2[4][2]={0};

	for(i=0; i<2; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d ", arr1[i][j]);
			arr2[j][i] = arr1[i][j];
		}
		printf("\n");
	}
	printf("\n\n");

	for( i=0; i<4; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}


	


	return 0;
}


		

	