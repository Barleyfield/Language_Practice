#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct point {
	int x;
	int y;
} POINT;

void ClearBuffer()
{
	while (getchar() != '\n');
}

int main()
{
	int num = 0;
	int i = 0;
	printf("점은 몇 개? : ");
	scanf("%d", &num);

	POINT *point = (POINT *)malloc(sizeof(POINT) * num);

	for (i = 0; i < num; i++)
	{
		printf("%d번째 점 입력(x,y): ", i + 1);
		scanf("%d %d", &point[i].x, &point[i].y);
	}

	for (i = 0; i < num; i++)
	{
		printf("%d번째 점: [%d, %d]\n", i + 1, point[i].x, point[i].y);
	}

	free(point);
	return 0;
}
	

