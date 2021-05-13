#include <stdio.h>

int main(void)
{
	int length = 0, i = 0;
	char word[15];
	printf("영단어 입력: ");
	scanf("%s", word);

	for (; i < 14; i++)
	{
		if (word[i] == '\0')		// 널 값이 나올 때까지 진행. 나오면 break
			break;
		length = i + 1;		//길이의 값은 i+1임. 이렇게 해야 제대로 나오던데 나도 왜 저렇게 해야되는지 잘 모르겠음. 아마 length 초기값이 0이라서 그럴까 싶음.
	}
	printf("%d\n", length);
	return 0;
}

	
