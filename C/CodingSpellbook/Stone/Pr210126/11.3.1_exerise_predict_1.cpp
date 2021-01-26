/*
* 코딩마법서 연습문제 11.3.1
* 다음 프로그램을 보고 화면에 출력되는 수를 예측하여라.
*/

#include <cstdio>
int main() {
	int b = 12;
	printf("%d\n", b--);
	printf("%d\n", --b);
	printf("%d\n", ++b);
	printf("%d\n", ++b);
	printf("%d\n", b--);
	return 0;
}