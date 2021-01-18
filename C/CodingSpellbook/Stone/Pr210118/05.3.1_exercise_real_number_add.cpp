/*
* 코딩마법서 05.3.1 연습문제
* printf()문 6개를 각 줄에 사용하여 실수의 덧셈 과정 출력
*/

#include <cstdio>
int main() {
	printf("%10.3lf\n", 12.345);
	printf("%10.3f\n", 34.567);
	printf("%10.3f\n", 56.789);
	printf("%10.3f\n", 456.780);
	printf("----------\n");
	printf("%10.3lf\n", 560.481);
	return 0;
}