#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void ClearBuffer()
{
	while (getchar() != '\n');
}

typedef struct font {
	char faceName[40];
	unsigned int size;
	int weight;
} FONT;

int CompareByFaceName(const void *e1, const void *e2)
{
	const FONT *fnt1 = (const FONT *)e1;
	const FONT *fnt2 = (const FONT *)e2;
	return strcmp(fnt1->faceName, fnt2->faceName);
}

int FindName(const void *e1, const void *e2)
{
	const char *fnt1 = (const char *)e1;
	const FONT *fnt2 = (const FONT *)e2;
	return strcmp(fnt1, fnt2->faceName);
}
	

int main()
{
	FONT font[5] = {
		{"궁서체", 11, 1},
		{"돋움체", 12, 2},
		{"나눔체", 13, 3},
		{"굴림체", 14, 4},
		{"바탕체", 15, 5}
	};
	FONT *find;

	char key[10];
	char yesno = 'a';

	qsort(font, 5, sizeof(FONT), CompareByFaceName);


	while (1)
	{
		printf("검색할 폰트명 : ");
		scanf("%s", key);
	


		find = (FONT *)bsearch(&key, font, 5, sizeof(FONT), FindName);

		if (find != NULL)
		{
			printf("폰트명: %s\n", find->faceName);
			printf("폰트 크기: %u\n", find->size);
			printf("폰트 두께: %d\n", find->weight);
		}
		ClearBuffer();
		printf("계속 하시겠습니까? (y/n): ");
		scanf("%c", &yesno);
		if (yesno == 'n')
			break;
		else
			continue;
	}
	return 0;
}

		



