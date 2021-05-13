/* 142694 윤이삭 문제 19번 */
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	char str1[20] = "a";
	char str2[20] = "a";
	int i = 0, check = 0;
	char *ptr1 = str1;
	char *ptr2 = str2;
	printf("첫 번째 문자열을 입력하세요: ");
	gets(str1);
	printf("두 번째 문자열을 입력하세요: ");
	gets(str2);

	while (str1[i] != NULL)		//문자열 비교. str1이 NULL, 즉 마지막 글자까지 비교.
	{
		if (str1[i] == str2[i] || (str1[i] + ('a' - 'A')) == str2[i] || (str1[i] - ('a' - 'A')) == str2[i])		//대소문자 구분하지 않고 동일하게 판별.
		{
			check++;	//문자가 같으면 check 1 증가.
		}
		i++;
	}

	if (check == strlen(str1))	//check가 str1의 문자열 길이와 같다면 OK 메시지 출력.
	{
		printf("%s와(과) %s는(은) 같습니다.\n", str1, str2);	
	}
	else
	{
		printf("%s와(과) %s는(은) 다릅니다.\n", str1, str2);	//다르면 NO라고 출력.
	}
	return 0;
}

	
	



