#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	FILE *fp = fopen("test.txt", "rt");
	int i = 0;
	int A, P;
	char str[100];

	if (fp == NULL)
	{
		printf("파일 오픈 실패!\n");
		return -1;
	}


	for (i = 0, A = 0, P = 0; fscanf(fp, "%s", str) != EOF; i++)
	{
		if (str[0] == 'A')
			A++;
		else if (str[0] == 'P')
			P++;
	}

	printf("A의 개수: %d\n", A);
	printf("P의 개수: %d\n", P);
	return 0;
}


	