#include <stdio.h>
int main()
{
	int i = 0, j = 0;
	int input = 0;

	printf("단을 입력하세요 : ");
	scanf("%d", &input);

	for (j = 1; j <= 9; j++)
	{
		for (i = 1; i <= input; i++)
		{
			if (i != 1 && (i*j) < 10)		// 간격 맞추기용 if문
			{
				printf("%d * %d = %d  ", i, j, i*j);
			}
			else
				printf("%d * %d = %d ", i, j, i*j);
			
		}
		printf("\n");
	}

	return 0;
}