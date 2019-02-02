/* 142694 윤이삭 8장 18번 */
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char str[10] = "abcdefg";	//문자열 선언
	char str2[10] = "a";
	int i = 0;
	char *ptr = str;		//문자열 str을 가리키는 포인터 ptr 선언

	while (ptr[i] != NULL)		//ptr[i]가 NULL이 될 때까지..
	{
		str2[i] = ptr[i];	//str2에 ptr의 글자를 한 글자씩 복사.
		i++;
	}

	printf("%s", str2);		//마지막으로 출력.
	printf("\n");
	return 0;
}