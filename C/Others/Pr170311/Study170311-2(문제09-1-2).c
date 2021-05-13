#include <stdio.h>
int CelToFah(int cel, int fah)
{
	fah = 1.8 * cel + 32;
	return fah;
}

int FahToCel(int cel, int fah)
{
	cel = (fah - 32) / 1.8;
	return cel;
}


int main(void)
{
	int cel = 0, fah = 0;
	int choice = 0;
	printf("¼·¾¾(0) or È­¾¾(1): ");
	scanf_s("%d", &choice);

	while (choice>1)
	{
		printf("0 ¾Æ´Ï¸é 1À» ÀÔ·ÂÇÏ½Ê½Ã¿À: ");
		scanf_s("%d", &choice);
	}

	switch (choice)
	{
	case 0:
		printf("¼·¾¾ ¿Âµµ ÀÔ·Â: ");
		scanf_s("%d", &cel);
		printf("È­¾¾ ¿Âµµ´Â %d \n", CelToFah(cel, fah));
		break;
	case 1:
		printf("È­¾¾ ¿Âµµ ÀÔ·Â: ");
		scanf_s("%d", &fah);
		printf("¼·¾¾ ¿Âµµ´Â %d \n", FahToCel(cel, fah));
	}
	return 0;
}
	