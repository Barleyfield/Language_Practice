/*
* 코딩마법서 05.1 실수형 데이터 출력
*/

#include <cstdio>
int main() {
	printf("%lf\n", 123.4567);
	printf("%.2lf\n", 123.4567);
	printf("%.0lf\n", 123.4567);	// 정수 부분만 출력
	printf("%.lf\n", 123.4567);		// %.0lf와 같은 표현
	return 0;
}