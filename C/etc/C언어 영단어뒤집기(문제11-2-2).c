#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{

	char str[50];
	int i=0, a=0;
	printf("영단어 입력: ");
	scanf("%s", str);
	

	printf("원래 단어: ");
	while(str[i] != '\0')		// str[i]가 널 문자가 나올 때까지 멈추기.
	{
		printf("%c", str[i]);
		i++;
		a = i;		
	}
	printf("\n거꾸로: ");
	

	while(str[a+1]!=str[0])		// str[0] 즉 첫번째 문자가 될 때까지 멈추기. 나도 왜 [a+1]로 해야 전부 출력되는지 모르겠음.
	{
		printf("%c", str[a]);
		a--;
		
	}
	



	printf("\n");
	return 0;
}
