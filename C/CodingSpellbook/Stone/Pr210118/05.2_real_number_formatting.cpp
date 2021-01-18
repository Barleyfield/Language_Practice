/*
* 코딩마법서 05.2 실수형 포맷팅
*/

#include <cstdio>
int main() {
	printf("12345678901234\n");
	printf("ABC%8.2lfDEF\n", 123.4567);
	printf("ABC%-8.2lfDEF\n", 123.4567);
	printf("ABC%3.2lfDEF\n", 123.4567);
	return 0;
}