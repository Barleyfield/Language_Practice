/*
* 코딩마법서 10.3 누적시키기
*/

#include <cstdio>
int main() {
	int s = 10;
	
	s += 5;
	printf("%d\n", s);

	s *= 5;
	printf("%d\n", s);

	s -= 5;
	printf("%d\n", s);
	
	s /= 5;
	printf("%d\n", s);

	s %= 5;
	printf("%d\n", s);
	return 0;
}