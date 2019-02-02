#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

typedef union dummy {
	unsigned char str[10];
	double d;
	char x;
}DUMMY;

int main(void)
{
	printf("%d\n", sizeof(DUMMY));
	return 0;
}
