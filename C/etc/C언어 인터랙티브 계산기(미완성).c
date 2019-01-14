#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void mode_change(int result);
int plus(int n1, int n2);
int minus(int n1, int n2);
int multi(int n1, int n2);
int divide(int n1, int n2);

int main(void)
{
	int num1 = 0, num2 = 0, num3 = 0;
	printf("계산기입니다.\n");
	printf("가운데는 부호입니다. + - / * 을 입력하세요.\n");
	printf("입력하세요!\n");
	printf("종료: -1 -1 -1, 진수바꾸기: 0 0 0 \n");
	scanf("%d %d %d", &num1, &num2, &num3);

	while (num1 == -1 && num2 == -1 && num3 == -1)
	{

		if (num2 != 0 || num2 != -1)
		{
			switch (num2)
			{
			case '+':
				printf("%d", plus(num1, num3));
				break;
			case '-':
				printf("%d", minus(num1, num3));
				break;
			case '*':
				printf("%d", multi(num1, num3));
				break;
			case '/':
				printf("%d", divide(num1, num3));
				break;
			default:
				printf("부호를 잘못 입력하셨습니다.");
				break;
			}
		}
		else if (num1 == 0 && num2 == 0 && num3 == 0)
			mode_change(result);
	}

			



	return 0;
}

void mode_change(int result)
{
	int jinsu = 0;
	printf("진수를 입력하세요 (1: 8진수, 2: 16진수, 3: 10진수) \n ");
	scanf("%d", &jinsu);
	switch (jinsu)
	{
	case 1:
		printf("%#o \n", result);
		break;
	case 2:
		printf("%#x \n", result);
		break;
	case 3:
		printf("%d \n", result);
		break;
	default:
		printf("진수를 잘못 입력하셨습니다.\n");
		break;
	}
}

int plus(int n1, int n2)
{
	int result = n1 + n2;
	return result;
}

int minus(int n1, int n2)
{
	int result = n1 - n2;
	return result;
}

int multi(int n1, int n2)
{
	int result = n1 * n2;
	return result;
}

int divide(int n1, int n2)
{
	int result = n1 / n2;
	return result;
}

		
	
	
