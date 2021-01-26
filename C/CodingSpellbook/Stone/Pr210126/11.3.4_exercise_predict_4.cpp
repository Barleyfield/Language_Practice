/*
* 코딩마법서 11.3.4 연습문제
* 다음 프로그램을 보고 화면에 출력되는 수를 예측하여라.
*/

#include <cstdio>

int main() {
	int e = 7;
	printf("%d\n", --e);
	printf("%d\n", e--);
	printf("%d\n", e++);
	printf("%d\n", ++e);
	e++;
	printf("%d\n", e);
	return 0;
}
