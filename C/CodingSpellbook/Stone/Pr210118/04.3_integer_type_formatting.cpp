/*
* 코딩마법서 04.3 정수형 포맷팅
*/
#include <cstdio>
int main() {
	printf("123 ");
	printf(" 678\n");
	printf("12345678901234\n");
	printf("ABC%8dDEF\n", 123);
	printf("ABC%-8dDEF\n", 123);
	printf("ABC%2dDEF\n", 123);
	return 0;
}