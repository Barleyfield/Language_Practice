/*
* 코딩마법서 11.3.2 연습문제
* 다음 프로그램을 보고 화면에 출력되는 수를 예측하여라.
*/

#include <cstdio>
int main() {
	int c = 7;
	printf("%d\n", ++c);
	printf("%d\n", c++);
	printf("%d\n", c++);
	printf("%d\n", c--);
	printf("%d\n", --c);
	return 0;
}