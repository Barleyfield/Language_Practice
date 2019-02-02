#include <stdio.h>
int main(void)
{
	int a = 0, b = 0, c = 0;
	int result = (a + b + c) / 3;


	printf("국어, 영어, 수학 점수 입력: ");
	scanf_s("%d %d %d", &a, &b, &c);

	int grade = (result >= 90) ? (A) / (B);
	return 0;
}
	

	