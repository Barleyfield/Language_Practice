/*
* 코딩마법서 11.3.3 연습문제
* 다음 프로그램을 보고 화면에 출력되는 수를 예측하여라.
*/

#include <cstdio>
int main() {
	int d = -3;
	printf("%d\n", d--);
	printf("%d\n", d--);
	printf("%d\n", ++d);
	printf("%d\n", ++d);
	printf("%d\n", d++);
	return 0;
}