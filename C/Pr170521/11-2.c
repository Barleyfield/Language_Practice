#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct font {
	char faceName[40]; // 폰트명
	unsigned int size; // 폰트 크기
	int weight; // 폰트 두께
} FONT;

int CompareByFaceName(const void* e1, const void* e2)
{
	const FONT *fnt1 = (const FONT *)e1;
	const FONT *fnt2 = (const FONT *)e2;
	return strcmp(fnt1->faceName, fnt2->faceName);
}

int main(void)
{
	FONT *font1[20];
	FONT *found;
	char *str[20];
	int i = 0, j = 0;

	for (i = 0; i < 20; i++)
	{
		printf("검색할 폰트명: ");
		gets(str);


		for (j = 0; j <= i; j++)
		{
			if (strcmp(str, font1[j]->faceName) == 0)
			{
				found = (FONT *)bsearch(font1[j]->faceName, font1, i, sizeof(FONT), CompareByFaceName);
				printf("폰트명 : %s \n", found->faceName);
				printf("폰트크기 : %u \n", found->size);
				printf("폰트두께 : %d \n", found->weight);
				break;
			}
			else
			{
				printf("폰트크기를 입력하세요: ");
				scanf("%u",(unsigned int *)font1[i]->size);
				printf("폰트두께를 입력하세요: ");
				scanf("%d",(int *)font1[i]->weight);
				break;
			}
		}

		qsort(font1, i, sizeof(FONT), CompareByFaceName);
	}

	return 0;
}
			






		
	