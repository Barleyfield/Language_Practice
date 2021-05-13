/* 142694 윤이삭 과제 2번 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#define ALGORITHM 1		//알고리즘 선언
	
typedef struct fruit {
	char fruit[20];		//과일 구조체 선언 (퀵 정렬 방법)
} FRUIT;

#if ALGORITHM == 2		//퀵 정렬 방법

typedef struct fruit {
	char fruit[20];		//fruit원소가 있는 구조체 선언.
} FRUIT;

int CompareName(const char *e1, const char *e2)		//구조체 이름 비교용 함수
{
	FRUIT *frt1 = (FRUIT *)e1;
	FRUIT *frt2 = (FRUIT *)e2;
	return strcmp(frt1->fruit, frt2->fruit);	//오름차순
}

int main()
{
	FRUIT fruitbox[5] = {
		{"watermelon"},
		{"strawberry"},
		{"kiwi"},
		{"mango"},
		{"banana"},
	};

	int i = 0;

	printf("정렬 전 문자열: ");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", fruitbox[i].fruit);
	}



	qsort(fruitbox, 5, sizeof(FRUIT), CompareName);		//qsort로 정렬해주기
	printf("\n");
	printf("정렬 후 문자열: ");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", fruitbox[i].fruit);
	}
	printf("\n");
	return 0;
}

#elif ALGORITHM == 1		//선택 정렬 방법
int main()
{
	char *str[5] = { "watermelon", "strawberry", "kiwi", "mango", "banana" };
	int i, j;
	int index;
	char *tmp;
	char *max;

	printf("변경 전 문자열: ");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", str[i]);
	}
	printf("\n");


	for (i = 0; i < 5; i++)
	{
		index = i;
		max = str[i];
		for (j = i + 1; j < 5; j++)		//str[i+1]부터 max와 비교.
		{
			if (strcmp(max, str[j]) > 0)	//만약 max가 str[j]보다 사전순 뒤에 있다면...
			{
				max = str[j];	//max가 str[j]가 된다.
				index = j;		//index도 j가 된다.
			}
		}
		tmp = str[i];	//이제 배열순서를 바꾼다.(tmp이용 맞교환형식)
		str[i] = str[index];
		str[index] = tmp;
	}

	printf("변경 후 문자열: ");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", str[i]);
	}
	printf("\n");
	return 0;
}


#endif
	



