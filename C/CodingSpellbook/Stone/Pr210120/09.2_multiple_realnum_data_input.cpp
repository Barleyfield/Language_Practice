/*
* 코딩마법서 09.2 실수형 데이터 입력
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.2lf\n", a);
	printf("%.2lf\n", b);
	return 0;
}