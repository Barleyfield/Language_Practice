/* 142694 윤이삭 과제 3번 */
#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAKE_RGB(A,B,C) ( ((C)*16*16*16*16) + ((B)*16*16) + (A) )	//RGB 만들기. C-B-A 순서로 있으므로 차례로 16진수 4자리, 2자리 곱함.
#define GET_RED(RGB) ( RGB % (16*16*16*16) ) % (16*16)	//RED 골라내기. 16^4로 나눈 나머지에서 다시 16^2로 나눈 나머지.
#define GET_BLUE(RGB) ( RGB / (16*16*16*16) )	//BLUE 골라내기. 16^4로 나눈 몫
#define GET_GREEN(RGB) (RGB - ( GET_BLUE(RGB)*16*16*16*16 ) - ( GET_RED(RGB) ) ) / (16*16)	//GREEN 골라내기. 위에서 골라낸 RED와 BLUE를 이용한다.

int main()
{
	int red = 0, green = 0, blue = 0;
	printf("Red를 입력하세요: ");
	scanf("%d", &red);
	printf("Green을 입력하세요: ");
	scanf("%d", &green);
	printf("Blue를 입력하세요: ");
	scanf("%d", &blue);

	int rgb = MAKE_RGB(red, green, blue);
	printf("RGB 값: %X\n", rgb);
	
	int getred = GET_RED(rgb);
	int getgreen = GET_GREEN(rgb);
	int getblue = GET_BLUE(rgb);
	printf("RGB 값 %X 중 Red: %d\n", rgb, getred);
	printf("RGB 값 %X 중 Green: %d\n", rgb, getgreen);
	printf("RGB값 %X 중 Blue: %d \n", rgb, getblue);
	
	
	return 0;
}