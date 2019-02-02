#include <stdio.h>

int Add(int num1, int num2)
{
	return num1 + num2;
}

void ShowAddResult(int num)
{
	printf("µ¡¼À°á°ú Ãâ·Â: %d \n", num);
}
int ReadNum(void)
{
	int num;
	scanf_s("%d", &num);
	return num;
}

void HowToUseThisProg(void)
{
	printf("2°³ ÀÔ·ÂÇÏ¸é\n");
	printf("µ¡¼À°á°ú Ãâ·Â: ");
}

int main(void)
{
	int result, num1, num2;
	HowToUseThisProg();
	num1 = ReadNum();
	num2 = ReadNum();
	result = Add(num1, num2);
	ShowAddResult(result);
	return 0;
}
