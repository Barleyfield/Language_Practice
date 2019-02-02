/* 142694 À±ÀÌ»è 9Àå ½ÇÀü°úÁ¦ */
#include <stdio.h>
#include <math.h>
#define COUNT 5
#define _CRT_SECURE_NO_WARNINGS

typedef struct rect {
	int left;		//ÁÂ»ó´ÜÁ¡ xÁÂÇ¥
	int top;		//ÁÂ»ó´ÜÁ¡ yÁÂÇ¥
	int right;		//¿ìÇÏ´ÜÁ¡ xÁÂÇ¥
	int bottom;		//¿ìÇÏ´ÜÁ¡ yÁÂÇ¥
} RECT;

int main(void)
{
	RECT rects[COUNT] = { 0 };
	int i;

	for (i = 0; i < COUNT; i++)
	{
		printf("ÁÂ»ó´ÜÁ¡/¿ìÇÏ´ÜÁ¡ÀÇ ÁÂÇ¥¸¦ ÀÔ·ÂÇÏ¼¼¿ä(left, top, right, bottom ¼ø)\n");
		scanf("%d %d %d %d", &(rects[i].left), &(rects[i].top), &(rects[i].right), &(rects[i].bottom));
	}

	for (i = 0; i < COUNT; i++)
	{
		int width = abs((rects[i].right) - (rects[i].left));
		int height = abs((rects[i].top) - (rects[i].bottom));
		printf("%d¹øÂ° Á÷»ç°¢Çü : ", i + 1);
		printf("ÁÂ»ó´ÜÁ¡ = [%d, %d] ¿ìÇÏ´ÜÁ¡ = [%d, %d] Æø = %d ³ôÀÌ = %d\n", rects[i].left, rects[i].top, rects[i].right, rects[i].bottom, width, height);
		//rects ¸â¹ö Ãâ·Â
	}
	return 0;
}




