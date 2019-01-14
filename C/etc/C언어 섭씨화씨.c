#include <stdio.h>

int CtoF(int c)
{
	int f=0;
	scanf_s("%d", &c);

	f = (c * 1.8) + 32;
	return f;
}
	

int main(void)
{
	int c=0;
	printf("섭씨 입력: ");
	printf("화씨: %d", CtoF(c));
	return 0;
}
