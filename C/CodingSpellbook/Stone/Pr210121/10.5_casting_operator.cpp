/*
* 코딩마법서 10.5 형 변환 연산자
*/

#include <cstdio>
int main() {
	int a = 10, b = 3;
	double c = 0, d = 0, e = 0, f = 0;

	c = a / b;			// int를 int로 나누었기 때문에 결과도 int로 나온다. c는 double이니 3.00으로 저장된다.
	d = (double)a / b;	// a의 값을 실수형으로 변환해서 연산
	e = double(a) / b; // 얘도 마찬가지.
	f = a / 3.0;

	printf("c = %.2lf\n", c);
	printf("d = %.2lf\n", d);
	printf("e = %.2lf\n", e);
	printf("f = %.2lf\n", f);
	return 0;
}