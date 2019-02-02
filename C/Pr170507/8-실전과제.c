#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char str[30];
	char *ptr = str;
	int len;

	printf("문자열을 입력하세요 : ");
	gets(str);

	len = 0;
	while (ptr[len] != NULL)
	{
		len++;
		*ptr = str[len];
	}

	printf("문자열의 길이 : %d\n", len);
	return 0;
}
