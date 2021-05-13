/* 142694 윤이삭 8장 23번 */
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char str[20];
	printf("문자열 입력: ");
	gets(str);
	char *ptr = str;
	int i = 0, num = 0;

	while (*(ptr+i) != NULL)
	{
		if ( ptr[i] == ' ' || ptr[i] == '\t' || ptr[i] == '\v' || ptr[i] == '\f' || ptr[i] == '\n' || ptr[i] == '\r')	//공백인지 확인
		{
			num++;		//공백이면 num을 1씩 증가.
		}
		i++;
	}

	printf("공백의 개수 : %d개", num);	//num의 값이 공백의 개수.
	printf("\n");
	return 0;
}


	

	