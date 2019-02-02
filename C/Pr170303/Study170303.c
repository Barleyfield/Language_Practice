#include <stdio.h>
int main(void)
{
	double gae, a = 1, b=0, num;
	double result;

	printf("정수 몇 개 입력? : ");
	scanf_s("%lf", &gae);

	while (a <= gae)
	{
		scanf_s("%lf", &num);
		a++;
		b += num;
		
	}

	result = b / gae;
	printf("평균 : %lf \n", result);
	return 0;
}



