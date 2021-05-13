#include <stdio.h>
int c;
int Gugudan(int a, int b)
{
	if(a<b)
	for( ; a<=b; a++)
	{
		for(c=1; c<10; c++)
		{
			printf("%d*%d=%d\n", a, c, a*c);
		}
		printf("\n");
	}
	else if (a==b)
	for( c=1; c<10; c++)
	{
		printf("%d*%d=%d \n", a, c, a*c);
	}
	else
	for( ; b<=a; b++)
	{
		for(c=1; c<10; c++)
			printf("%d*%d=%d \n", b, c, b*c);
		printf("\n");
	}
	return;
}
int main(void)
{
	int a,b;
	printf("2개 정수 입력: ");
	scanf("%d %d", &a, &b);
	Gugudan(a,b);
	return 0;
}