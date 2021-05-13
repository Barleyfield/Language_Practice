/* 142694 윤이삭 과제 3번 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct point {
	int x;
	int y;
} POINT;

int main()
{
	int loop = 0, pointnum = 0, i = 0;	// loop : 순환,  pointnum : 점의 개수.

	printf("점의 개수를 입력하세요: ");
	scanf("%d", &pointnum);

	POINT *point = (POINT *)malloc(sizeof(POINT)*pointnum); //구조체 포인터 사용. 동적할당을 위해 malloc 사용.

	for (loop = 0; loop < pointnum; loop++)
	{
		printf("점 입력(x, y): ");
		scanf("%d %d", &point[loop].x, &point[loop].y);	//점 입력하기.

	}

	for (loop = 0; loop < pointnum; loop++)
	{
		printf("%d번째 점: [%d, %d]\n", loop + 1, point[loop].x, point[loop].y);
	}
	return 0;
}