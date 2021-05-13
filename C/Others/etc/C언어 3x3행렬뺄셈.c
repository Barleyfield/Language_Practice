/* 142694 윤이삭 문제 5번 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int arr1[3][3];		//3x3 행렬 선언
	int arr2[3][3];
	int a=0, b=0;

	printf("A 행렬 입력: \n");
	for(a=0; a<3; a++)
	{
		for(b=0; b<3; b++)
		{
			printf("%d행 %d열: ", a+1, b+1);		//A 행렬 입력
			scanf("%d", &arr1[a][b]);
		}
	}

	printf("\n");
	printf("B 행렬 입력: \n");
	for(a=0; a<3; a++)			//B 행렬 입력
	{
		for(b=0; b<3; b++)
		{
			printf("%d행 %d열: ", a+1, b+1);
			scanf("%d", &arr2[a][b]);
		}
	}

	printf("결과: \n");
	for(a=0; a<3; a++)
	{
		for(b=0; b<3; b++)
		{
			printf("%d ", arr1[a][b] - arr2[a][b]);		//arr1 - arr2 값 출력
		}
		printf("\n");		//행 바뀔 때 개행
	}
	printf("\n");
	return 0;
}
	

			
