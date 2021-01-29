#pragma warning(disable:4996)
#include <cstdio>
int main() {
	// 첫날 = 0000, 둘째 날 = 0001과 같이 짝수-홀수 번갈아 돌린다.
	// 따라서 자물쇠 1은 홀수로, 자물쇠 2는 짝수로 채우면 된다.
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a % 2 == 0 || b % 2 == 1) {
		printf("1");
	}
	else {
		printf("0");
	}
	return 0;
}