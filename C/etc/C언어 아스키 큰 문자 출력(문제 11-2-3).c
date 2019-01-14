#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char str[50];
	char max=0;
	int i=0;
	int len=0;
	printf("문자 입력: ");
	scanf("%s", str);



	while(str[len] != '\0')		//영단어 길이 계산
		len++;

	for( ; i<len; i++)
	{
		if( max < str[i])
			max = str[i];
	}

	printf("아스키코드 큰 값: %c \n", max);
	
	
	return 0;
}
