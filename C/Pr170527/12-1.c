/*142694 윤이삭 과제 1번 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
#define UPPER(CH) CH-32		//대문자 매크로
#define LOWER(CH) CH+32		//소문자 매크로
#define STRCPY(A) (char *)A		//문자열복사 매크로
#define STRCAT(A, B) printf(#A#B)	//문자열결합 매크로. 원리는 두 문자열을 그대로 붙여 출력.


void UpperLower(void)
{
	char str[13] = "Good Morning";	//문자열 받기.
	int i = 0;
	for (i = 0; i < 12; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')		//str[i]가 소문자면 32를 빼서 대문자 만들기(ASCII 이용)
		{
			str[i] = UPPER(str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')	//이것도 마찬가지. 32 더해 소문자 만들기.
		{
			str[i] = LOWER(str[i]);
		}
		else if (str[i] == ' ')		//공백이면 처음으로 돌아가 다음 차례의 원소에게 수행.
			continue;
	}
	printf("str : %s\n", str);
}

void StringCopy(void)
{
	char *str1 = "ABCDE";
	char *str2 = STRCPY(str1);	//(char *)를 이용해 문자열 복사.


	printf("복사된 문자열 : %s \n", str2);
}

void StringCatenate(void)
{
	printf("연결된 문자열: ");
	STRCAT(ABCDE, 12345);
	printf("\n");

}




int main()
{
	UpperLower();
	StringCopy();
	StringCatenate();
	return 0;
}





