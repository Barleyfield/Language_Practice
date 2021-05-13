#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void ClearBuffer(void)
{
	while (getchar() != '\n');
}

typedef struct contact {
	char name[20];
	char phoneNum[20];
} CONTACT;

int NameCompare(CONTACT *example, char *str1, int loop)
{
	int i = 0;
	
	for (i = 0; i < loop; i++)
	{
		if (strcmp(str1, example[i].name) == 0)
		{
			return 0;
			break;
		}	//이름이 같은 게 있다.
		else
			return 1;	//이름이 없다.
	}


}


void FindNumber(CONTACT *example, char *str1, int loop)
{
	int i = 0;

	for (i = 0; i < loop; i++)
	{
		if (strcmp(str1, example[i].name) == 0)
		{
			printf("찾은 전화번호: ");
			printf("%s", example[i].phoneNum);
			getchar();
			ClearBuffer();
			break;
		}	
		
	}


}



int main(void)
{
	int contactlength = 100;
	int loop = 0, i = 0, order = 0;
	CONTACT *contact = (CONTACT *)malloc(sizeof(CONTACT) * contactlength);

	for (loop = 1; loop < contactlength; loop++)
	{
		printf("검색할 이름 : ");
		scanf("%s", contact[loop].name);
		ClearBuffer();

		if (contact[loop].name[0] == '.')
			break;

		if (NameCompare(contact, contact[loop].name, loop) == 0)
		{
			FindNumber(contact, contact[loop].name, loop);
		}
		else
		{
			printf("전화번호 입력 : ");
			scanf("%s", contact[loop].phoneNum);
			ClearBuffer();
			order++;
		}

	}

	for (loop = 0; loop < order; loop++)
	{
		printf("이름 : ");
		printf("%s", contact[loop].name);
		printf("\n");

		printf("전화번호 : ");
		printf("%s", contact[loop].phoneNum);
		printf("\n\n");



	}

	return 0;
}


	
