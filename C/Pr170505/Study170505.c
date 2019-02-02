#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct point
{
	int xpos;
	int ypos;
} Point;

typedef struct rectangle
{
	Point coor1, coor2;

} Rectangle;

void area(Rectangle num)
{
	int x_length, y_length;
	x_length = abs(num.coor2.xpos - num.coor1.xpos);
	y_length = abs(num.coor2.ypos - num.coor1.ypos);
	printf("직사각형의 넓이: %d \n", x_length * y_length);
}

void ShowRectangle(Rectangle num)
{
	printf("좌 하단 : [%d, %d] \n", num.coor1.xpos, num.coor1.ypos);
	printf("좌 상단 : [%d, %d] \n", num.coor1.xpos, num.coor2.ypos);
	printf("우 하단 : [%d, %d] \n", num.coor2.xpos, num.coor1.ypos);
	printf("우 상단 : [%d, %d] \n", num.coor2.xpos, num.coor2.ypos);
}


int main(void)
{
	Rectangle rec1 = { {1,1}, {4,5} };
	Rectangle rec2 = { {3,4}, {5,6} };
	ShowRectangle(rec1);
	area(rec1);
	ShowRectangle(rec2);
	area(rec2);
	return 0;
}







