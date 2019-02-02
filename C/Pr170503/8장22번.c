/* 142694 윤이삭 8장 22번 */
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char str[20];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);	//문자열 출력. fgets를 쓰는 이유는 sizeof(str)까지 확실하게 입력하기 위해서.
	char *ptr = str;
	int i = 0;
	char temp = 'a';
	int a = strlen(str);		//a = 문자열 길이

	for (i = 0; i < (a/2); i++)		//문자열의 절반 길이까지만 바꾸면 됨.
	{
		temp = *(ptr + a - i - 1);		//temp = 원래 끝 글자.
		*(ptr + a - i - 1) = *(ptr + i);		//끝 글자 <- 처음 글자
		*(ptr + i) = temp;		//처음 글자 <- temp
	}
	
	

	printf("뒤바뀐 문자열 : ");
	puts(str);
	printf("\n");
	return 0;
}

		
		


